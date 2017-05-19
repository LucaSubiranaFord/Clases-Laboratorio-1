#include <stdio.h>
#include <stdlib.h>
#define TAM 6

eliminarUnDato(int[], int, int);

int main()
{
    int i;

    int* punt1 = (int*) malloc(sizeof(int));
    *punt1 = 1;

    int* punt2 = (int*) malloc(sizeof(int));
    *punt2 = 2;

    int* punt3 = (int*) malloc(sizeof(int));
    *punt3 = 3;

    int* punt4 = (int*) malloc(sizeof(int));
    *punt4 = 4;

    int* punt5 = (int*) malloc(sizeof(int));
    *punt5 = 5;

    int* punt6 = (int*) malloc(sizeof(int));
    *punt6 = 6;


    int array[TAM] = {*punt1, *punt2, *punt3, *punt4, *punt5, *punt6};

    printf("\nARRAY CON EL NUMERO\n");
    for(i=0; i<TAM; i++)
    {
        printf("%d\n",array[i]);
    }

    printf("\nARRAY SIN EL NUMERO\n");

    eliminarUnDato(array,TAM,2);

    return 0;
}


eliminarUnDato(int array[], int tam, int x)
{
    int i,j;
    int aux;
    int auxI;

    for(i=0; i<tam; i++)
    {
        if(array[i] == x )
        {
            auxI = i;
            break;
        }
    }


    for(i=auxI; i<(tam-1); i++)
    {
        for(j=(i+1); j<tam; j++)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            break;
        }
    }

    realloc(array,sizeof(int)*(tam-1));

    for(i=0; i<tam-1; i++)
    {
        printf("%d\n",array[i]);
    }

}
