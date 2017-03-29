#include <stdio.h>
#include <stdlib.h>

//______________________ FUNCIONES ________________
int funLegajo();
int funSueldo();
int funEdad();
char funSexo();
int porcentaje(int x, int y);

int main()
{
    // ____VARIABLES ___
    char seguir;
    int masculinos = 0;
    int femeninos = 0;
    int mascEntre = 0;
    int empleados = 0;
    int mujMayor38 = 0;
    int legajo;
    int sueldo;
    int edad;
    char sexo;
    int porcentajeMasc = 0;
    int porcentajeFem = 0;
    int sueldoTotal = 0;
    int flag = 0;
    int maxMasc = 0;
    int maxLegajo = 0;
    int maxEdadFem = 0;
    int maxLegajoFem = 0;
    int maxSueldoFem = 0;
    // ____VARIABLES ___

    do{
    empleados++;

    legajo = funLegajo();
    sueldo = funSueldo();
    edad = funEdad();
    sexo = funSexo();

    sueldoTotal += sueldo;

    if ( maxMasc < sueldo && sexo == 'm'){
        maxMasc == sueldo;
        maxLegajo = legajo;
    }

    if ( maxEdadFem < edad && sexo == 'f'){
        maxEdadFem == edad;
        maxLegajoFem = legajo;
        maxSueldoFem = sueldo;
    }

    if ( sueldo >= 2000 && sueldo <= 7500 && sexo == 'm'){
        mascEntre++;
    }

    if( sexo == 'f' && edad > 38){
        mujMayor38++;
    }

    if( sexo == 'f'){
        femeninos++;
    }else {
        masculinos++;
    }

      printf("\nDesea seguir? (s/n)\n");
      seguir = tolower(getch());
      }while( seguir == 's');


    printf("\nHay %d que ganan entre 2000 y 7500", mascEntre);
    printf("\nHay %d mujeres mayores de 38", mujMayor38);
    printf("\n El sueldo total que debera pagar la fabrica sera: %d", sueldoTotal);
    printf("\n El sueldo maximo masculino es: %d y su legajo es: %d", maxMasc, maxLegajo);

/*      porcentajeMasc = porcentaje(int masculinos, int empleados);
        porcentajeFem = porcentaje(int femeninos, int empleados);
        printf("\nHay un %d porciento de hombres y un %d porciento de mujeres", porcentajeMasc, porcentajeFem);*/

    return 0;
}

int funLegajo(){
    int x;
    do{
    printf("Ingrese el legajo (numero entre 1000 y 9999): ");
    scanf("%d", &x);
    }while(x < 1000 || x > 9999);

    return x;

}

int funSueldo(){
    int x;
    do{
    printf("Ingrese el sueldo (numero entre 1500 y 10000): ");
    scanf("%d", &x);
    }while(x < 1500 || x > 10000);
    return x;
}

char funSexo(){
    char x;
    do{
    printf("Ingrese su sexo (f/m): ");
    x = getche();
    }while( x != 'f' && x != 'm');
    return x;
}

int funEdad(){
    int x;
    do{
    printf("Ingrese su edad: ");
    scanf("%d", &x);
    }while(x < 18 || x > 65);
    return x;
}

int porcentaje(int x, int y){
   return (x * 100)/y;

}






