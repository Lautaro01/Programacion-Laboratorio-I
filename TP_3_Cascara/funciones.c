#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



int buscarPorTitulo(ePelicula* pelicula,int cantidadPeliculas,char* titulo){
int existe = 0;
for(int i=0;i<cantidadPeliculas;i++)
{
    if(stricmp((pelicula+i)->titulo,titulo) == 0 && (pelicula+i)->estado == 1){
        existe = 1;
        break;
        }
}
return existe;
}

int agregarPelicula(ePelicula* pelicula,int cantidadPeliculas,int* pContador){

char auxTitulo[50];
char auxGenero[100];
//int duracion;
//char descripcion[100];
int numeroDeLetras;
char respuesta;
int retornar;

system("cls");
printf("\t Agregar Pelicula\n\n");
printf("Ingrese los siguientes datos para agregar la pelicula: \n");
printf("Titulo: ");
fflush(stdin);
scanf("%[^\n]", auxTitulo);
int existe = buscarPorTitulo(pelicula,cantidadPeliculas,auxTitulo);

while(existe == 1)
{
    printf("\nError! el titulo ya existe, ingrese otro: ");
    fflush(stdin);
    scanf("%[^\n]", auxTitulo);
    system("pause");
    existe = buscarPorTitulo(pelicula,cantidadPeliculas,auxTitulo);
}


printf("Ingrese genero: ");
fflush(stdin);
scanf("%[^\n]", auxGenero);
numeroDeLetras = strlen(auxGenero);

while(numeroDeLetras < 0 && numeroDeLetras > 20)
    {
        printf("Error! el genero es muy largo, ingrese otro: ");
        fflush(stdin);
        scanf("%[^\n]", auxGenero);
        system("pause");
        numeroDeLetras = strlen(auxGenero);
    }

strcpy(pelicula->titulo,auxTitulo);
strcpy(pelicula->genero,auxGenero);
pelicula->estado=1;


retornar= guardarPelicula(pelicula,cantidadPeliculas,pContador);

    if(!retornar)
    {
        printf("\n Se an guardado los datos con exito!");
        system("pause");
        return 0;
    }
    else
    {
        printf("\nNo se an podido guardar los datos");
        system("pause");
        return 1;
    }


}

int guardarPelicula(ePelicula* pelicula,int contador, int* pContador)
{

    FILE* f;
    f = fopen("listaDePeliculas", "wb");

    if(f != NULL)
    {
        if(pelicula->estado)
        {
            fwrite(pelicula,sizeof(ePelicula),contador,f);
            fwrite(pContador,sizeof(int),1,f);
            fclose(f);
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

int cargarPelicula(ePelicula* pelicula,int* pContador)
{
    int flag=0;
    FILE *f;
    f=fopen("listaDePeliculas","rb");

    if(f==NULL)
    {
        f=fopen("listaDePeliculas","wb");

        if(f==NULL)
        {
            return 0;
        }

        flag=1;
    }

    if(!flag)
    {
        fread(pContador,sizeof(int),1,f);

        while(!feof(f))
        {
            fread(pelicula,sizeof(ePelicula),*pContador,f);
        }
    }

    fclose(f);
    return 1;
}



