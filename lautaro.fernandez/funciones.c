#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int funcionMenu(){
        int opcion;
        system("cls");
        printf("---M e n u---\n\n");
        printf("1-alta proveedor\n");
        printf("2-alta producto\n");
        printf("3-Modoficar producto\n");
        printf("4-Baja producto\n");
        printf("5-Informar\n");
        printf("6-Listar\n");
        printf("ESC-Salir\n\n");
        printf("Ingrese opcion: ");

        opcion=getch();

    return opcion;
}//funcion

void inicializarEstadoPersona(eProveedor prov[],int tam){
    for(int i=0;i<tam;i++)
    {
        prov[i].estado = 0;
    }
}

void inicializarEstadoProducto(eProducto produ[],int tam){
    for(int i=0;i<tam;i++)
    {
        produ[i].estado = 0;
    }
}

int buscarLibre(eProveedor prov[],int tam){

int indice = -1; //si retorna -1 es que estan todos los espacios llenos, es decir todos los isEmpty en 0. osea que no hay nada vacio
for(int i=0;i<tam;i++){
    if(prov[i].estado == 0){
        indice = i;
        break;
    }
}
return indice;
}

int buscarLibreProduc(eProducto produ[],int tam)
{
int indice = -1; //si retorna -1 es que estan todos los espacios llenos, es decir todos los isEmpty en 0. osea que no hay nada vacio
for(int i=0;i<tam;i++){
    if(produ[i].estado == 0){
        indice = i;
        break;
    }
}
return indice;
}


int buscarProveedor(eProveedor prov[],int tam,int id){

int existe = -1; //busca si existe, si retorna -1 es que no existe.
for(int i=0;i<tam;i++){
    if(prov[i].estado == 1 && prov[i].codigoDeProveedor == id)
    {
        existe = i;
        break;
    }
}
return existe;
}

int buscarProducto(eProducto produ[],int tam,int id){

int existe = -1; //busca si existe, si retorna -1 es que no existe.
for(int i=0;i<tam;i++){
    if(produ[i].estado == 1 && produ[i].codigoDeProducto == id)
    {
        existe = i;
        break;
    }
}
return existe;
}




void altaProveedor(eProveedor prov[], int tam,int id){
system("cls");
int indice = buscarLibre(prov,tam);

if(indice<0){
    printf("Ya no queda espacio disponible en el sistema!.");
}
else{
        printf("---Alta proveedor---\n\n");

        prov[indice].codigoDeProveedor = id;
        printf("\nSu codigo De Proveedor es: %d", id);
        printf("\nIngrese una descripcion del proveedor: ");
        fflush(stdin);
        scanf("%[^\n]", prov[indice].descripcion);
        fflush(stdin);

        prov[indice].estado = 1;
        system("cls");
        printf("Se an guardado los siguientes datos con exito!\n");
        system("pause");
        }
}

void altaProducto(eProducto produ[],eProveedor prov[],int tam,int cant,int id){

system("cls");
int indice = buscarLibreProduc(produ,tam);
int idProveedor;
int existe;

    printf("ALTA PRODUCTO\n");
    printf("\nIngrese el codigo de proveedor: ");
    scanf("%d",&idProveedor);
    existe = buscarProveedor(prov,cant,idProveedor);
    if(existe == -1){
        printf("\nEl proveedor no existe\n",existe);
        system("pause");
    }
    else
    {
    printf("Ingrese la descripcion del producto: ");
    fflush(stdin);
    scanf("%[^\n]",produ[indice].descipcion);
    fflush(stdin);
    printf("\nIngrese el importe del producto: ");
    scanf("%f",&produ[indice].importe);
    fflush(stdin);
    printf("\nIngrese la cantidad del productos: ");
    scanf("%d",&produ[indice].cantidad);

    printf("\nCARGA EXITOSA!\n");
    produ[indice].codigoDeProducto = id;
    printf("El codigo de producto es %d\n", id);
    produ[indice].estado=1;
    prov[existe].idProducto = id;
    system("pause");
    }
}

void modificar(eProducto produ[],int tam){

int auxProducto;
int opcion;
int existe;
int seguir=1;
do{
    system("cls");
    printf("---Modificar producto---\n");
    printf("\nIngrese el codigo del producto!: ");
    scanf("%d",&auxProducto);
    existe = buscarProducto(produ,tam,auxProducto);

        if(existe >= 0){

            printf("\nQue desea modificar del producto N %d",existe);
            printf("\n1-Descripcion");
            printf("\n2-importe");
            printf("\n3-cantidad");
            printf("\n\nIngrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    system("cls");
                    printf("Modificar Descripcion!\n");
                    printf("\nDescripcion actual: %s\n",produ[existe].descipcion);
                    printf("Ingrese nueva Descripcion: ");
                    fflush(stdin);
                    scanf("%s", produ[existe].descipcion);
                    printf("\nMODIFICACION EXITOSA\n!");
                    seguir = 0;
                    break;
                case 2:
                    system("cls");
                    printf("Modificar importe!\n");
                    printf("\nimporte actual: %f\n",produ[existe].importe);
                    printf("Ingrese nuevo importe: ");
                    fflush(stdin);
                    scanf("%f", &produ[existe].importe);
                    printf("\nMODIFICACION EXITOSA\n!");
                    seguir = 0;
                    break;
                case 3:
                    system("cls");
                    printf("Modificar cantidad!\n");
                    printf("\ncantidad actual: %d\n",produ[existe].cantidad);
                    printf("Ingrese nueva cantidad: ");
                    fflush(stdin);
                    scanf("%d", &produ[existe].cantidad);
                    printf("\nMODIFICACION EXITOSA\n!");
                    seguir = 0;
                    system("pause");
                    break;
                default:
                    printf("\nError! opcion incorecta\n");
                    }
        }
        else
        {
            printf("\nNo existe un trabajador con ese legajo!\n");
            system("pause");
        }

}while(seguir!=0);
}

void bajaProducto(eProducto produ[],int tam){

int auxProducto;
char siono;

system("cls");
printf("---BAJA PRODUCTO---\n\n");
printf("Para dar de baja a un producto, ingrese su codigo de producto!: ");
scanf("%d", &auxProducto);

int existe = buscarProducto(produ,tam,auxProducto);

if(existe >= 0){
    /*printf("Usted esta por dar de baja a: \n\n");
    printf("Legajo\tNombre\tSexo\tSueldo\t\tFecha de Ingreso\n\n");
    mostrarEmpleado(emp[existe]);*/
    printf("\nEsta seguro que quire borrarlo? s/n: ");
    fflush(stdin);
    siono = getch();

    if(siono == 's')
    {
        produ[existe].estado = 0;
        printf("\nBorrado exitoso!");
    }
    else{
        printf("\nNo se dado de baja!...");
    }
}
else{

    printf("El id %d no existe!\n",auxProducto);
}
}



