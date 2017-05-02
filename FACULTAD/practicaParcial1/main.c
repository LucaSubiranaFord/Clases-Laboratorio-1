#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 10

typedef struct
{

    int idSerie;
    char titulo[50];
    int estado;
} eSerie;


typedef struct
{
    int estado;
    char nombre[50];
    int idCliente;
} eCliente;


typedef struct
{
    int idSerie;
    int idCliente;
} eClienteSerie;

typedef struct
{
    int idSerie;
    int contador;
} eContador;


void cargarSeries(eSerie[], int tam);
void cargarClientes(eCliente[], int);
void cargarClienteSerie(eCliente[], eSerie[], eClienteSerie[], int);
mostrarSeries(eSerie[], int);
inicializarEstados(eSerie[],eCliente clientes[],  int);
mostrarSerie(eSerie[], int);
mostrarCliente(eCliente[], int);
mostrarClientes(eCliente[], int);
mostrarClienteConSerie(eCliente[], eSerie[], eClienteSerie[], int);
mostrarSerieConClientes(eCliente[], eSerie[], eClienteSerie[], int);
mostrarTBBT(eCliente[], eSerie[], eClienteSerie[], int);
serieMenosPopular(eContador[], eCliente[], eSerie[], eClienteSerie[], int);
inicializarContador(eContador contador[], eSerie series[], int tam);


/*
1- mostrar series
2- mostrar clientes
3- mostrar clientes con su serie
4- por cada serie los clientes que la estan viendo
5- todos los clientes que ven TBBT (100)
6- La serie menos popular

Crear una cuarta estructura que permita relacionar un cliente con una serie, de esta manera podremos obtener una relacion
muchos a muchos (Un cliente que ve muchas series)

7- Todas las series que ven los clientes de nombre "Juan"
*/
int main()
{

    eSerie series[S];
    eContador contador[S];
    eCliente clientes[S];
    eClienteSerie clienteSerie[S];


    cargarSeries(series, S);
    cargarClientes(clientes, S);
    cargarClienteSerie(clientes, series, clienteSerie, S);
    inicializarEstados(series, clientes, S);
    inicializarContador(contador, series, S);


    mostrarSeries(series, S);
    printf("\n/////////////////////////////////////////////////////\n\n");
    mostrarClientes(clientes, S);
    printf("\n/////////////////////////////////////////////////////\n\n");
    mostrarClienteConSerie(clientes, series, clienteSerie, S);
    printf("\n/////////////////////////////////////////////////////\n\n");
    mostrarSerieConClientes(clientes, series, clienteSerie, S);
    printf("\n/////////////////////////////////////////////////////\n\n");
    mostrarTBBT(clientes, series, clienteSerie, S);
    printf("\n/////////////////////////////////////////////////////\n\n");
    serieMenosPopular(contador, clientes,  series, clienteSerie, S);
    return 0;
}


void cargarSeries(eSerie series[], int tam)
{
//"Luca","Juan","Pedro","Ivan","Alberto","Alejandro","Julian","Romero","Garcia", "Ramiro"
    int i;
    char nombre[5][50] = {"AHS","TBBT","TBBT","BB","FRIENDS"};
    int id[5] = {100,101,102,103,104};

    for(i=0; i<5; i++)
    {
        strcpy(series[i].titulo, nombre[i]);
        series[i].idSerie = id[i];
        series[i].estado = 1;
    }

}


void cargarClientes(eCliente clientes[], int tam)
{
    int i;
    char nombre[10][50] = {"Luca","Juan","Pedro","Ivan","Luca","Alejandro","Julian","Romero","Garcia", "Ramiro"};
    int id[10] = {20,21,22,23,24,25,26,27,28,29};

    for (i=0;i<tam;i++)
    {
        strcpy(clientes[i].nombre, nombre[i]);
        clientes[i].idCliente = id[i];
        clientes[i].estado = 1;
    }
}


mostrarSeries(eSerie series[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(series[i].estado == 1)
        {
            mostrarSerie(series, i);
        }
    }
}

mostrarClientes(eCliente clientes[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(clientes[i].estado == 1)
        {

        mostrarCliente(clientes, i);
    }
    }
}


inicializarEstados(eSerie series[], eCliente clientes[], int tam)
{

    int i;
    for(i=0; i<tam; i++)
    {
        series[i].estado = 0;
        clientes[i].estado = 0;
    }

}


mostrarSerie(eSerie series[], int serie)
{
    printf("Nombre: %s, ID: %d\n",series[serie].titulo, series[serie].idSerie);
}

mostrarCliente(eCliente clientes[], int cliente)
{
    printf("Nombre: %s, ID: %d\n",clientes[cliente].nombre, clientes[cliente].idCliente);
}

cargarClienteSerie(eCliente clientes[], eSerie series[], eClienteSerie clienteSeries[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        clienteSeries[i].idSerie = series[i].idSerie;
        clienteSeries[i].idCliente = clientes[i].idCliente;
    }

}

mostrarClienteConSerie(eCliente clientes[], eSerie series[], eClienteSerie clienteSeries[], int tam)
{
    int i,j;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {

            if(clienteSeries[i].idCliente == clientes[j].idCliente)
            {
                printf("%s\t",clientes[j].nombre);
                if(clienteSeries[i].idSerie == series[j].idSerie)
                {
                    printf("%s\n",series[j].titulo);
                }
            }

        }
    }
}

mostrarSerieConClientes(eCliente clientes[], eSerie series[], eClienteSerie clienteSeries[], int tam)
{
    int i,j;

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(clienteSeries[i].idSerie == series[j].idSerie)
            {
                printf("%s\t", series[j].titulo);
                if(clienteSeries[i].idCliente == clientes[j].idCliente)
                {
                    printf("%s\n", clientes[j].nombre);
                }
            }

        }
    }
}

mostrarTBBT(eCliente clientes[], eSerie series[], eClienteSerie clienteSeries[], int tam)
{
    int i,j,k;
    int auxTBBT;

    printf("TBBT: \t");
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(strcmp(series[i].titulo, "TBBT") == 0)
            {
                auxTBBT = series[i].idSerie;
                if(auxTBBT == clienteSeries[j].idSerie)
                {
                    for(k=0; k<tam; k++)
                    {
                        if(clientes[k].idCliente == clienteSeries[j].idCliente)
                        {
                            printf("%s\n", clientes[k].nombre);
                        }
                    }

                }
            }
        }
    }
}

serieMenosPopular(eContador contador[], eCliente clientes[], eSerie series[], eClienteSerie clienteSeries[], int tam)
{
    int i,j;


    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {

            if(clienteSeries[j].idSerie == contador[i].idSerie)
            {
                contador[i].contador++;
            }

        }
    }


    int auxMin = contador[0].contador;
    int auxIdSerie = contador[0].idSerie;

    for(i=0; i<tam; i++)
    {
        if(contador[i].contador < auxMin)
        {
            auxMin = contador[i].contador;
            auxIdSerie = contador[i].idSerie;
        }
    }

    for(i=0; i<tam; i++)
    {
        if(auxIdSerie == series[i].idSerie)
        {
            printf("%s\n", series[i].titulo);
        }
    }

}

inicializarContador(eContador contador[], eSerie series[], int tam)
{

    int i;
    for(i=0; i<tam; i++)
    {
        contador[i].contador = 0;
        contador[i].idSerie = series[i].idSerie;
    }

}

