#include <stdio.h>
#include <stdlib.h>
#define TAM 3
typedef struct{

char nombre[30];
int edad;

}ePersona;

int main()
{
    int i;
    ePersona* auxPersona;
    ePersona* listaPersonas[TAM];

    for(i=0;i<TAM;i++)
    {
        auxPersona = (ePersona*) malloc(sizeof(ePersona));
        listaPersonas[i] = auxPersona;

        printf("Ingrese un nombre: \n");
        fflush(stdin);
        gets(listaPersonas[i]->nombre);

        printf("Ingrese la edad: \n");
        scanf("%d",&(listaPersonas[i]->edad));
    }

    for(i=0;i<TAM;i++)
    {
        printf("%s, %d\t",listaPersonas[i]->nombre,listaPersonas[i]->edad);
    }



    return 0;
}
