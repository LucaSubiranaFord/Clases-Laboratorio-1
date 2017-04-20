#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 3


typedef struct
{
    int legajo;
    int edad;
    char nombre[20];
    float promedio;
    char sexo;
} eAlumno;

void mostrarAlumno(eAlumno);

int main()
{
    eAlumno misAlumnos[A];
    int i;

    for(i=0; i<A; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &misAlumnos[i].legajo);
        printf("Ingrese edad: ");
        scanf("%d", &misAlumnos[i].edad);
        printf("Ingrese promedio: ");
        scanf("%f", &misAlumnos[i].promedio);
        printf("Ingrese sexo: ");
        misAlumnos[i].sexo=getche();
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(misAlumnos[i].nombre);
    }



 for(i=0; i<A; i++)
 {
     mostrarAlumno(misAlumnos[i]);
 }









    return 0;
}

void mostrarAlumno(eAlumno alu)
{
    printf("%d--%d--%s--%f--%c\n", alu.legajo, alu.edad, alu.nombre, alu.promedio, alu.sexo);
}

