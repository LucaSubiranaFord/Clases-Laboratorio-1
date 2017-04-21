#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char nombre[20], apellido[20], buffer[200];

    do
    {
        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(buffer);

    }while ((strlen(buffer) > 19));

    strcpy(nombre, buffer);


    do
    {

        printf("Ingrese su apellido: ");
        fflush(stdin);
        gets(buffer);

    }while ((strlen(buffer) > 19));

    strcpy(apellido, buffer);

    int i;


    if(nombre[0] >= 'a' && nombre[0] <= 'z')
    {
        nombre[0] = nombre[0] - 32 ;
    }

    for(i=1; i<strlen(nombre); i++)
    {
        if(nombre[i] >= 'A' && nombre[i] <= 'Z' )
        {
             nombre[i] = nombre[i] + 32;
            }
    }


    if(apellido[0] >= 'a' && apellido[0] <= 'z')
    {
        apellido[0] = apellido[0] - 32;
    }

    for(i=1; i<strlen(apellido); i++)
    {
        if(apellido[i] >= 'A' && apellido[i] <= 'Z' )
        {
             apellido[i] = apellido[i] + 32;
            }
    }



    char apeNombre[strlen(nombre) + strlen(apellido)];
    strcat(apeNombre, apellido);
    strcat(apeNombre, ", ");
    strcat(apeNombre, nombre);

    printf("%s", apeNombre);




    return 0;
}
