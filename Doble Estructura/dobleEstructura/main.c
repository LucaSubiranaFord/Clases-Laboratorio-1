#include <stdio.h>
#include <stdlib.h>
#define C 10
#define S 5

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


typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
} eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;
    int idSerie;
} eCliente;

typedef struct
{
    int idSerie;
    int cont;
} eLoser;

void cargarSeries(eSerie[]);
void cargarClientes(eCliente[]);

void mostrarSeries(eSerie[],int);
void mostrarClientes(eCliente[], int);
void mostrarClientesConSerie(eCliente[], eSerie[], int, int);
void mostrarSeriesConClientes(eCliente[], eSerie[], int, int);
void mostrarSerieLoser(eLoser[], eCliente[], eSerie[], int, int);
void mostrarClientesTBBT(eCliente[], eSerie[], int, int);

int main()
{
    eLoser losers[S];
    eSerie series[S];
    eCliente clientes[C];
    cargarSeries(series);
    cargarClientes(clientes);

    //MOSTRAR SERIES
    mostrarSeries(series, S);
    printf("\n**************************************\n");
    // MOSTRAR CLIENTES
    mostrarClientes(clientes, C);
    printf("\n**************************************\n");
    //MOSTRAR CLIENTES CON SU SERIE
    mostrarClientesConSerie(clientes, series, C, S);
    printf("\n**************************************\n");
    // POR CADA SERIE LOS CLIENTES QUE LA ESTAN VIENDO
    mostrarSeriesConClientes(clientes, series, C, S);
    printf("\n**************************************\n");
    //TODOS LOS CLIENTES QUE VEN TBBT
    mostrarClientesTBBT(clientes, series, C, S);
    printf("\n**************************************\n");
    //LA SERIE MENOS POPULAR
    mostrarSerieLoser(losers, clientes, series, C, S);
    printf("\n**************************************\n");

    return 0;
}

void cargarSeries(eSerie series[])
{
    int idSerie[5]= {100,101,102,103,104};
    int estado[5]= {1,1,1,1,1};
    char titulo[5][30]= {"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]= {9,7,7,6,1};
    char genero[5][30]= {"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
    for(i=0; i<5; i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]= {"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};
    int idSerie[10]= {100,100,101,103,103,101,102,103,100,100};
    int i;

    for(i=0; i<10; i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
        clientes[i].idSerie = idSerie[i];
    }

}

void mostrarSeries(eSerie series[],int tam)
{
    int i;
      for(i=0; i<tam; i++)
    {
        if(series[i].estado == 1)
        {
            printf("\nid: %d, titulo: %s, temporadas: %d, genero: %s", series[i].idSerie, series[i].titulo, series[i].temporadas, series[i].genero);
        }
    }

}

void mostrarClientes(eCliente clientes[], int tam)
{
    int i;
     for(i=0; i<tam; i++)
    {
        if(clientes[i].estado == 1)
        {
            printf("\nid: %d, nombre: %s, id serie: %d", clientes[i].idCliente, clientes[i].nombre, clientes[i].idSerie);
        }
    }
}

void mostrarClientesConSerie(eCliente clientes[], eSerie series[], int tamC, int tamS)
{
    int i;
    int j;
    for(i=0; i<tamC; i++)
    {
        for(j=0; j<tamS; j++)
        {
            if(series[j].idSerie == clientes[i].idSerie)
            {
                printf("\nCliente: %s, \t Serie: %s", clientes[i].nombre, series[j].titulo);
            }
        }
    }
}

void mostrarSeriesConClientes(eCliente clientes[], eSerie series[], int tamC, int tamS)
{
    int j;
    int i;
    for(i=0; i<tamS; i++)
    {
        printf("\n%s", series[i].titulo);
        for(j=0; j<tamC; j++)
        {
            if(series[i].idSerie == clientes[j].idSerie)
            {
                printf("\t%s\t", clientes[j].nombre);
            }
        }
    }
}

void mostrarSerieLoser(eLoser losers[], eCliente clientes[], eSerie series[], int tamC, int tamS)
{


    //REVISAR FUNCION. SE PUEDE HACER SIN FLAG SI QUIERO !
    int i;
    int j;
    for(i=0; i<tamS; i++) // restauro todos los contadores a 0
    {
        losers[i].cont = 0;
        losers[i].idSerie = series[i].idSerie;
    }

    for(i=0; i<tamS; i++)
    {
        for(j=0; j<tamC; j++)
        {
            if(losers[i].idSerie == clientes[j].idSerie)
            {
                losers[i].cont++;
            }
        }
    }

    int flag = 0;
    int min = losers[0].cont;
    for(i=0; i<tamS; i++)
    {
        if(flag == 0 || losers[i].cont < min)
        {
            flag = 1;
            min = losers[i].cont;
        }
    }
    for(i=0; i<tamS; i++)
    {
        if(min == losers[i].cont)
        {
            for(j=0;j<tamS;j++)
            {
                if(losers[i].idSerie == series[j].idSerie)
                {
                    printf("El nombre de la mas loser es: %d", series[j].titulo);
                    break;
                }
            }
        }

    }
}

void mostrarClientesTBBT(eCliente clientes[], eSerie series[], int tamC, int tamS)
{
    int i;
    int j;
    printf("\nTBBT: \n");
    // COMPARAR CON EL NOMBRE, PRIMERO BUSCAR EL ID A TRAVES DEL NOMBRE Y DESPUES CON EL ID ENCONTRAR EL NOMBRE.


    // despues aplicar este codigo!
        for(i=0; i<tamC; i++)
            {
                if(clientes[j].idSerie == 100)
                {
                printf("%s\t",clientes[j].nombre);
                }

            }
}

