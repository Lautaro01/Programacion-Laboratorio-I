#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    char opcion=0;
    int numeroA=0;
    int numeroB=0;
    int resultado=0;
    float resultadoDivision=0;


    while(seguir=='s')
    {

        printf("[1]-Ingresar numero A \n");
        printf("[2]-Ingresar numero B \n");
        printf("[3]-Sumar A + B \n");
        printf("[4]-restar A - B \n");
        printf("[5]-Dividir A / B \n");
        printf("[6]-Multiplicar A * B \n");
        printf("[7]-Calcular el factorial de A!\n");
        printf("[8]-Todas las operaciones! \n");
        printf("[9]-Salir \n");
        printf("[c]-Limpiar A y B!\n");
        printf("----------------------------------------\n");
        printf("A=%d  B=%d\n",numeroA,numeroB);
        printf("----------------------------------------\n");
        opcion = getch();

        switch(opcion)
        {
            case '1':

                printf("ingrese el numero A: ");
                scanf("%d", &numeroA);
                system("cls");
                break;

            case '2':

                printf("ingrese el numero B: ");
                scanf("%d", &numeroB);
                system("cls");
                break;

            case '3':

                resultado = suma(numeroA, numeroB);
                printf("El resultado de la suma es: %d+%d=%d\n",numeroA,numeroB,resultado);
                system("pause");
                system("cls");
                break;

            case '4':

                resultado = resta(numeroA, numeroB);
                printf("El resultado de la resta es: %d-%d=%d\n",numeroA,numeroB,resultado);
                system("pause");
                system("cls");
                break;

            case '5':

                if(numeroB == 0)
                {
                    printf("ERROR! No se puede dividir por cero!\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                resultadoDivision = division(numeroA, numeroB);
                printf("El resultado de la division es: %d/%d= %.2f\n",numeroA,numeroB,resultadoDivision);
                system("pause");
                system("cls");
                }
                break;

            case '6':

                resultado = mulplicacion(numeroA, numeroB);
                printf("El resultado de la multiplicacion es: %d*%d=%d\n",numeroA,numeroB,resultado);
                system("pause");
                system("cls");
                break;

            case '7':

                resultado = factorial(numeroA);
                printf("El resultado del factorial es: %d!=%d\n",numeroA,resultado);
                system("pause");
                system("cls");
                break;

            case '8':

                resultado = suma(numeroA, numeroB);
                printf("El resultado de la suma es: %d+%d=%d\n",numeroA,numeroB,resultado);
                resultado = resta(numeroA, numeroB);
                printf("El resultado de la resta es: %d-%d=%d\n",numeroA,numeroB,resultado);
                if(numeroB == 0)
                {
                    printf("ERROR! No se puede dividir por cero!\n");
                }
                else
                {
                resultadoDivision = division(numeroA, numeroB);
                printf("El resultado de la division es: %d/%d= %.2f\n",numeroA,numeroB,resultadoDivision);
                }

                resultado = mulplicacion(numeroA, numeroB);
                printf("El resultado de la multiplicacion es: %d*%d=%d\n",numeroA,numeroB,resultado);
                resultado = factorial(numeroA);
                printf("El resultado del factorial es: %d!=%d\n",numeroA,resultado);

                system("pause");
                system("cls");

                break;
            case '9':
                seguir = 'n';
                break;
            case 'c':
                numeroA = 0;
                numeroB = 0;
                system("cls");
                break;
        }

    }

    return 0;
}
