#include <stdio.h>
#include <stdlib.h>
#define S 10
#include <string.h>

typedef struct
{
    int id;
    int horario;
    char aerOrigen[10][50];
    char aerDestino[10][50];
    int estado;

} eVuelos;


typedef struct
{
    int matricula;
    char fabricante[10][50];
    char modelo[10][50];
    int capacidad;
    int autonomia;
    int estado;
} eAviones;

typedef struct
{
    int contador;
    int idAvion;

} eContador;

mayorCantVuelos(eAviones[], eVuelos[], eContador[], int);
altaAvion(eAviones[],int, int);
obtenerEspacioLibre(eAviones[], int);
mostrarAvion(eAviones[], int);
inicializarEstadosAvion(eVuelos[], eAviones[], int);
cargarAviones(eAviones[], int);
modificarAvion(eAviones[], int);
bajaAvion(eAviones[], int);
nuevoVuelo(eContador[], eAviones[],eVuelos[], int);
inicializarIdVuelos(eVuelos[], int);
suspenderVuelo(eAviones[], eVuelos[], int);
inicializarContador(eContador[], eAviones[], int);


int main()
{
    eContador contador[S];
    eAviones avion[S];
    eVuelos vuelo[S];
    int flagSeguir = 0;
    int opcion;
    int espLibre;
    inicializarEstadosAvion(vuelo, avion, S);
    cargarAviones(avion,S);
    int flagIngreso = 0;
    int i, j;
    inicializarIdVuelos(vuelo, S);
    inicializarContador(contador, avion, S);

    while(flagSeguir == 0)
    {

        printf("1.-ALTAS AVION\n");
        printf("2.-MODIFICAR DATOS AVION\n");
        printf("3.-BAJA AVION\n");
        printf("4.-NUEVO VUELO\n");
        printf("5.-SUSPENDER VUELO\n");
        printf("6.-LISTAR\n");
        printf("\n1.-Ingrese una opcion: \n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            flagIngreso = 1;
        espLibre = obtenerEspacioLibre(avion, S);
        if(espLibre != -1)
        {
            altaAvion(avion, espLibre, S);
        }else
        {
            printf("No queda espacio!");
        }
            break;
        case 2:

            if(flagIngreso == 1)
            {
                modificarAvion(avion, S);
            }
            break;
        case 3:
                if(flagIngreso == 1)
            {
                bajaAvion(avion, S);
            }
            break;
            case 4:
                  if(flagIngreso == 1)
            {
                nuevoVuelo(contador, avion, vuelo, S);
            }


            break;
            case 5:
            suspenderVuelo(avion, vuelo, S);
            break;
            case 6:
       mayorCantVuelos(avion, vuelo, contador, S);
            break;
        default:
                printf("\nIngrese una opcion correcta!\n");
            break;
        }

    }
    return 0;
}

inicializarContador(eContador contadorr[], eAviones avion[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        contadorr[i].contador = 0;
        contadorr[i].idAvion = avion[i].matricula;
    }
}

mayorCantVuelos(eAviones avion[], eVuelos vuelo[], eContador contador[], int tam)
{
    int i;

    int auxMax = contador[0].contador;
    int auxIdAvion = contador[0].idAvion;

    for(i=0; i<tam; i++)
    {
        if(contador[i].contador > auxMax)
        {
            auxMax = contador[i].contador;
            auxIdAvion = contador[i].idAvion;
        }
    }

    for(i=0; i<tam; i++)
    {
        if(auxIdAvion == avion[i].matricula)
        {
            printf("%d\n", avion[i].matricula);
        }
    }

}

suspenderVuelo(eAviones avion[], eVuelos vuelo[], int tam)
{
      int flagConfirmarEliminar = 0;
    int i;
    int borrar;
    int borrar2;
    char eliminar;

    printf("Ingrese el ID del vuelo que quiere cancelar: ");
    scanf("%d", &borrar);

      for(i=0; i<tam; i++)
    {
        while(vuelo[i].id != borrar)
        {
            printf("ID equivocado: ");
            scanf("%d", &borrar);
        }
    }

     printf("Ingrese la matricula del avion: ");
    scanf("%d", &borrar2);

      for(i=0; i<tam; i++)
    {
        while(avion[i].matricula != borrar2)
        {
            printf("Matricula equivocada: ");
            scanf("%d", &borrar2);
        }
    }

    for(i=0; i<tam; i++)
    {
        if(vuelo[i].id == borrar)
        {
            mostrarAvion(avion, i);
            printf("\nSeguro quiere cancelar su vuelo (s/n)");
            eliminar = getche();
            flagConfirmarEliminar = 1;


            if(eliminar == 's')
            {
                printf("\nHa sido eliminado!");
                vuelo[i].estado = 0;
                break;
            }
            else
            {
                printf("\nAccion cancelada");
                break;
            }
        }
}
}

inicializarIdVuelos(eVuelos vuelo[], int tam)
{
    int idVuelos[10][5] = {500,501,502,503,504,505,506,507,508,509};
    int i;
    for(i=0; i<tam; i++)
    {
        vuelo[i].id = idVuelos[i];
    }

}

nuevoVuelo(eContador contadorr[],eAviones avion[], eVuelos vuelo[], int tam)
{
    char buffer[200];
    int auxMat;
    int i,j;
     printf("Ingrese la matricula del avion al que quiere ingresar: \n");
    scanf("%d", &auxMat);

    for(i=0; i<tam; i++)
    {
        if(avion[i].estado == 1 && avion[i].matricula == auxMat)
        {
            for(j=0;j<tam;j++)
            {
                if(contadorr[j].idAvion == avion[i].matricula)
                {
                    contadorr[j].contador++;
                }
            }
          vuelo[i].estado = 1;
           printf("Ingrese un horario: \n");
           scanf("%d", &vuelo[i].horario);

            printf("Ingrese el destino: \n");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer)>49)
            {
                printf("El pais de destino debe tener menos de 50 caracteres: \n");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(vuelo[i].aerDestino, buffer);


             printf("Ingrese el origen: \n");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer)>49)
            {
                printf("El pais de origen debe tener menos de 50 caracteres: \n");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(vuelo[i].aerOrigen, buffer);

            printf("Usted se registro en el avion: \n");
            mostrarAvion(avion, i);

        }
}
}

bajaAvion(eAviones avion[], int tam)
{
     int flagConfirmarEliminar = 0;
    int i;
    int borrar;
    char eliminar;

    printf("Ingrese la matricula del avion que quiere eliminar: ");
    scanf("%d", &borrar);

    for(i=0; i<tam; i++)
    {
        if(avion[i].estado == 1 && avion[i].matricula == borrar)
        {
            mostrarAvion(avion, i);
            printf("\nSeguro quiere eliminar a este avion? (s/n)");
            eliminar = getche();
            flagConfirmarEliminar = 1;


            if(eliminar == 's')
            {
                printf("\nHa sido eliminado!");
                avion[i].estado = 0;
                break;
            }
            else
            {
                printf("\nAccion cancelada");
                break;
            }
        }
}
}

modificarAvion(eAviones avion[], int tam)
{
    int flag = 0;
    int auxMat;
    char buffer[200];
    printf("Ingrese la matricula del avion a modificar: ");
    scanf("%d", &auxMat);

    int i;

    for(i=0; i<tam; i++)
    {
        if(auxMat == avion[i].matricula && avion[i].estado == 1)
        {

            printf("Ingrese el nuevo fabricante: \n");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer)>49)
            {
                printf("El fabricante debe contener menos de 50 caracteres: \n");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(avion[i].fabricante, buffer);


            printf("Ingrese el nuevo modelo del avion: \n");
            fflush(stdin);
            gets(buffer);

            while(strlen(buffer)>49)
            {
                printf("El modelo debe contener menos de 50 caracteres \n");
                fflush(stdin);
                gets(buffer);
            }

            strcpy(avion[i].modelo, buffer);

            printf("Ingrese la nueva autonomia del avion: \n");
            scanf("%d",&avion[i].autonomia);

            printf("Ingrese la nueva capacidad del avion: \n");
            scanf("%d",&avion[i].autonomia);


            mostrarAvion(avion, i);

            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Esa matricula no existe!");
    }


}




altaAvion(eAviones avion[],int espacioLibre, int tam)
{
    int auxNum;
    int auxMat;
    int buffer[200];
    int i;

    printf("Fabricante del avion: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>49)
    {
        printf("El fabricante debe contener menos de 50 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(avion[espacioLibre].fabricante, buffer);


    printf("Modelo del avion: \n");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>49)
    {
        printf("El modelo debe contener menos de 50 caracteres: \n");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(avion[espacioLibre].modelo, buffer);

    printf("Matricula del avion: \n");
    scanf("%d", &auxMat);

    for(i=0; i<tam; i++)
    {
        if(avion[i].estado == 1)
        {
            if(auxMat == avion[i].matricula)
            {
                printf("Esa matricula ya existe!: \n");
                scanf("%d",&auxMat);
            }

        }
    }

    avion[espacioLibre].matricula = auxMat;

    printf("Capacidad maxima: \n");
    scanf("%d", &avion[espacioLibre].capacidad);

    printf("Autonomia de vuelo: \n");
    scanf("%d", &avion[espacioLibre].autonomia);

    avion[espacioLibre].estado = 1;



    mostrarAvion(avion, espacioLibre);

}


obtenerEspacioLibre(eAviones avion[], int tam)
{
    int espacioLibre;
    int i;

    for(i=0; i<tam; i++)
    {
        if(avion[i].estado != 1)
        {
            espacioLibre = i;
            return espacioLibre;
            break;
        }
    }

    return -1;

}

mostrarAvion(eAviones avion[], int avionNum)
{
    printf("Matricula: %d, Fabricante: %s, Modelo: %s, Capacidad: %d, Autonomia: %d\n",avion[avionNum].matricula,avion[avionNum].fabricante, avion[avionNum].modelo, avion[avionNum].capacidad, avion[avionNum].autonomia);
}

inicializarEstadosAvion(eVuelos vuelo[],eAviones avion[], int tam)
{
   int i;
    for(i=0; i<tam; i++)
    {
        vuelo[i].estado = 0;
        avion[i].estado = 0;
    }
}


cargarAviones(eAviones avion[], int tam)
{

  char modelo[10][50] = {"AHS","TBBT","TBBT","BB","FRIENDS","THM","TBBT","TWD","VIKINGS","GREYS"};
  char fabricante[10][50] = {"Luca","Juan","Pedro","Ivan","Luca","Alejandro","Julian","Romero","Garcia", "Ramiro"};
    int capacidad[10] = {100,101,102,103,104,105,106,107,108,109};
    int autonomia[10] = {20,21,22,23,24,25,26,27,28,29};
    int matricula[10] = {45,46,47,48,49,50,51,52,53,54};
    int i;

    for(i=0; i<tam; i++)
    {
        avion[i].capacidad = capacidad[i];
        avion[i].autonomia = autonomia[i];
        avion[i].matricula = matricula[i];
        strcpy(avion[i].modelo, modelo[i]);
        strcpy(avion[i].fabricante, fabricante[i]);
        avion[i].estado = 1;
    }
}
