#include <stdio.h>
#include <stdlib.h>

/* ingreso un numero pero en un tipo char, osea una cadena, despues verifico que no esa cadena solo tenga
numeros con el for, si hay una letra (lo verifico usando is digit) usa el flag para informarlo, y si
todo lo que pase fue un numero, con atoi (as to int) paso ese chat a un int */

int main()
{
int numero;
int flag = 0;
char dato[15];
printf("ingrese un numero: ");
fflush(stdin);
scanf("%s",dato);

    for(int i=0;i<strlen(dato);i++)     /* isdigit espera un chat, y es un un numero devuelve un 1*/
    {
        if(!isdigit(dato[i])) //si el primer dato no es no dijito entra por eso el ! para negar
        {
            flag=1;
            break;
        }
    }

    if(flag == 0)
    {
        numero = atoi(dato);
        printf("%d",numero);    //atoi pasa de una cadena de catactares a un numero
    }

    else
    {
        printf("bobo ingresa un numero sin letras pls xd");
    }


    return 0;
}
