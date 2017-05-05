#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 7;
    int* otro;
    int* punt; //DECLARAMOS EL PUNTERO
    punt=&a; //ASIGNAMOS LA DIRECCION DE MEMORIA DE LA VARIABLE "a" EN EL PUNTERO


    printf("%p",&a); //MUESTRO LA DIRECCION DE MEMORIA DE "a"
    printf("\n%p", punt); // MUESTRO LA DIRECCION DE MEMORIA DE puntero, que va ser la misma que la de "a"
    printf("\n//////////////\n");
    printf("%d\n", a); //VARIABLE NORMAL
    printf("%d\n", *punt); //VARIABLE QUE SE LE ASIGNO AL PUNTERO
    printf("%p",&punt); //DIRECCION DE MEMORIA QUE TIENE LA VARIABLE PUNTERO(DISTINTA A LAS DEMAS)
    printf("\n//////////////\n");
    otro = punt;
    printf("%d",*otro); //APUNTA AL MISMO LUGAR QUE PUNT.
    printf("\n%d",*punt);
    printf("\n//////////////\n");



    /////////////////////////////////////ARITMETICA DE PUNTEROS/////////////////////////////////////////////////////


    //punt = punt +1 lo mismo que punt++
    printf("\%p", punt); // MUSTRA LA DIRECCION DE MEMORIA DE LA VARIABLE "a"
    printf("\n%p", punt+1); // LE ESTOY SUMANDO 4 BITS QUE ES LO QUE VALE EL ENTERO. DIRECCION DE MEMORIA DE LA VARIABLE "a" + 1

    // if(punt < otro) -- si la direccion de memoria de PUNT es menor a la direccion de memoria de OTRO. En este caso, es falso porque son iguales !!
    // if(punt == &a) -- SI TIENEN LA MISMA DIRECCION DE MEMORIA .. LO CUAL ES VERDAD.


    return 0;
}
