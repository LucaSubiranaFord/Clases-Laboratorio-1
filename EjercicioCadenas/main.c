#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char nombre[20], apellido[20], buffer[200];
    int i;

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





    char apeNombre[13];
    strcat(apeNombre, apellido);
    strcat(apeNombre, ", ");
    strcat(apeNombre, nombre);

    strlwr(apeNombre);



  for(i=0;i<strlen(apeNombre);i++)
    {
        if( apeNombre[i] == 32 )
        {
            apeNombre[(i+1)] = toupper(apeNombre[(i+1)]);
            break;
        }
    }

    apeNombre[0] = toupper(apeNombre[0]);

printf("%s", apeNombre);




    return 0;
}
