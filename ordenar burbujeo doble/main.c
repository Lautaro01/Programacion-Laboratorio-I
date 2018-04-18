#include <stdio.h>
#include <stdlib.h>
#define CANT 3

/*

copiar un vector a otro

char n1[30]="jose";
char n2[30];

n2=n1;   XmalX por que es una cadena de caracteres, no se puede, pero si es un numero si.

strcpy(n2,n1); ☺bien☺ usar esto es lo mismo que =

for (i=0;i<30;i++)
{
n2[i]=n1[1]
}

*/
typedef struct{
    int dia,mes,anio; //no se pusar la ñ
}eFecha;

typedef struct{
    char nombre[21];
    int legajo;
    float sueldo;
    char sexo;
    eFecha fn;

    /*fecha de nacimiendo, una estructura
    dentro de otra, puedo hacer mas eFechas para distintas
    cosas, ej: eFecha jubilacion.*/

}eEmpleado;

int main()
{
/*emp.nombre;
emp.legajo;
emp.fm.dia;*/

/*ordenar por sueldo de mayor a menor con un burbujeo.
el emp, con el mayor sueldo va a ordenarse primero,
todos sus datos no solo el salario, todo anidado (?*/

eEmpleado emp [CANT],aux;


for(int i=0;i<CANT-1;i++){
    for(int j=i+1; j<CANT; j++){
        if(emp[i].sueldo < emp[j].sueldo){
            aux= emp[i];
            emp[i] = emp[j];
            emp[j] = aux;
        }
        else{
            if(emp[i].sueldo == emp[j].sueldo){
             if(strcmp(emp[i].nombre,emp[j].nombre)>0){
                 aux= emp[i];
                emp[i] = emp[j];
                emp[j] = aux;
             }
            }
        }
    }
}




    return 0;
}
