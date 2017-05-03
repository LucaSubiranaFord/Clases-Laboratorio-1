#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int id;
    int numero;
    char nombre[50];
    char apellido[50];
    int estado;
    char apeNombre[];

}eAbonado;


void agregarPersona(eAbonado[],int, int);

int obtenerEspacioLibre(eAbonado[]);

mostrarAbonado(eAbonado[], int);

void mostrarLista(eAbonado abonado[], int tam);

//inicializarEstados(eAbonado abonado[], int);
