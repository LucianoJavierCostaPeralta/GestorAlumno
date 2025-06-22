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

int main(int argc, char const *argv[])
{
    printf("Bienvenido al sistema de gestion de alumnos.\n");
    return 0;
}
