#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int x[]={34,14,23,12,7};

    int c;

    printf("0 para ordenar de menor a mayor, 1 para mayor a menor: ");
    scanf("%d",&c);


    ordenar(x,5,c);

    mostrarVector(x,5);

    return 0;
}
