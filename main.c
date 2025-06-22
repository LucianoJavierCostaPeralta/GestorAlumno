#include <stdio.h>
#include <string.h> // Agrega esta línea

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

int main(int argc, char const *argv[])
{
    printf("Bienvenido al sistema de gestion de alumnos.\n");
    return 0;
}
