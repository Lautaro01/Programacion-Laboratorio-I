#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    ePelicula* pPelicula;
    int retorno;
    int contadorDePeliculas=0;
    int* pContador = &contadorDePeliculas;
    cargarPelicula(pPelicula,pContador);
    pPelicula = (ePelicula*)malloc(sizeof(ePelicula)*(contadorDePeliculas+1));
    if(pPelicula != NULL)
    {
        strcpy(pPelicula->titulo,"");
        strcpy(pPelicula->genero,"");
        pPelicula->duracion = 0;
        strcpy(pPelicula->descripcion,"");
        pPelicula->estado = 0;
        pPelicula->puntaje = 0;
        strcpy(pPelicula->linkImagen,"");
    }




    while(seguir=='s')
    {
        system("cls");
        printf("\t M e n u  P e l o c u l a s\n\n");
        printf("Cantidad de peliculas: %d\n",contadorDePeliculas);
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        printf("\n\nIngrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                retorno=agregarPelicula(pPelicula,contadorDePeliculas,pContador);
                if(retorno == 0)
                    contadorDePeliculas++;


                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
            default:
                printf("Error! ingrese una opcion valida\n\n");
                system("pause");
                break;
        }
    }

    return 0;
}
