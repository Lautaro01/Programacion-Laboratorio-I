#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;

    int n,cant;
    char nombre[20];
    char apellido[20];
    char letra;

    f = fopen("numeros.txt","r");
    if(f == NULL)
    {
        printf("ERROR! no se pudo abrir el archivo");
        system("pause");
        exit(EXIT_FAILURE);
    }

    while(!feof(f))
    {
        cant = fscanf(f," %s, %s, %c, %d\n",nombre,apellido,&letra,&n);

        printf("%d",cant);

        if(cant != 1){
            if(feof(f)){
             break;
            }
            else
            {
            printf("Error txt\n\n");
            system("pause");
            exit(EXIT_FAILURE);
            }
        }

        printf("%s,%s,%c,%d\n",nombre,apellido,letra,n);
    }
    return 0;
}
