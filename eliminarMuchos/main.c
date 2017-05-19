#include <stdio.h>
#include <stdlib.h>
#define TAM 6

eliminarMuchos(int[], int, int);

int main()
{
    int i;

    int* punt1 = (int*) malloc(sizeof(int));
    *punt1 = 1;

    int* punt2 = (int*) malloc(sizeof(int));
    *punt2 = 4;

    int* punt3 = (int*) malloc(sizeof(int));
    *punt3 = 3;

    int* punt4 = (int*) malloc(sizeof(int));
    *punt4 = 4;

    int* punt5 = (int*) malloc(sizeof(int));
    *punt5 = 5;

    int* punt6 = (int*) malloc(sizeof(int));
    *punt6 = 4;


    int array[TAM] = {*punt1, *punt2, *punt3, *punt4, *punt5, *punt6};


    for(i=0; i<TAM; i++)
    {
        printf("%d\n",array[i]);
    }

    printf("\n//////////////////////\n");

    eliminarMuchos(array,TAM,4);

    return 0;
}


eliminarMuchos(int array[], int tam, int x)
{
    int i,j;
    int aux;
    int auxTam = 0;

    for(i=0;i<(tam-1);i++)
     {
         for(j=(i+1);j<tam;j++)
         {
             if(array[i] == x)
             {
                 aux = array[i];
                 array[i] = array[j];
                 array[j] = aux;
             }
         }
     }


     for(i=0;i<tam;i++)
     {
         if(array[i] == x)
         {
             auxTam++;
         }
     }

    realloc(array,sizeof(int)*(tam-auxTam));

    for(i=0; i<(tam-auxTam); i++)
    {
        printf("%d\n",array[i]);
    }

}
