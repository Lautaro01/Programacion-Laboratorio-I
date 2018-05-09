#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include <ctype.h>
#define CANT 3

void inicializarEstadoPersona(ePersona pers[],int cantidad){
    for(int i=0;i<cantidad;i++)
{
    pers[i].estado = 0;
}
}

int funcionMenu(){
        int opcion;
        system("cls");
        printf("\t---T r a b a j o   p r a c t i c o N.2---\n\n");
        printf("1-Agregar una persona\n");
        printf("2-Borrar una persona\n");
        printf("3-Imprimir lista ordenada por nombre\n");
        printf("4-Grafico\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        opcion = getch();

        return opcion;
};

int obtenerEspacioLibre(ePersona pers[],int cantidad){
int indice = -1;
for(int i=0;i<cantidad;i++){
    if(pers[i].estado == 0){
        indice =i;
        break;
        }
}
return indice;
}

int buscarPorDni(ePersona pers[],int cantidad,int dni){
int existe = -1;
for(int i=0;i<cantidad;i++){
    if(pers[i].estado == 1 && pers[i].dni == dni){
        existe = i;
        break;
        }
}
return existe;
}

void altaPersona(ePersona pers[], int cantidad){
system("cls");
int dni;
int existe;
int espacioLibre = obtenerEspacioLibre(pers,cantidad);

if(espacioLibre <0){
    printf("El sistema esta lleno! llame a su programador favorito para solucionarlo :).\n");
    system("pause");
}else{
    printf("\t---A l t a   P e r s o n a---\n\n");
    printf("Ingrese los datos que se piden a continuacion...\n ");
    printf("\nD.N.I(sin puntos ni espacios): ");
    scanf("%d",&dni);

    existe = buscarPorDni(pers,cantidad,dni);

    if(existe == -1)
    {
        pers[espacioLibre].dni = dni;
        printf("\nNombre: ");
        fflush(stdin);
        scanf("%s", pers[espacioLibre].nombre);
        printf("\nEdad: ");
        fflush(stdin);
        scanf("%d", &pers[espacioLibre].edad);
        pers[espacioLibre].estado = 1;
        system("cls");
        printf("Se agrego a la persona con exito!\n");
        printf("Nombre\tedad\tD.N.I\n\n");
        mostrarPersona(pers[espacioLibre]);
        system("pause");


    }
    else{
        system("cls");
        printf("ERROR! El dni ingreaso ya existe!.\n");
        printf("El dni: %d pertenece a:  \n",dni);
        printf("Nombre\tedad\tD.N.I\n\n");
        mostrarPersona(pers[existe]);
        system("pause");
        system("cls");
    }
}
}//

void mostrarPersona(ePersona pers){
pers.nombre[0]= toupper(pers.nombre[0]);
printf("%s\t%d\t%d\n",pers.nombre,pers.edad, pers.dni);
}

void mostrarPersonas(ePersona pers[],int cantidad){
    system("cls");
    ordenarPersonas(pers,cantidad);
    printf("\t---M o s t r a r   P e r s o n a s---\n");
    printf("Nombre\tedad\tD.N.I\n");
    printf("*****************************\n");
    for(int i=0;i<cantidad;i++){
        if(pers[i].estado==1){
        mostrarPersona(pers[i]);
        }
    }
    system("pause");
}

void bajaPersona(ePersona pers[],int cantidad){
system("cls");
int dni;
char opcion;
int existe;

printf("\t--- B a j a    P e r s o n a ---\n\n");
printf("Para eliminar a una persona de la base de datos, ingrese su D.N.I: ");
scanf("%d",&dni);

existe=buscarPorDni(pers,cantidad,dni);

if(existe >= 0){
    printf("Persona encontrada: \n");
    printf("Nombre\tedad\tD.N.I\n");
    mostrarPersona(pers[existe]);
    printf("Estas seguro de querer eliminarla del sistema? s/n: ");
    fflush(stdin);
    scanf("%c",&opcion);
    if(opcion == 'n')
    {
        printf("No se a concretado la baja\n");
        system("pause");

    }
    else
    {
        system("cls");
        printf("\nBaja exitosa!\n");
        printf("%s fue borrado del sistema...\n",pers[existe].nombre);
        pers[existe].estado = 0;
        system("pause");
    }
}
else{
    printf("ERROR! el dni: %d ingresado no existe!\n\n",dni);
    system("pause");
}
}

void ordenarPersonas(ePersona pers[],int cantidad){

ePersona aux;

for(int i=0;i<cantidad-1;i++){
    for(int j=i+1; j<cantidad; j++){
        if(stricmp(pers[i].nombre,pers[j].nombre)>0){
                aux = pers[i];
                pers[i] = pers[j];
                pers[j] = aux;
        }
        else{
            if(stricmp(pers[i].nombre,pers[j].nombre)==0){
                if(pers[i].dni < pers[j].dni){
                aux = pers[i];
                pers[i] = pers[j];
                pers[j] = aux;
                }
            }
        }
    }
}
}

void graficoPorEdades(ePersona pers[], int cantidad){

system("cls");
int bandera = 0;
int mayor;
int menoresDe18 = 0;
int entre19y35 = 0;
int mayoresDe36 = 0;

printf("\t--- G r a f i c o   d e   E d a d e s ---\n\n");

for(int i=0; i<CANT; i++){
    if(pers[i].estado == 1){
        if(pers[i].edad <= 18){
            menoresDe18++;
        }
        else{
            if(pers[i].edad >= 19 && pers[i].edad <= 35){
                entre19y35++;
            }
            else{
                mayoresDe36++;
            }
        }
    }
}

if(menoresDe18 >= entre19y35 && menoresDe18 >= mayoresDe36){
        mayor = menoresDe18;
    }
    else{
        if(entre19y35 >= menoresDe18 && entre19y35 >= mayoresDe36){
            mayor = entre19y35;
        }
        else{
            mayor = mayoresDe36;
        }
    }
    for(int i=mayor; i>0; i--){
        if(i <= menoresDe18){
            printf("  *");
        }
        if(i <= entre19y35){
            printf("\t*");
            bandera = 1;
        }
        if(i <= mayoresDe36){
            if(bandera == 0){
                printf("\t\t*");
            }
            else{
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("<18\t19-35\t36>\n\n");
    system("pause");
}



