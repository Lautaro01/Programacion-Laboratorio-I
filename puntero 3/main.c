#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* pNum;
    pNum = (int*) malloc(sizeof(int));

    if(pNum == NULL){

        printf("No se pudo conseguir memoria");
        exit(1);
    }

    printf("Ingerse un numero: ");
    scanf("%d", pNum);

    printf(" %d\n\n", *pNum);

    free(pNum); // Libera el espacio de memoria
    return 0;
}
