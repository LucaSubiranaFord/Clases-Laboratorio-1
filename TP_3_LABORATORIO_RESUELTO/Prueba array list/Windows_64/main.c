#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

int main()
{
    char seguir='s';
    int opcion=0;
    ArrayList* lista;
    eMovie* aux;
    lista = al_newArrayList();
    char nombre[10] = "Luca";
    int edad = 15;
    char nombre2[10] = "Gonza";
    int edad2 = 17;
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
                agregarPelicula(lista);
                break;
            case 2:
                borrarPelicula(lista);
                break;
            case 3:
                modificarPelicula(lista);
               break;
               case 4:
                   generarPagina(lista);
               break;
            case 5:
                 for(i=0;i<al_len(lista);i++)
                {
                    aux = newMovie();
                    aux = al_get(lista,i);
                    printf("%s --- %d\n", aux->titulo, aux->puntaje);
                }
                seguir = 'n';
                break;
        }
    }

    return 0;
}
