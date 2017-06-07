#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char titulo[20];
    int edad;
}eMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie*, int);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
//borrarPelicula(eMovie*,int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
//void generarPagina(eMovie lista[], char nombre[]);


eMovie* newMovie(void);

//eMovie* newMovieParametrizada(char[], char[], int, char[], int, char[]);

//int agregarMovieLista(eMovie*, int);
