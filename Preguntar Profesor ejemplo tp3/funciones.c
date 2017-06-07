#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


eMovie* newMovie()
{
    eMovie* auxMovie;

    auxMovie = (eMovie*) malloc ( sizeof(eMovie) );

    return auxMovie;
}

/*eMovie* newMovieParametrizada(char titulo[], char genero[], int duracion, char descripcion[], int puntaje, char link[])
{
    eMovie* auxMovie;
    auxMovie = newMovie();

    auxMovie->puntaje = puntaje;
    auxMovie->duracion = duracion;
    strcpy(auxMovie->descripcion, descripcion);
    strcpy(auxMovie->genero, genero);
    strcpy(auxMovie->linkImagen, link);
    strcpy(auxMovie->titulo,titulo);

    return auxMovie;
}*/


int agregarMovieLista(eMovie* lista, int contLista)
{

    lista = realloc(lista,sizeof(eMovie)*contLista);

    printf("Nombre: \n");
    fflush(stdin);
    gets( (lista+contLista-1)->titulo);

    printf("Edad:  \n");
    scanf("%d",&(lista+contLista-1)->edad);

    return 0;
}


/*
borrarPelicula(eMovie* lista,int tam)
{
    int i,j;
    eMovie* movie;
    eMovie* aux;
    char auxNombre[20];
    int existePelicula = 0;
    int auxI;

    aux = (eMovie*) malloc (sizeof(eMovie));

    while(existePelicula == 0)
    {
        printf("Ingrese el titulo que desee eliminar: \n");
        fflush(stdin);
        gets(auxNombre);

        for(i=0; i<tam; i++)
        {
            if( strcmp( (lista+i)->titulo,auxNombre)  == 0 )
            {
                auxI = i;
                existePelicula = 1;
                break;
            }
        }

        if(existePelicula == 0)
        {
            printf("Esa pelicula no existe!\n");
        }
    }


    for(i=auxI; i<(tam-1); i++)
    {
        for(j=(i+1); j<tam; j++)
        {
            aux = (lista+i);
            (lista+i) = (lista+j);
            (lista+j) = aux;
            break;
        }
    }
}




agregarPelicula(eMovie* lista,FILE* archivo, int tam)
{
    int i;

    archivo = fopen("paginaPeliculas.html","w");
    fprintf(archivo, "<html><body><header><h1>ABC</h1></header></body></html>");
    for(i=0; i<tam; i++)
    {
        fprintf(archivo, "<article class='col-md-4 article-intro'>\
                <a href='#'>\
                <img class='img-responsive img-rounded' src='\
                http://ia.media-\
                imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg\
                '\
                alt=''>\
                </a>\
                <h3>\
                <a href='#'>\
                %s\
                </a>\
                </h3>\
                <ul>\
                <li>Género:\
                %s\
                </li>\
                <li>Puntaje:\
                %d\
                </li>\
                <li>Duración:\
                %d\
                </li>\
                </ul>\
                <p>\
                %s\
                </p>\
                </article>",(lista+i)->titulo,(lista+i)->genero,(lista+i)->puntaje,(lista+i)->duracion,(lista+i)->descripcion);
    }

    fclose(archivo);
}
*/
