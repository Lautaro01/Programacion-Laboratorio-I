#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 3
#define ESC 27

int main(){
    ePersona personas[CANT];
    inicializarEstadoPersona(personas,CANT);
    int opcion = 0;

    do{
        int funcionMenu();
        switch(funcionMenu()){
            case '1':
                altaPersona(personas,CANT);
                break;
            case '2':
                bajaPersona(personas,CANT);
                break;
            case '3':
                mostrarPersonas(personas,CANT);
                break;
            case '4':
                graficoPorEdades(personas,CANT);
                break;
            case 27:
                    opcion = 'ESC';
                break;
        }
    }while(opcion != 'ESC');

    return 0;
}
