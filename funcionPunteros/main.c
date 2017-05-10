#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[5];
    int* p;
    p = x;
    int i,j;
    int* aux;

    for(i=0; i<7; i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d", (p+i));
    }

    for(i=0; i<6; i++)
    {
        for(j=(i+1); j<7; j++)
        {
            if(p+i > p+j)
            {


                aux = (p+i);
                (p+i) = (p+j);
                (p+j) = (aux);
            }
        }
    }


    for(i=0; i<5; i++)
    {
        printf("%d\n",*(p+i));
    }

    return 0;
}
