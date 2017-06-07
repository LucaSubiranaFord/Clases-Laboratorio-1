#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int contLista = 1;
    eMovie* lista;
    lista = (eMovie*) malloc(sizeof(eMovie));
    int i;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            agregarMovieLista(lista,contLista);
            contLista++;
            break;
        case 2:
            for(i=0;i<4;i++)
            {
                printf("%s \t %d\n", (lista+i)->titulo, (lista+i)->edad);
            }
            break;
        case 3:
            break;
        case 4:
            //agregarPelicula(lista, archivo, contLista);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Ingreso una opcion incorrecta! \n");
            break;
        }
    }

    return 0;
}
