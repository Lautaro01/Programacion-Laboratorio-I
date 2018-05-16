#include <stdio.h>
#include <stdlib.h>

int main()
{
struct alumno{
char nombre[20];
int nota;
};

struct alumno auxiliarAlumno;

struct alumno* punteroAlumno;

punteroAlumno = &auxiliarAlumno;


//Pedir datos con -> en una estructura

//Cadena de caracteres
printf("Ingrese nombre: ");
scanf("%s", punteroAlumno->nombre);
printf("%s", punteroAlumno->nombre);

//Numeros
printf("\nIngrese Nota: ");
scanf("%d", &punteroAlumno->nota);
printf("%d", punteroAlumno->nota);


//Pedir datos con *


//Cadena de caracteres
printf("\nIngrese nombre: ");
scanf("%s", (*punteroAlumno).nombre);
printf("%s", (*punteroAlumno).nombre);

//Numero
printf("\nIngrese Nota: ");
scanf("%d", &(*punteroAlumno).nota);
printf("%d", (*punteroAlumno).nota);





    return 0;
}
