#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
    Puntero: guarda la direccion de memoria (ej: dx288ff1c)
    para declarar una variable que guarde una direccion de memoria es

    int* x;
    char* x;
    float* x;

    *puntero: tiene el contenido de la direccion de memoria, ej

    int x=5;

    &=Operador de direccion
    *= operador de indireccion

    printf("%p", );


    */


    int vec[5];



    //1era funcion: Recibe el array como vector y accede a los datos utilizando notación vectorial ([])

    void motrarVecUno(int vec[], int tam){

        for(int i=0; i<tam;i++){
        scanf("%d", &vec[i]));
        }

        for(int i=0; i<tam;i++){
        printf("%d", vec[i]);
        }
    }

    //2da funcion: Recibe el array como vector y accede a los datos utilizando aritmetica de punteros

        void motrarVecDos(int vec[], int tam){

        for(int i=0; i<tam;i++){
        scanf("%d", &vec[i]));
        }

        for(int i=0; i<tam;i++){
        printf("%d", vec+1);
        }
    }

    //3era funcion: Recibe el array como puntero y accede a los datos utilizando notación vectorial ([])

    void motrarVecDos(int* vec, int tam){

        for(int i=0; i<tam;i++){
        scanf("%d", &vec[i]));
        }

        for(int i=0; i<tam;i++){
        printf("%d", vec[i]);
        }
    }

    // 4da funcion: Recibe el array como puntero y accede a los datos utilizando aritmetica de punteros

    void motrarVecDos(int* vec[], int tam){

        for(int i=0; i<tam;i++){
        scanf("%d", &vec[i]));
        }

        for(int i=0; i<tam;i++){
        printf("%d", vec+1);
        }
    }


    return 0;
}
