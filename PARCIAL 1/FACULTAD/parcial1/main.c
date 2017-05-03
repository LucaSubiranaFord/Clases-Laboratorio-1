#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 10


typedef struct
{
    int id;
    int numero;
    char nombre[50];
    char apellido[50];
    int estado;
    char apeNombre[];

} eAbonado;


typedef struct
{
    int id;
    char motivo[10];
    char estado[10];
    int duracion;

} eLlamada;

mostrarLista(eAbonado abonado[],eLlamada llamada[], int tam);

finalizarLlamada(eAbonado[], eLlamada[], int);

llamadaEntrante(eAbonado[],eLlamada[], int);

cargarAbonados(eAbonado[], int);

inicializarStrcat(eAbonado[], int);

void agregarPersona(eAbonado[],int, int);

int obtenerEspacioLibre(eAbonado[], int);

mostrarAbonado(eAbonado[], int);

void modificarAbonado(eAbonado[], int);

borrarAbonado(eAbonado Abonado[], int tam);
int main()
{
    eLlamada llamada[S];
    eAbonado abonado[S];
    int flagSeguir = 1;
    int opcion;
    int espLibre;
    int i;

    inicializarStrcat(abonado, S);
    //cargarAbonados(abonado, S);

    do
    {

        printf("1.-ALTA ABONADO\n");
        printf("2.-MODIFICAR DATOS ABONADO\n");
        printf("3.-BAJA ABONADO\n");
        printf("4.-NUEVA LLAMADA\n");
        printf("5.-FIN LLAMADA\n");
        printf("6.-INFORMAR\n");
        printf("\n1.-Ingrese una opcion: \n");
        scanf("%d",&opcion);


        switch(opcion)
        {

        case 1:
            espLibre = obtenerEspacioLibre(abonado, S);
            if(espLibre != -1)
            {
                agregarPersona(abonado,espLibre,S);
            }
            else
            {
                printf("Ya no hay mas espacio!");
            }
            break;

        case 2:
            modificarAbonado(abonado, S);
            break;

        case 3:
            borrarAbonado(abonado, S);
            break;

        case 4:
            llamadaEntrante(abonado, llamada, S);
            break;

        case 5:
            finalizarLlamada(abonado,llamada,S);
            break;

        case 6:
            mostrarLista(abonado,llamada,S);
            break;

        }

    }
    while(flagSeguir == 1);

    return 0;
}


mostrarLista(eAbonado abonado[],eLlamada llamada[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(abonado[i].estado == 1 && abonado[i].id == llamada[i].id)
        {
            printf("nombre: %s, estado: %s, problema: %s",abonado[i].nombre, llamada[i].estado, llamada[i].motivo);
        }
    }
}





finalizarLlamada(eAbonado abonado[], eLlamada llamada[], int tam)
{
    int auxId;
    int i,j;
    int flag = 0;
    int flagSwitch = 0;
    int auxNum;
    int auxDuracion;
    int abonadoNum;

    printf("ID de abonados en llamada en curso: \n");

    for(i=0; i<tam; i++)
    {
        if(strcmp(llamada[i].estado,"ENCURSO") == 0 && abonado[i].estado == 1)
        {

                printf("%d\t",abonado[i].id);
                flag =1;

        }
    }

    if(flag == 1)
    {
        printf("Ingrese el ID a responder: \n");
        scanf("%d",&auxId);

        printf("\nCuanto tiempo duro la llamada?: ");
        scanf("%d",&auxDuracion);

        printf("Como resulto la llamada?(1.- SOLUCIONADO\t2.-NO SOLUCIONADO");
        scanf("%d",&auxNum);

        for(i=0;i<tam;i++)
        {
            if(auxId == abonado[i].id)
            {


             if(auxNum == 1)
        {
            strcpy(llamada[i].estado, "\0");
            strcpy(llamada[i].estado, "SOLUCIONADO");
        }else if(auxNum == 2)
        {
            strcpy(llamada[i].estado, "\0");
            strcpy(llamada[i].estado, "NOSOLUCIONADO");
        }
            }
        }


          /*while(flagSwitch == 0)
        {


                printf("Como resulto la llamada?(1.- SOLUCIONADO\t2.-NO SOLUCIONADO");
                scanf("%d",&auxNum);

                switch(auxNum)
                {
                case 1:
                    flagSwitch = 1;
                    strcpy(llamada[abonadoNum].estado, "\0");
                    strcpy(llamada[abonadoNum].estado, "SOLUCIONADO");
                    break;
                case 2:

                    flagSwitch = 1;
                    strcpy(llamada[abonadoNum].estado, "\0");
                    strcpy(llamada[abonadoNum].estado, "NOSOLUCIONADO");
                    break;

                default:
                    printf("Debe elegir una de las opciones dadas!\n");
                    flagSwitch = 0;
                    break;



            }*/
        }






}

llamadaEntrante(eAbonado abonado[], eLlamada llamada[], int tam)
{
    int auxNum;
    int auxId;
    printf("ID del abonado realizando la llamada: \n");
    scanf("%d", &auxId);
    int flag = 0;
    int flagSwitch = 0;

    int i;

    for(i=0; i<tam; i++)
    {


        while(flagSwitch == 0)
        {
            if(auxId == abonado[i].id && abonado[i].estado == 1)
            {
                strcpy(llamada[i].estado, "ENCURSO");
                llamada[i].id = auxId;
                printf("Motivo de la llamada: (1.-FALLA 3G\t2.- FALLALTE\t3.- FALLAEQUIPO)\n");
                scanf("%d",&auxNum);

                switch(auxNum)
                {
                case 1:
                    strcpy(llamada[i].motivo,"FALLA3G");
                    flagSwitch = 1;
                    strcpy(llamada[i].estado, "ENCURSO");
                    break;
                case 2:
                    strcpy(llamada[i].motivo,"FALLALTE");
                    flagSwitch = 1;
                    strcpy(llamada[i].estado, "ENCURSO");
                    break;
                case 3:
                    strcpy(llamada[i].motivo,"FALLAEQUPO");
                    flagSwitch = 1;
                    strcpy(llamada[i].estado, "ENCURSO");
                    break;
                default:
                    printf("Debe elegir una de las opciones dadas!\n");
                    flagSwitch = 0;
                    break;
                }


            }
        }


    }

}

agregarPersona(eAbonado abonado[], int espacioLibre, int tam)
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

    strcpy(abonado[espacioLibre].nombre, buffer);


    printf("Apellido de la persona: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>49)
    {
        printf("El Apellido debe contener menos de 50 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(abonado[espacioLibre].apellido, buffer);

    printf("ID del abonado: \n");
    scanf("%d", &auxId);

    for(i=0; i<tam; i++)
    {
        if(abonado[i].estado == 1)
        {
            if(auxId == abonado[i].id)
            {
                printf("Ese ID ya existe!: \n");
                scanf("%d",&auxId);
            }

        }
    }

    abonado[espacioLibre].id = auxId;

    printf("Numero del abonado: \n");
    scanf("%d", &auxNum);

    for(i=0; i<tam; i++)
    {
        if(abonado[i].estado == 1)
        {
            if(auxNum == abonado[i].numero)
            {
                printf("Ese numero ya existe!: \n");
                scanf("%d",&auxNum);
            }
        }
    }

    abonado[espacioLibre].numero = auxNum;

    abonado[espacioLibre].estado = 1;


    strcat(abonado[espacioLibre].apeNombre, abonado[espacioLibre].nombre);
    strcat(abonado[espacioLibre].apeNombre, " ");
    strcat(abonado[espacioLibre].apeNombre, abonado[espacioLibre].apellido);

    mostrarAbonado(abonado, espacioLibre);

}


borrarAbonado(eAbonado abonado[], int tam)
{
    int flagConfirmarEliminar = 0;
    int i;
    int borrar;
    char eliminar;

    printf("Ingrese el ID de la persona que quiere eliminar: ");
    scanf("%d", &borrar);

    for(i=0; i<tam; i++)
    {
        if(abonado[i].estado == 1 && abonado[i].id == borrar)
        {
            mostrarAbonado(abonado, i);
            printf("\nSeguro quiere eliminar a esta persona? (s/n)");
            eliminar = getche();
            flagConfirmarEliminar = 1;


            if(eliminar == 's')
            {
                printf("\nHa sido eliminado!");
                abonado[i].estado = 0;
                break;
            }
            else
            {
                printf("\nAccion cancelada");
                break;
            }
        }
    }

    if(flagConfirmarEliminar == 0)
    {

        printf("Ese id no existe!");
    }
}


cargarAbonados(eAbonado abonado[], int tam)
{
    int i;
    char nombres[10][50] = {"Luca","Juan","Pedro","Ivan","Roxane","Alejandro","Julian","Romero","Garcia", "Ramiro"};
    char apellidos[10][50] = {"Camaro", "Subirana", "Ford", "Maglietti", "Garcia", "Rial", "Ventura", "Schedule", "Montecarlo", "Otero"};
    int id[10] = {20,21,22,23,24,25,26,27,28,29};
    int numero[10] = {100,101,102,103,104,105,106,107,108,109};
    for(i=0; i<tam; i++)
    {
        strcpy(abonado[i].nombre, nombres[i]);
        strcpy(abonado[i].apellido, apellidos[i]);

        strcat(abonado[i].apeNombre, abonado[i].nombre);
        strcat(abonado[i].apeNombre, " ");
        strcat(abonado[i].apeNombre, abonado[i].apellido);

        abonado[i].estado = 1;
        abonado[i].id = id[i];
        abonado[i].numero = numero[i];

    }
}

inicializarStrcat(eAbonado abonado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        strcpy(abonado[i].apeNombre, "\0");
    }
}

int obtenerEspacioLibre(eAbonado abonado[], int tam)
{
    int espacioLibre;
    int i;

    for(i=0; i<tam; i++)
    {
        if(abonado[i].estado != 1)
        {
            espacioLibre = i;
            return espacioLibre;
            break;
        }
    }

    return -1;

}

mostrarAbonado(eAbonado abonado[], int abonadoNum)
{
    printf("Nombre: %s, numero: %d, ID: %d\n",abonado[abonadoNum].apeNombre, abonado[abonadoNum].numero, abonado[abonadoNum].id);
}



modificarAbonado(eAbonado abonado[], int tam)
{
    int flag = 0;
    int auxId;
    char buffer[200];
    printf("Ingrese el ID del abonado a modificar: ");
    scanf("%d", &auxId);

    int i;

    for(i=0; i<tam; i++)
    {
        if(auxId == abonado[i].id && abonado[i].estado == 1)
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

            strcpy(abonado[i].nombre, buffer);


            printf("Ingrese el nuevo apellido de la persona: \n");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer)>49)
            {
                printf("El Apellido debe contener menos de 50 caracteres: \n");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(abonado[i].apellido, buffer);


            strcpy(abonado[i].apeNombre, "\0");
            strcat(abonado[i].apeNombre, abonado[i].nombre);
            strcat(abonado[i].apeNombre, " ");
            strcat(abonado[i].apeNombre, abonado[i].apellido);

            mostrarAbonado(abonado, i);

            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Ese id no existe!");
    }


}


