#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}eMovie;


agregarPelicula(ArrayList*);
borrarPelicula(ArrayList*);
eMovie* newMovie();
modificarPelicula(ArrayList*);


#endif // _EMPLOYEE_H



