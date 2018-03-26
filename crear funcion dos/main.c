#include <stdio.h>
#include <stdlib.h>
#include "baus.h"

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;

    printf("Ingrese numero 1\n");
    scanf("%d",&numeroUno);


    printf("Ingrese numero 2\n");
    scanf("%d",&numeroDos);


    resultado = sumar(numeroUno,numeroDos);

    printf("La suma es %d", resultado);

    return 0;
}
