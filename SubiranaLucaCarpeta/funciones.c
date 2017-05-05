#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 20
#define ALPHA_ROMEO 500
#define FERRARI 501
#define AUDI 502
#define OTRO 503

inicializarContador(eContador contador[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        contador[i].precio = 0;
    }
}

inicializarEstados(eAuto automovil[], eDueno dueno[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        automovil[i].estado = 0;
        dueno[i].estado = 0;
    }
}

listado(eContador contador[], eAuto automovil[], eDueno dueno[], int tam)
{
    int i, j;
    int aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(automovil[i].horario>automovil[j].horario)
            {
                aux=automovil[i].horario;
                automovil[i].horario=automovil[j].horario;
                automovil[j].horario=aux;
            }
        }
    }

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(automovil[i].idDueno == dueno[j].idDueno)
            {
                if(automovil[i].estado == 1)
                {
                    printf("Dueno: %s, Hora entrada: %d, patente: %d", dueno[j].apeNombre, automovil[i].horario, automovil[i].patente);
                }


            }
        }

    }

// TODOS LOS PROPIETARIOS DE AUDI:
    printf("\nPropietarios AUDI: \n");
    for(i=0; i<tam; i++)
    {
        if(automovil[i].marca == 500)
        {
            for(j=0; j<tam; j++)
            {
                if(automovil[i].idDueno == dueno[j].idDueno)
                {
                    printf("%s\t", dueno[j].apeNombre);
                }
            }
        }
    }

    //RECAUDACION TOTAL POR MARCA
    printf("Alpha Rompeo: %d\n ", contador[0].precio);
    printf("Ferrari: %d\n ", contador[1].precio);
    printf("Audi: %d\n ", contador[2].precio);
    printf("Otros: %d\n ", contador[3].precio);

    //RECAUDACION TOTAL

    int recaudacionTotal;

    for(i=0;i<4;i++)
    {
        recaudacionTotal += contador[i].precio;
    }

    printf("La recaudacion total del estacionamiento es: %d\n", recaudacionTotal);






}

egresoAutomovil(eContador contador[], eDueno dueno[], eAuto automovil[], int tam)
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

    for(i=0; i<tam; i++)
    {
        while(flagPatente == 0)
        {
            printf("Ingrese la patente del auto: ");
            fflush(stdin);
            gets(buffer);

            if(strcmp(buffer,automovil[i].patente) == 0)
            {
                flagPatente = 1;
                break;
            }
        }

    }

    strcpy(auxPatente, buffer);

    printf("Cual es el horario de salida?: ");
    scanf("%d",&auxSalida);

    automovil[i].salida = auxSalida;

    for(i=0; i<tam; i++)
    {
        if(strcmp(automovil[i].patente,auxPatente)== 0)
        {
            auxEntrada = automovil[i].horario;
        }
    }


    int horarioTotal;
    horarioTotal = auxSalida - auxEntrada; //CANTIDAD DE HORAS EN EL ESTACIONAMIENTO
    if(horarioTotal < 0) //SI ES NEGATIVO LO HAGO POSITIVO.
    {
        horarioTotal = horarioTotal * (-1);
    }

    int pagoPorHora;
    int pagoTotal;

    for(i=0; i<tam; i++)
    {
        if(strcmp(auxPatente, automovil[i].patente)==0)
        {
            if(automovil[i].marca == ALPHA_ROMEO)
            {
                contador[0].precio = contador[0].precio + 150;
                pagoPorHora = 150;
                break;
            }
            else if(automovil[i].marca == FERRARI)
            {
                contador[1].precio = contador[1].precio + 175;
                pagoPorHora = 175;
                break;
            }
            else if(automovil[i].marca == AUDI)
            {
                contador[2].precio = contador[2].precio + 200;
                pagoPorHora = 200;
                break;
            }
            else if(automovil[i].marca == OTRO)
            {
                contador[3].precio = contador[3].precio + 250;
                pagoPorHora = 250;
                break;
            }
            break;
        }
    }

    pagoTotal = pagoPorHora * horarioTotal;

    for(i=0; i<tam; i++)
    {
        if(strcmp(auxPatente, automovil[i].patente)==0)
        {
            for(j=0; j<tam; j++)
            {
                if(automovil[i].idDueno == dueno[j].idDueno)
                {
                    printf("Nombre: %s, Patente: %s, Marca: %d, Valor estadia: %d",dueno[j].apeNombre, automovil[i].patente, automovil[i].marca, pagoTotal);
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
    int flagSwitch = 0;
    int auxMarca;
    int auxId;
    int buffer[200];
    int i;

    printf("Patente del auto: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>9)
    {
        printf("La patente debe contener menos de 10 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(automovil[espacioLibre].patente, buffer);


    printf("Escoja la marca del automovil: 1.- Alpha Romeo\t2.-Ferrari\t3.-Audi\t4.-Otro \n");

    scanf("%d",&auxMarca);
    while(flagSwitch = 0)
    {
        switch(auxMarca)
        {
        case 1:
            automovil[espacioLibre].marca = ALPHA_ROMEO;
            flagSwitch = 1;
            break;
        case 2:
            automovil[espacioLibre].marca = FERRARI;
            flagSwitch = 1;
            break;
        case 3:
            automovil[espacioLibre].marca = AUDI;
            flagSwitch = 1;
            break;
        case 4:
            automovil[espacioLibre].marca = OTRO;
            flagSwitch = 1;
            break;
        default:
            printf("Tiene que escojer una de las opciones dadas!");
            break;
        }

    }


    printf("ID del dueno del auto: \n");
    scanf("%d", &auxId);


    automovil[espacioLibre].idDueno = auxId;

    printf("Horario de entrada: \n");
    scanf("%d", &automovil[espacioLibre].horario);


    automovil[espacioLibre].estado = 1;


    mostrarAuto(automovil, espacioLibre);
}

mostrarAuto(eAuto automovil[], int autoNum)
{
    printf("Patente: %s, ID del dueno: %d, horario de entrada: %d, Marca: %d,\n",automovil[autoNum].patente, automovil[autoNum].idDueno, automovil[autoNum].horario, automovil[autoNum].marca);
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
    int auxNum;
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
            if(auxId == dueno[i].idDueno)
            {
                printf("Ese ID ya existe!: \n");
                scanf("%d",&auxId);
            }

        }
    }

    dueno[espacioLibre].idDueno = auxId;

    printf("Numero de tarjeta de credito: \n");
    scanf("%d", &auxNum);

    for(i=0; i<tam; i++)
    {
        if(dueno[i].estado == 1)
        {
            if(auxNum == dueno[espacioLibre].tarjetaNum)
            {
                printf("Ese numero ya existe!: \n");
                scanf("%d",&auxNum);
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
    printf("Nombre: %s, Id: %d, Tarjeta de credito: %d, Direccion: %s,\n",dueno[duenoNum].apeNombre, dueno[duenoNum].idDueno, dueno[duenoNum].tarjetaNum, dueno[duenoNum].direccion);
}



