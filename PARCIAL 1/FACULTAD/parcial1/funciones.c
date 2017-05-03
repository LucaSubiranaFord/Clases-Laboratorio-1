#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void agregarPersona(eAbonado abonado[],int espacioLibre,int tam)
{
    int auxNum;
    int auxId;
    int buffer[200];
    int i;

    printf("Nombre de la persona: \n");
    fflush(stdin);
    gets(buffer);

    while(buffer>49)
    {
        printf("El nombre debe contener menos de 50 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(abonado[espacioLibre].nombre, buffer);


    printf("Apellido de la persona: \n");
    fflush(stdin);
    gets(buffer);

    while(buffer>49)
    {
        printf("El Apellido debe contener menos de 50 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(abonado[espacioLibre].apellido, buffer);

    printf("ID del abonado: \n");
    scanf("%d", &auxId);

    for(i=0;i<tam;i++)
    {
        if(abonado[i].estado == 1){
        if(auxId == abonado[i].id)
        {
            printf("Ese ID ya existe!: \n");
            scanf("%d",&auxId);
        }

        }
    }

    abonado[espacioLibre].id = auxId;

      printf("Numero del abonado: \n");
    scanf("%d", &auxNum);

    for(i=0;i<tam;i++)
    {
        if(abonado[i].estado == 1){
        if(auxNum == abonado[i].numero)
        {
            printf("Ese numero ya existe!: \n");
            scanf("%d",&auxNum);
        }
        }
    }

    abonado[espacioLibre].numero = auxNum;
    abonado[espacioLibre].estado = 1;
    strcat(abonado[espacioLibre].apeNombre, abonado[espacioLibre].nombre);
    strcat(abonado[espacioLibre].apeNombre, " ");
    strcat(abonado[espacioLibre].apeNombre, abonado[espacioLibre].apellido);

    mostrarLista(abonado, strlen(abonado));

}
int obtenerEspacioLibre(eAbonado abonado[])
{
    int espacioLibre;
    int i;

    for(i=0; i<200; i++)
    {
        if(abonado[i].estado != 1)
        {
            espacioLibre = i;
            return espacioLibre;
            break;
        }
    }

    return -1;

}

mostrarAbonado(eAbonado abonado[], int abonadoNum)
{
    printf("Nombre: %s, numero: %d, ID: %d\n",abonado[abonadoNum].apeNombre, abonado[abonadoNum].numero, abonado[abonadoNum].id);
}


mostrarLista(eAbonado abonado[], int tam)
{
      int i;
     for(i=0; i<tam; i++)
            {
                if(abonado[i].estado == 1)
                {
                    mostrarAbonado(abonado, i);
                }
            }
}





/*inicializarEstados(eAbonado abonado[], int tam)
{

int i;
    for(i=0; i<tam; i++)
    {
        abonado[i].estado = 0;
    }*/

