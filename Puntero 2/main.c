#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cod[]={"hola"};
    mostrarCadena(cod);

    char cad[51];
    strcpy(cad, getChax());
    printf("%S",cad);
    return 0;
}

void mostrarCadena(char *punteroCadena){

    while(*punteroCadena != '\0'){
        printf("%c", *punteroCadena);
        punteroCadena++;
    }

}

char *getChax(void){
    char letra[]={"abc"};
    return letra;
}

/*
struct alumno {
char nombre[20];
int nota;
};

struct alumno auxiliarAlumno;
struct* punteroAlumno;
punteroAlumno = &auxiliarAlumno;

*(punteroAlumno).nota == auxiliar[].nota

*/
