#include <stdio.h>
#include <stdlib.h>

//LOS VECTORES SIEMPRE REPRESENTAN UNA DIRECCION DE MEMORIA YA DE POR SI

int main()
{
    /*int x[5]; //CADA SUBINDICE REPRESENTA UNA DIRECCION DE MEMORIA DISTINTA.
    int* p;
    x[0] = 9;
    x[1] = 1;
    x[2] = 5;
    x[3] = 6;
    x[4] = 8;

    // p = &x[0];el puntero p apunta a la direccion de memoria de x[0] . NO USO ESTA PORQUE ES NOTACION DE VECTORES
    // Tambien podria poner p = &x; el cual apunta a la direccion de memoria del primer elemento. NO USO ESTA PORQUE LE REPITO QUE ME PASE LA DIRECCION DE MEMORIA DE LA DIRECCION DE MEMORIA
    // tambien puedo poner p = x; HAY QUE USAR ESTA QUE ES LA MEJOR, LOS VECTORES YA REPRESENTAN UNA DIRECCION DE MEMORIA YA DE POR SI.

   *p = 1;//ESTOY MODIFICANDO EL SEGUNDO VALOR DEL ARRAY, QUE SERIA x[0]
   *(p+1) = 3; //ESTOY MODIFICANDO EL SEGUNDO VALOR DEL ARRAY, QUE SERIA x[1]
   *(p+2) = 7; //ESTOY MODIFICANDO EL SEGUNDO VALOR DEL ARRAY, QUE SERIA x[2]*/


   int x[5];
   int* p;
   p=x;
   int i;

   for(i=0;i<5;i++) // CARGA SECUENCIAL PARA INICIAR TODO EL VECTOR EN 0 ..
   {
       *(p+i) = 0;
   }
   for(i=0;i<5;i++)
   {
       printf("\n%d", *(p+i));
   }


    return 0;
}
