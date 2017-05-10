#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 20


inicializarContador(int contador[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        contador[i] = 0;
    }
}

inicializarEstados(eAuto automovil[], eDueno dueno[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        automovil[i].estado = 0;
        dueno[i].estado = 0;
        automovil[i].estadoEstadia = 0;
    }
}

listado(int contador[], eAuto automovil[], eDueno dueno[], int tam)
{
    int i, j;
    int aux;


for(i=0; i<tam-1; i++) //ORDENAMIENTO DE COCHES POR HORA
    {
        for
        (j=i+1; j<tam; j++)
        {
            if
            (automovil[j].horario>automovil[i].horario)
            {
                aux=automovil[j].horario;
                automovil[j].horario=automovil[i].horario;
                automovil[i].horario=aux;
            }
        }
    }


  for(i=0; i<tam; i++) //MUESTRA DE COCHE POR DUENO, ORDENAMIENTO POR HORA Y PATENTE
    {

            for(j=0; j<tam; j++)
            {
                if(automovil[i].idDueno == dueno[j].idDueno && automovil[i].estado == 1)
                {
                    printf("\nNombre: %s, Patente: %s, Marca: %s, Hora entrada: %d\n",dueno[j].apeNombre, automovil[i].patente, automovil[i].marca, automovil[i].horario);
                    break;
                }
            }

    }


// TODOS LOS PROPIETARIOS DE AUDI:
    printf("\nPropietarios AUDI: \n");
    for(i=0; i<tam; i++)
    {
        if(strcmp(automovil[i].marca,"Audi")==0 && automovil[i].estadoEstadia == 1) //MUESTRA SOLO LOS PROPIETARIOS AUDIS QUE ESTAN ESTACIONADOS.
        {
            for(j=0; j<tam; j++)
            {
                if(automovil[i].idDueno == dueno[j].idDueno)
                {
                    printf("\n%s", dueno[j].apeNombre);
                    break;
                }
            }
        }
    }

   //RECAUDACION TOTAL POR MARCA
    printf("\nRecaudacion total por marca: \n\n");
    printf("Alpha Romeo: %d\n ", contador[0]);
    printf("Ferrari: %d\n ", contador[1]);
    printf("Audi: %d\n ", contador[2]);
    printf("Otros: %d\n ", contador[3]);

    //RECAUDACION TOTAL DEL ESTACIONAMIENTO

    int recaudacionTotal = 0;

    for(i=0; i<4; i++)
    {
        recaudacionTotal += contador[i];
    }

    printf("\n\nLa recaudacion total del estacionamiento es: %d\n", recaudacionTotal);





}

egresoAutomovil(int contador[], eDueno dueno[], eAuto automovil[], int tam)
{
    int flagPatente = 0;
    char buffer[200];
    int i, j;
    int auxSalida;
    int auxEntrada;
    char auxPatente[1][10];

    printf("Ingrese la patente del auto: ");
    fflush(stdin);
    gets(buffer);

    while(flagPatente == 0)
    {
        for(i=0; i<tam; i++)
        {
            if(strcmp(buffer,automovil[i].patente)==0 && automovil[i].estado == 1)
            {
                flagPatente = 1;
                break;
            }
        }

        if(flagPatente == 0)
        {
            printf("Esa patente no esta registrada! Ingrese una distinta: \n");
            fflush(stdin);
            gets(buffer);
        }

    }

    strcpy(auxPatente, buffer);

     for(i=0; i<tam; i++)
    {
        if(strcmp(automovil[i].patente,auxPatente)== 0)
        {
            auxEntrada = automovil[i].horario;
        }
    }

    printf("Horario de salida: \n");
    scanf("%d", &auxSalida);

    while(auxSalida<auxEntrada || auxSalida>23) //VERIFICA QUE NO HAYA ESTADO DE UN DIA PARA EL OTRO EN EL ESTACIONAMIENTO. CONTANDO COMO LAS 24 HORAS YA UN DIA NUEVO.
    {
        printf("Tiene que ingresar un horario valido! (Un coche no pudo haber estado de un dia para el otro!)\n");
        scanf("%d", &auxSalida);
    }

    automovil[i].salida = auxSalida;

    int horarioTotal;
    horarioTotal = auxSalida - auxEntrada; //CANTIDAD DE HORAS EN EL ESTACIONAMIENTO

    int pagoPorHora;
    int pagoTotal;

        for(i=0; i<tam; i++)
    {
        if(strcmp(auxPatente, automovil[i].patente)==0)
        {
            if(strcmp(automovil[i].marca,"Alpha Romeo") == 0)
            {
                pagoPorHora = 150;
                pagoTotal = pagoPorHora * horarioTotal;
                contador[0] += pagoTotal;
                break;
            }
            else if(strcmp(automovil[i].marca,"Ferrari") == 0)
            {

                pagoPorHora = 175;
                pagoTotal = pagoPorHora * horarioTotal;
                contador[1] += pagoTotal;
                break;
            }
            else if(strcmp(automovil[i].marca,"Audi") == 0)
            {

                pagoPorHora = 200;
                pagoTotal = pagoPorHora * horarioTotal;
                contador[2] += pagoTotal;
                break;
            }
            else if(strcmp(automovil[i].marca,"Otro") == 0)
            {

                pagoPorHora = 250;
                pagoTotal = pagoPorHora * horarioTotal;
                contador[3] += pagoTotal;
                break;
            }
            break;
        }
    }



    for(i=0; i<tam; i++)
    {
        if(strcmp(auxPatente, automovil[i].patente)==0)
        {
            for(j=0; j<tam; j++)
            {
                if(automovil[i].idDueno == dueno[j].idDueno)
                {
                    printf("Nombre: %s, Patente: %s, Marca: %s, Valor estadia: %d",dueno[j].apeNombre, automovil[i].patente, automovil[i].marca, pagoTotal);
                    break;
                }
            }
        }
    }


}

int obtenerEspacioLibreAuto(eAuto automovil[], int tam)
{
    int espacioLibre;
    int i;

    for(i=0; i<tam; i++)
    {
        if(automovil[i].estado != 1)
        {
            espacioLibre = i;
            return espacioLibre;
            break;
        }
    }

    return -1;
}

altaAuto(eAuto automovil[], eDueno dueno[], int espacioLibre, int tam)
{
    int flagMarca = 0;
    int auxMarca;
    int auxId;
    int buffer[200];
    int i;
    int flagPatente = 0;


    while(flagPatente == 0)
    {
        printf("Patente del auto: \n");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)>9)
        {
            printf("La patente debe contener menos de 10 caracteres: \n");
            fflush(stdin);
            gets(buffer);
        }


        for(i=0; i<tam; i++)
        {
            if(strcmp(buffer,automovil[i].patente) == 0)
            {
                flagPatente = 0;
                break;
            }
            else
            {
                flagPatente = 1;
            }
        }

    }


    strcpy(automovil[espacioLibre].patente, buffer);


    while(flagMarca == 0)
    {
        printf("Escoja la marca del automovil: 1.- Alpha Romeo\t2.-Ferrari\t3.-Audi\t4.-Otro \n");
        scanf("%d",&auxMarca);

        if(auxMarca == 1)
        {
            flagMarca = 1;
            strcpy(automovil[espacioLibre].marca,"Alpha Romeo");
        }
        else if(auxMarca == 2)
        {
            flagMarca = 1;
            strcpy(automovil[espacioLibre].marca, "Ferrari");
        }
        else if(auxMarca == 3)
        {
            flagMarca = 1;
            strcpy(automovil[espacioLibre].marca,"Audi");
        }
        else if(auxMarca == 4)
        {
            flagMarca = 1;
            strcpy(automovil[espacioLibre].marca,"Otro");
        }
        else
        {

            printf("Debe escojer una de las opciones dadas!\n");

        }

    }

    printf("ID del dueno del auto: \n"); //NO SE ACLARA SI UN DUENO PUEDE INGRESAR MAS DE DOS AUTOS. SI NO SE PUEDE, SE HARIA UNA VERIFICACION.
    scanf("%d", &auxId);


    int flagIdDuenoAuto = 0; //VARIABLE BANDERA QUE VERIFICA SI EXISTE UN DUENO CON EL ID INGRESADO

    // BUSCADOR DE AUXID EN ESTRUCTURA DUENO
    while(flagIdDuenoAuto == 0)
    {
        for(i=0; i<tam; i++)
        {
            if(auxId == dueno[i].idDueno)
            {
                flagIdDuenoAuto = 1;
                break;
            }
        }
        if(flagIdDuenoAuto == 0)
        {
            printf("No existe un dueno con ese ID!. Ingrese otro:  \n");
            scanf("%d", &auxId);
        }

    }

        automovil[espacioLibre].idDueno = auxId;

    int auxHorario; //VARIABLE AUXILIAR PARA VERIFICAR HORARIO DE ENTRADA.

    printf("Horario de entrada: \n");
    scanf("%d", &auxHorario);

    while(auxHorario<1 || auxHorario>24) //VERIFICA QUE EL HORARIO ESTE DENTRO DEL FORMATO DE 24 HORAS.
    {
        printf("Tiene que ingresar un horario valido! (entre 1 y 24\n)");
        scanf("%d", &auxHorario);
    }


    automovil[espacioLibre].horario = auxHorario;

    automovil[espacioLibre].estado = 1;


    mostrarAuto(automovil, espacioLibre);
}

mostrarAuto(eAuto automovil[], int autoNum)
{

    printf("Patente: %s, ID del dueno: %d, horario de entrada: %d, Marca: %s\n",automovil[autoNum].patente, automovil[autoNum].idDueno, automovil[autoNum].horario, automovil[autoNum].marca);

}


modificarDueno(eDueno dueno[], int tam)
{
    int flag = 0;
    int auxTarjeta;
    char buffer[200];
    printf("Ingrese la tarjeta de credito del dueno a modificar: ");
    scanf("%d", &auxTarjeta);

    int i;

    for(i=0; i<tam; i++)
    {
        if(auxTarjeta == dueno[i].tarjetaNum && dueno[i].estado == 1)
        {

            printf("Ingrese el nuevo nombre: \n");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer)>49)
            {
                printf("El nombre debe contener menos de 50 caracteres: \n");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(dueno[i].nombre, buffer);


            printf("Ingrese el nuevo apellido de la persona: \n");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer)>49)
            {
                printf("El Apellido debe contener menos de 50 caracteres: \n");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(dueno[i].apellido, buffer);

            printf("Ingrese la nueva direccion de la persona: \n");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer)>49)
            {
                printf("La direccion debe contener menos de 50 caracteres: \n");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(dueno[i].direccion, buffer);

            printf("Ingrese la nueva tarjeta de credito de la persona: \n");
            scanf("%d",&dueno[i].tarjetaNum);

            printf("Ingrese el nuevo ID de la persona: \n");
            scanf("%d",&dueno[i].idDueno);

            strcpy(dueno[i].apeNombre, "\0");
            strcat(dueno[i].apeNombre, dueno[i].nombre);
            strcat(dueno[i].apeNombre, " ");
            strcat(dueno[i].apeNombre, dueno[i].apellido);

            mostrarDueno(dueno, i);

            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Esa tarjeta de credito no existe!");
    }
}

altaDueno(eDueno dueno[], int espacioLibre, int tam)

{
    long long auxNum;
    int auxId;
    int buffer[200];
    int i;

    printf("Nombre de la persona: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>49)
    {
        printf("El nombre debe contener menos de 50 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(dueno[espacioLibre].nombre, buffer);


    printf("Apellido de la persona: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>49)
    {
        printf("El Apellido debe contener menos de 50 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(dueno[espacioLibre].apellido, buffer);

    printf("Direccion del dueno: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>49)
    {
        printf("La direccion debe contener menos de 50 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(dueno[espacioLibre].direccion, buffer);

    printf("ID del dueno: \n");
    scanf("%d", &auxId);

    for(i=0; i<tam; i++)
    {
        if(dueno[i].estado == 1)
        {
            while(auxId == dueno[i].idDueno)
            {
                printf("Ese ID ya existe!: \n");
                scanf("%d",&auxId);
            }

        }
    }

    dueno[espacioLibre].idDueno = auxId;

    printf("Numero de tarjeta de credito: \n");
    scanf("%lli", &auxNum);

    for(i=0; i<tam; i++)
    {
        if(dueno[i].estado == 1)
        {
            while(auxNum == dueno[i].tarjetaNum)
            {
                printf("Esa tarjeta de credito ya existe!: \n");
                scanf("%lli",&auxNum);
            }
        }
    }

    dueno[espacioLibre].tarjetaNum = auxNum;

    dueno[espacioLibre].estado = 1;



    strcat(dueno[espacioLibre].apeNombre, dueno[espacioLibre].nombre);
    strcat(dueno[espacioLibre].apeNombre, " ");
    strcat(dueno[espacioLibre].apeNombre, dueno[espacioLibre].apellido);

    mostrarDueno(dueno, espacioLibre);

}

int obtenerEspacioLibre(eDueno dueno[], int tam)
{
    int espacioLibre;
    int i;

    for(i=0; i<tam; i++)
    {
        if(dueno[i].estado != 1)
        {
            espacioLibre = i;
            return espacioLibre;
            break;
        }
    }

    return -1;
}

mostrarDueno(eDueno dueno[], int duenoNum)
{
    printf("Nombre: %s, Id: %d, Tarjeta de credito: %lli, Direccion: %s,\n",dueno[duenoNum].apeNombre, dueno[duenoNum].idDueno, dueno[duenoNum].tarjetaNum, dueno[duenoNum].direccion);
}



