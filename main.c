#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUMNOS 100
#define MAX_NOMBRE 50
#define MAX_MATERIAS 10

typedef struct
{
    char nombre[MAX_NOMBRE];
    int dni;
    float notas[MAX_MATERIAS];
    int cantidadNotas;
} Alumno;

void cargarAlumno(Alumno *alumno)
{
    printf("Nombre: ");
    fgets(alumno->nombre, MAX_NOMBRE, stdin);
    alumno->nombre[strcspn(alumno->nombre, "\n")] = 0;

    printf("DNI: ");
    scanf("%d", &alumno->dni);

    printf("Cantidad de notas: ");
    scanf("%d", &alumno->cantidadNotas);

    for (int i = 0; i < alumno->cantidadNotas; i++)
    {
        printf("Nota %d: ", i + 1);
        scanf("%f", &alumno->notas[i]);
    }
    getchar(); // limpiar buffer
}

float calcularPromedio(Alumno a)
{
    float suma = 0;
    for (int i = 0; i < a.cantidadNotas; i++)
    {
        suma += a.notas[i];
    }
    return a.cantidadNotas > 0 ? suma / a.cantidadNotas : 0;
}

void buscarAlumno(Alumno alumnos[], int cantidad)
{
    char nombre[MAX_NOMBRE];
    int dni;
    int opcion;

    printf("Buscar por: 1) Nombre 2) DNI: ");
    scanf("%d", &opcion);
    getchar();

    if (opcion == 1)
    {
        printf("Nombre a buscar: ");
        fgets(nombre, MAX_NOMBRE, stdin);
        nombre[strcspn(nombre, "\n")] = 0;

        for (int i = 0; i < cantidad; i++)
        {
            if (strcmp(alumnos[i].nombre, nombre) == 0)
            {
                printf("DNI: %d, Promedio: %.2f\n", alumnos[i].dni, calcularPromedio(alumnos[i]));
            }
        }
    }
    else
    {
        printf("DNI a buscar: ");
        scanf("%d", &dni);
        for (int i = 0; i < cantidad; i++)
        {
            if (alumnos[i].dni == dni)
            {
                printf("Nombre: %s, Promedio: %.2f\n", alumnos[i].nombre, calcularPromedio(alumnos[i]));
            }
        }
    }
}

void guardarArchivo(Alumno alumnos[], int cantidad, const char *archivo)
{
    FILE *f = fopen(archivo, "wb");
    if (f != NULL)
    {
        fwrite(&cantidad, sizeof(int), 1, f);
        fwrite(alumnos, sizeof(Alumno), cantidad, f);
        fclose(f);
    }
}

int leerArchivo(Alumno alumnos[], const char *archivo)
{
    FILE *f = fopen(archivo, "rb");
    int cantidad = 0;
    if (f != NULL)
    {
        fread(&cantidad, sizeof(int), 1, f);
        fread(alumnos, sizeof(Alumno), cantidad, f);
        fclose(f);
    }
    return cantidad;
}

int compararPromedio(const void *a, const void *b)
{
    float pa = calcularPromedio(*(Alumno *)a);
    float pb = calcularPromedio(*(Alumno *)b);
    return (pb > pa) - (pb < pa); // orden descendente
}

void mostrarMejoresPromedios(Alumno alumnos[], int cantidad)
{
    qsort(alumnos, cantidad, sizeof(Alumno), compararPromedio);
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s (DNI: %d) -> Promedio: %.2f\n", alumnos[i].nombre, alumnos[i].dni, calcularPromedio(alumnos[i]));
    }
}

int main(int argc, char const *argv[])
{
    Alumno alumnos[MAX_ALUMNOS];
    int cantidad = 0;
    int opcion;
    const char *archivo = "alumnos.dat";

    cantidad = leerArchivo(alumnos, archivo);

    do
    {
        printf("\n1. Cargar alumno\n2. Buscar alumno\n3. Mostrar mejores promedios\n4. Guardar y salir\nOpción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
        case 1:
            if (cantidad < MAX_ALUMNOS)
            {
                cargarAlumno(&alumnos[cantidad++]);
            }
            break;
        case 2:
            buscarAlumno(alumnos, cantidad);
            break;
        case 3:
            mostrarMejoresPromedios(alumnos, cantidad);
            break;
        case 4:
            guardarArchivo(alumnos, cantidad, archivo);
            break;
        }
    } while (opcion != 4);
    return 0;
}
