#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define S 20
#define ALPHA_ROMEO 500
#define FERRARI 501
#define AUDI 502
#define OTRO 503


int main()
{
    int flagIngreso = 0;
    int flagAutomovil = 0;
    int flagIngresoAuto = 0;
    int espLibre, espLibreAuto;
    eDueno dueno[S];
    eContador contador[4];
    eAuto automovil[S];
    int flagSeguir = 0;
    int opcion;
    inicializarEstados(automovil, dueno, S);
    inicializarContador(contador,S);
    while(flagSeguir == 0)
    {

        printf("\n1.-ALTA DUE�O\n");
        printf("2.-MODIFICACION DUE�O\n");
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
            flagAutomovil = 1;
            if(flagIngreso == 1)
            {
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
               egresoAutomovil(contador, dueno, automovil, S);
            }else
            {
               printf("Primero debe ingresar un automovil!");
            }

            break;
        case 5:
            listado(contador, automovil, dueno, S);
            break;

        default:
            printf("\nIngrese una opcion correcta!\n");
            break;
        }

    }
    return 0;
}

