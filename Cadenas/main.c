#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[200], nombre[20], apellido[20];
    int comp;
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>19)
    {
        printf("Reingrese un nombre mas corto: ");
        fflush(stdin);
        gets(buffer);

    }

    strcpy(nombre,buffer);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>19)
    {
        printf("Reingrese un apellido mas corto: ");
        fflush(stdin);
        gets(buffer);

    }

    strcpy(apellido,buffer);

   strcpy(buffer,apellido);
    strcat(buffer," ");
    strcat(buffer,nombre);
    printf("Su apellido y nombre es: %s", buffer);


    /* comp = strcmp(nombre, "GERMAN");

     if(comp==0)
     {
         printf("Ud se llama german");

     }
     else
     {
         printf("Ud no se llama german");
     }
    */



    return 0;
}
