#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec1[5];

    int* vec;
    vec = (int*) malloc(5* sizeof(int)); //Mlloc va a tratar de consguir una direccion de memoria con 20 bytes

    if(vec == NULL){

        printf("No se pudo conseguir memoria");
        system("pause");
        exit(1);
    }

    for(int i=0; i<5;i++)
    {
        printf("Ingrese un un numero: ");
        scanf("%d", vec+i);
    }

    for(int i=0; i<5;i++)
    {
        printf("%d", *(vec+i));

    }

    free(vec);
    return 0;
}
