#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define S 20

int main()
{
    int flagIngreso = 0;
    int flagAutomovil = 0;
    int flagIngresoAuto = 0;
    int espLibre, espLibreAuto;
    eDueno dueno[S];
    int contadorPrecio[4];
    eAuto automovil[S];
    int flagSeguir = 0;
    int opcion;
    inicializarEstados(automovil, dueno, S);
    inicializarContador(contadorPrecio,S);
    while(flagSeguir == 0)
    {

        printf("\n1.-ALTA DUEÑO\n");
        printf("2.-MODIFICACION DUEÑO\n");
        printf("3.-INGRESO DEL AUTOMOVIL\n");
        printf("4.-EGRESO DEL AUTOMOVIL\n");
        printf("5.-INFORMAR\n");
        printf("\n1.-Ingrese una opcion: \n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            espLibre = obtenerEspacioLibre(dueno, S);
            flagIngreso = 1;
            if(espLibre != -1)
            {
                altaDueno(dueno,espLibre,S);
            }
            else
            {
                printf("No queda espacio!");
            }
            break;
        case 2:
            if(flagIngreso == 1)
            {
                modificarDueno(dueno,S);
            }
            else
            {
                printf("Primero debe ingresar un dueno!");
            }
            break;
        case 3:

            if(flagIngreso == 1)
            {
                flagAutomovil = 1;
                espLibreAuto = obtenerEspacioLibreAuto(automovil,S);
                altaAuto(automovil, dueno, espLibreAuto, S);
            }
            else
            {
                printf("Primero debe ingresar un dueno!");
            }

            break;
        case 4:
            if(flagAutomovil == 1)
            {
               egresoAutomovil(contadorPrecio, dueno, automovil, S);
            }else
            {
               printf("Primero debe ingresar un automovil!");
            }

            break;
        case 5:
            listado(contadorPrecio, automovil, dueno, S);
            break;

        default:
            printf("\nIngrese una opcion correcta!\n");
            break;
        }

    }
    return 0;
}


