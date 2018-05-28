#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct{
    int legajo;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;

void mostrarEmpleado(eEmpleado*);
void mostrarEmpleados(eEmpleado*,int tam);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int,char*,float);
eEmpleado* newArrayEmpleados(int tam);

int main()
{
    FILE* archivo;
    eEmpleado* empleado;
    empleado = newEmpleadoParam(32,"pepe",12000);
    mostrarEmpleado(empleado);
    archivo = fopen("empleado","wb");

    if(archivo==NULL)
    {
        printf("No se pudo abrir el archivo");
        system("pause");
        exit(1);
    }
    return 0;
}

eEmpleado* newEmpleado()
{
    eEmpleado* x;
    x = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(x != NULL)
    {
        x->legajo = 0;
        strcpy(x->nombre,"");
        x->sueldo=0;
        x->estado=0;
    }

  return x;
};

eEmpleado* newEmpleadoParam(int legajo,char* nombre,float sueldo)
{
    eEmpleado* nuevoEmp;
    nuevoEmp = newEmpleado();

    if(nuevoEmp != NULL)
    {
        nuevoEmp->legajo=legajo;
        nuevoEmp->sueldo=sueldo;
        strcpy(nuevoEmp->nombre,nombre);
        nuevoEmp->estado=0;
    }
    return nuevoEmp;
}


void mostrarEmpleado(eEmpleado* emp)
{
    if(emp != NULL)
    {
      printf("  %d     %s    %0.2f\n", emp->legajo, emp->nombre, emp->sueldo);
    }

}

void mostrarEmpleados(eEmpleado* emp, int tam)
{
    system("cls");
    printf("---Lista de Empleados---\n\n");
    printf("  Legajo  Nombre   Sueldo  \n\n");
    for(int i=0; i< tam; i++)
    {
        if(emp != NULL)
        {
          if((emp+i)->estado)
            {
                mostrarEmpleado(emp+i);
            }
        }

    }
}

void inicializarEmpleados(eEmpleado* empleados, int tam)
{
    if(empleados != 0 && tam > 0)
      for(int i=0; i< tam; i++)
    {
       (empleados+i)->estado = 0;
    }
}

eEmpleado* newArrayEmpleados(int tam)
{
eEmpleado* array;

if(tam > 0)
{
    array = (eEmpleado*) malloc(tam * sizeof(eEmpleado));

    if(array != NULL)
    {
        inicializarEmpleados(array, tam);
    }
}

return array;
}
