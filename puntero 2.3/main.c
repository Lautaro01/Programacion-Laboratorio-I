#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nombre[21];
    int nota;
}ePersona;

int main()
{
ePersona pers[3];
ePersona* ptrPers;
ptrPers = pers;

for(int i=0;i<3;i++){
    printf("Ingrese nombre: ");
    scanf("%s", (ptrPers+i)->nombre);
    system("cls");
}
for(int i=0;i<3;i++){
    printf("Ingrese Nota: ");
    scanf("%d", &(ptrPers+i)->nota);
    system("cls");
}
for(int i=0;i<3;i++){
printf("%d\n", (ptrPers+i)->nota);
}
for(int i=0;i<3;i++){
printf("%s\n", (ptrPers+i)->nombre);
}

//Notacion de puntero
for(int i=0;i<3;i++){
    printf("Ingrese nombre: ");
    scanf("%s", (*(ptrPers+i)).nombre);
}
for(int i=0;i<3;i++){
    printf("\nIngrese Nota: ");
    scanf("%d", &(*(ptrPers+i)).nota);
}



    return 0;
}
