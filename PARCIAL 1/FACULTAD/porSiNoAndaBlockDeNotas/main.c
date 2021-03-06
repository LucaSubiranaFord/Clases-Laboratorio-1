#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}



//////////////////////////////////////////////////////////////


{"AHS","TBBT","TBBT","BB","FRIENDS","THM","TBBT","TWD","VIKINGS","GREYS"};
{"Luca","Juan","Pedro","Ivan","Luca","Alejandro","Julian","Romero","Garcia", "Ramiro"};
{100,101,102,103,104,105,106,107,108,109};
{20,21,22,23,24,25,26,27,28,29};
{"Camaro", "Subirana", "Ford", "Maglietti", "Garcia", "Rial", "Ventura", "Schedule", "Montecarlo", "Otero"};
{"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};




    int i;
    for(i=0; i<5; i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }


////////////////////////////////////////////////////////////



/** \brief Ingreso de un FLOAT
 *
 *\return numero ingresado (float)
 *
 */
float ingresoFloat();



/** \brief Ingreso de un INT
 *
 *\return numero ingresado (float)
 *
 */
int ingresoInt();




/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int tam);



/**\brief muestra a la persona a elegir
 * \param array de tipo ePersona
 */
mostrarPersona(ePersona lista[], int persona);



/** \brief muestra a todas las personas dadas de alta
 * \param un array de la clase ePersona
 * \param tama�o del array
 */
mostrarLista(ePersona lista[], int tam);



/** \brief Ordena los nombres en orden alfabetico
 * \param un array de la clase ePersona
 * \param tama�o del array
 */
ordenarAlfabeticamente(ePersona lista[], int tam);



/** \brief Ordena el vector en orden numeral
 * \param un array
 * \param tama�o del array
 */
ordenarNumeral(int[], int);




/** \brief BAJA a una persona
 * \param un array de la clase ePersona
 * \param tama�o del array
 */
borrarPersona(ePersona lista[], int tam);




/** \brief inicializa todos los estados en 0
 * \param un array de la clase ePersona
 * \param tama�o del array
 */
inicializarEstados(ePersona lista[], int tam);






/** \brief Busca el menos popular
 * \param array
 * \param array
 * \param array
 * \param tama�o del array
 */
serieMenosPopular(eContador[], eCliente[], eSerie[], eClienteSerie[], int);






/** \brief Agrega una persona
 * \param array
 * \param el primer espacio libre
 * \param tama�o del array
 */
agregarPersona(eAbonado abonado[], int espacioLibre, int tam)



/** \brief Obtiene el primer espacio libre de un array
 * \param array
 * \param tama�o del array
 * \return indice del espacio libre
*/

int obtenerEspacioLibre(eAbonado[], int);




/** \brief Modifica a una persona
 * \param array
 * \param tama�o del array
*/

modificarAbonado(eAbonado abonado[], int tam)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


int ingresoInt()
{

	int x;
	printf("\nIngrese un numero: ");
	scanf("%d", &x);
	return x;

}




float ingresoFloat()
{
    float x;
    printf("\nIngrese un numero: \n");
    scanf("%f", &x);
    return x;
}



int obtenerEspacioLibre(ePersona lista[], int tam)
{
    int i;
    int flag = 0;
    int espacioLibre;

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 0)
        {
            espacioLibre = i;
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        espacioLibre = -1;
    }

    return espacioLibre;
}



mostrarPersona(ePersona lista[], int persona)
{
    printf("Nombre: %s, Edad: %d, DNI: %d\n",lista[persona].nombre, lista[persona].edad, lista[persona].dni);
}




mostrarLista(ePersona lista[], int tam)
{
      int i;
     for(i=0; i<tam; i++)
            {
                if(lista[i].estado == 1)
                {
                    mostrarPersona(lista, i);
                }
            }
}




ordenarAlfabeticamente(ePersona lista[], int tam)
{
    int i, j;
    ePersona aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;

            }
        }

    }
}




ordenarNumeral(int vec[], int FIL)
{
    int i,j ;
    int aux;

        for
    (i=0; i<FIL-1; i++)
    {
        for
        (j=i+1; j<FIL; j++)
        {
            if
            (vec[i]>vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }

}



borrarPersona(ePersona lista[], int tam)
{
    int flagConfirmarEliminar = 0;
    int i;
    int borrar;
    char eliminar;

    printf("Ingrese el DNI de la persona que quiere eliminar: ");
    scanf("%d", &borrar);

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1 && lista[i].dni == borrar)
        {
            mostrarPersona(lista, i);
            printf("\nSeguro quiere eliminar a esta persona? (s/n)");
            eliminar = getche();
            flagConfirmarEliminar = 1;


            if(eliminar == 's')
            {
                printf("\nHa sido eliminado!");
                lista[i].estado = 0;
                break;
            }
            else
            {
                printf("\nAccion cancelada");
                break;
            }
        }

    }





inicializarEstados(ePersona lista[], int tam)
{

int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = 0;
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


//////////////////////////////////////////DOBLE ESTRUCTURA ///////////////////////////////////////////////

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





////////////////////////////////CONTADOR MAS SENCILLO //////////////////////////////////
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




////////////////////////////////////////








int flagSeguir = 0;
    int opcion;
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

            break;
        case 2:

            break;
        case 3:

            break;
            case 4:

            break;
            case 5:

            break;
            case 6:

            break;
        default:
                printf("\nIngrese una opcion correcta!\n");
            break;
        }

    }











////////////////////////////////////////////////





while()
        {



                switch()
                {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                default:

                    break;
                }



        }



/////////////////////////////////////
   for(i=0; i<tam; i++)
    {
        while()
        {

        }
    }


////////////////////

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#endif
