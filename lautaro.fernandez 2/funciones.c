#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

        opcion=getchar();

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

int buscarLibreProduc(eProducto produ[],int tam){
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

int altaProveedor(eProveedor prov[], int tam,int id){
system("cls");
int indice = buscarLibre(prov,tam);

if(indice<0){
    printf("Ya no queda espacio disponible en el sistema!.");
    return 1;
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
        printf("Se an guardado los datos con exito!\n");
        system("pause");
        }
    return 0;
}

int altaProducto(eProducto produ[],eProveedor prov[],int tam,int cant,int id, int idProve){

system("cls");
int indice = buscarLibreProduc(produ,tam);
int idProveedor;
int existe;

    printf("ALTA PRODUCTO\n");
    printf("\nIngrese el codigo de proveedor: ");
    fflush(stdin);
    scanf("%d",&idProveedor);
    existe = buscarProveedor(prov,cant,idProveedor);
    if(existe == -1){
        printf("\nEl proveedor no existe\n\n",existe);
        system("pause");
        return 1;
    }
    else
    {
    printf("\nIngrese la descripcion del producto: ");
    fflush(stdin);
    scanf("%[^\n]",produ[indice].descipcion);
    fflush(stdin);
    printf("\nIngrese el importe del producto: ");
    scanf("%f",&produ[indice].importe);
    fflush(stdin);
    printf("\nIngrese la cantidad del productos: ");
    scanf("%d",&produ[indice].cantidad);

    produ[indice].codigoDeProducto = id;
    produ[indice].idProveedor = idProveedor;
    printf("\n\nCARGA EXITOSA! El codigo de producto es %d\n\n", id);
    produ[indice].estado=1;
    system("pause");

    }
    return 0;
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

            printf("\nQue desea modificar del producto ID: %d",auxProducto);
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
                    printf("La nueva descripcion es: %s", produ[existe].descipcion);
                    system("pause");
                    seguir = 0;
                    break;
                case 2:
                    system("cls");
                    printf("Modificar importe!\n");
                    printf("\nimporte actual: %f\n",produ[existe].importe);
                    printf("Ingrese nuevo importe: ");
                    fflush(stdin);
                    scanf("%f", &produ[existe].importe);
                    printf("\n\nMODIFICACION EXITOSA\n!");
                    printf("\nEl nuevo importe es: %f", produ[existe].importe);
                    system("pause");
                    seguir = 0;
                    break;
                case 3:
                    system("cls");
                    printf("Modificar cantidad!\n");
                    printf("\ncantidad actual: %d\n",produ[existe].cantidad);
                    printf("Ingrese nueva cantidad: ");
                    fflush(stdin);
                    scanf("%d", &produ[existe].cantidad);
                    printf("\n\nMODIFICACION EXITOSA\n!");
                    printf("\nLa nueva cantidad del producto es: %d", produ[existe].cantidad);
                    system("pause");
                    system("pause");
                    seguir = 0;
                    break;
                default:
                    printf("\nError! opcion incorecta\n");
                    }
        }
        else
        {
            printf("\nNo existe el producto, ID incorrecto!\n");
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
    printf("Usted esta por dar de baja al producto ID:",auxProducto);
    printf("\nEsta seguro que quire borrarlo? s/n: ");
    fflush(stdin);
    siono = getchar();

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

void mostrarProducto(eProducto producto)
{
    printf("%d\t%s\t%.2f\t%d \n",producto.codigoDeProducto,producto.descipcion,producto.importe,producto.cantidad,producto.idProveedor);
}

void mostrarProveedor(eProveedor prove)
{
    printf("%d\t%s\n",prove.codigoDeProveedor,prove.descripcion);
}

void casof(eProducto produ[],eProveedor prove[],int cant,int tam)
{
int i;
int j;
int cantidadProducProveedor=0;

     for(i=0;i<cant;i++){
        if(prove[i].estado == 1){
            for(j=0;j<tam;j++){
                if(produ[j].estado == 1){
                    if(produ[j].idProveedor == prove[i].codigoDeProveedor){
                            cantidadProducProveedor+=produ[j].cantidad;
                    }
                }
            }
            if(j == (tam-1))
            {

                if(cantidadProducProveedor <= 10)
                {
                    printf("ID proveedor\tDescripcion del Proveedor\n");
                    mostrarProveedor(prove[i]);
                    printf("Cantidad de Productos del proveedor: %d", cantidadProducProveedor);
                }
            }
        }
    }
}

void casoh(eProducto produc[],eProveedor prove[],int tam,int cant){

    int id;
    int existe;
    system("cls");
    printf("Lista de proveedores\n\n");
    printf("ID proveedor\tDescripcion del Proveedor\n");
    for(int i=0;i<cant;i++){
        if(prove[i].estado==1){
            mostrarProveedor(prove[i]);
        }
    }
    printf("\n\nIngrese Id de proveedor: ");
    scanf("%d",&id);

    existe = buscarProveedor(prove,cant,id);
    if(existe>=0)
    {
        printf("Codigo De Producto\tDescripcion\tImporte\tCantidad\t\tID de proveerdor\n")
        for(int j=0;j<tam;j++){
        if(produc[j].idProveedor == id && produc[j].estado==1)
            mostrarProducto(produc[j]);
      }
    }
    else
    {
        printf("\nError! el proveedor no existe\n\n");
        system("pause");
    }
    system("pause");
}

void casoi()
{
    int Maximo=0;
    int Minimo=0;
    int flat=0;
    int i;
    int j;
    int auxMaximo=0;
    int auxMinimo=0;

    if(flat = 0)
    {
      for(i=0;i<1;i++){
        if(prove[i].estado==1){
           for(j=0;j<tam;j++){
            if(produ[j].idProveedor == prove[i].codigoDeProveedor && prove[j].estado==1){

            maximo+=produ[j].cantidad;
            minimo+=produ[j].cantidad;

            }
          }
        }
      }
    }
    flat=1;
    if(flat == 1)
    {
        for(i=1;i<cant;i++){
            if(prove[i].estado==1){
                for(j=0;j<tam;j++){
                    if(produ[j].idProveedor == prove[i].codigoDeProveedor && prove[j].estado==1){
                    auxMaximo+=produ[j].cantidad;
                    auxMaximominimo+=produ[j].cantidad;
            }
          }
          if(auxMaximo > Maximo)
          {
              Maximo=auxMaximo;
          }
          else
          {
              if(auxMinimo < Minimo)
              {
                  Minimo = auxMinimo;
              }
          }
        }
      }
    }

    }

}

void informarPromomedioYtotal(eProducto produ[],int tam)
{
    float totalImportes=0;

    int cantidadDeProductos=0;

    float promedioImporte=0;

    int cantidadDeProductosQueSuperanElPromedio=0;

    int cantidadDeProductosQueNoSuperanElPromedio=0;


    for(int i=0;i<tam;i++)
    {
        if(produ[i].estado == 1)
        {
          totalImportes = totalImportes + (produ[i].importe * produ[i].cantidad);
          cantidadDeProductos = cantidadDeProductos + produ[i].cantidad;
        }
    }

    promedioImporte = totalImportes / cantidadDeProductos;

    for(int i=0;i<tam;i++)
    {
        if(produ[i].estado == 1)
        {
            if(produ[i].importe > promedioImporte)
            {
                cantidadDeProductosQueSuperanElPromedio = cantidadDeProductosQueSuperanElPromedio + produ[i].cantidad;
            }
        }

    }

    for(int i=0;i<tam;i++)
    {
        if(produ[i].estado == 1)
        {
            if(produ[i].importe < promedioImporte)
            {
                cantidadDeProductosQueNoSuperanElPromedio = cantidadDeProductosQueNoSuperanElPromedio + produ[i].cantidad;
            }
        }

    }

    printf("\n\nTotal de importes: %.2f\n", totalImportes);
    printf("Promedio de los importes: %.2f\n", promedioImporte);
    printf("Cantidad de productos que superan el promedio: %d\n", cantidadDeProductosQueSuperanElPromedio);
    printf("Cantidad de productos que NO superan el promedio: %d\n\n", cantidadDeProductosQueNoSuperanElPromedio);
    system("pause");
}

void listarProductos(eProducto produ[],eProveedor prove[],int tam,int cant)
{

float totalImportes=0;
int cantidadDeProductos=0;
float promedioImporte=0;
char opcion;

eProducto aux;

printf("---L I S T A R\t P R O D U C T O S---\n\n");
printf("A. Listado de todos los productos\n");
printf("B. Todos los productos que en cantidad son menor o igual a 10\n");
printf("C. Todos los productos que en cantidad son mayor a 10\n");
printf("D. Todos los productos que superan el promedio de los importes.\n");
printf("E. Todos los productos que NO superan el promedio de los importes.\n");
printf("F. Todos los proveedores cuya cantidad de producto es menor o igual a 10.\n");
printf("G. Todos los productos provistos por proveedor.\n");
printf("H. Todos los productos provistos por un proveedor determinado.\n");
printf("I. El Proveedor que provee mas productos, mostrando los productos.\n");
printf("J. El proveedor que provee menos productos, mostrando los productos.\n");
printf("K. El proveedor que provee el producto mas caro, mostrando ese producto.\n");
printf("L. El proveedor que provee el producto mas barato, mostrando ese producto.\n");
printf("\n\nIngrese opcion: ");
opcion = getchar();

switch(opcion){
case 'A':
    system("cls");

    for(int i=0; i<tam-1; i++)
    {
        if(produ[i].estado== 1)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(produ[j].estado== 1)
                {
                    if(produ[i].importe<produ[j].importe)
                    {
                        aux = produ[i];
                        produ[i]=produ[j];
                        produ[j]=aux;

                    }
                    else
                    {
                        if(strcmp(produ[i].descipcion,produ[j].descipcion)>0)
                            aux = produ[i];
                        produ[i]=produ[j];
                        produ[j]=aux;

                    }
                }
            }
        }
    }
printf("A. Listado de todos los productos\n");
printf("Codigo De Producto\tDescripcion\tImporte\tCantidad\t\tID de proveerdor\n");
    for(int i=0; i<tam; i++)
    {
        if(produ[i].estado == 1)
        {
            mostrarProducto(produ[i]);
        }
    }

    break;
case 'B':
    system("cls");
    printf("\nTodos los productos que en cantidad son menor o igual a 10: \n");
    printf("Codigo De Producto\tDescripcion\tImporte\tCantidad\t\tID de proveerdor\n");
    for(int i=0; i<tam; i++)
    {
        if(produ[i].cantidad <= 10 && produ[i].estado == 1)
        {
            mostrarProducto(produ[i]);
        }
    }
    break;
case 'C':
    system("cls");
    printf("\nTodos los productos que en cantidad son mayor a 10: \n");
    printf("Codigo De Producto\tDescripcion\tImporte\tCantidad\t\tID de proveerdor\n");
    for(int i=0;i<tam;i++){
       if(produ[i].cantidad > 10 && produ[i].estado == 1){
           mostrarProducto(produ[i]);
       }
    }
    break;
case 'D':

for(int i=0;i<tam;i++)
    {
        if(produ[i].estado == 1)
        {
          totalImportes = totalImportes + (produ[i].importe * produ[i].cantidad);
          cantidadDeProductos = cantidadDeProductos + produ[i].cantidad;
        }
    }
promedioImporte = totalImportes / cantidadDeProductos;

printf("\nTodos los productos que superan el promedio de los importes: \n");
printf("Codigo De Producto\tDescripcion\tImporte\tCantidad\t\tID de proveerdor\n");
   for(int i=0;i<tam;i++){
        if(produ[i].estado == 1){
            if(produ[i].importe > promedioImporte)
            {
                mostrarProducto(produ[i]);
            }
        }
   }

    break;
case 'E':

    for(int i=0;i<tam;i++)
    {
        if(produ[i].estado == 1)
        {
          totalImportes = totalImportes + (produ[i].importe * produ[i].cantidad);
          cantidadDeProductos = cantidadDeProductos + produ[i].cantidad;
        }
    }
promedioImporte = totalImportes / cantidadDeProductos;

printf("\nTodos los productos que NO superan el promedio de los importes: \n");
   for(int i=0;i<tam;i++){
        if(produ[i].estado == 1){
            if(produ[i].importe < promedioImporte)
            {
                mostrarProducto(produ[i]);
            }
        }
   }

    break;
case 'F':
        casof(produ,prove,cant,tam);
    break;
case 'G':
    system("cls");
    for(int i=0;i<cant;i++){
        if(prove[i].estado == 1){
            printf("ID proveedor\tDescripcion del Proveedor\n");
                mostrarProveedor(prove[i]);
            for(int j=0;j<tam;j++){
                if(produ[j].estado == 1){
                    printf("Codigo De Producto\tDescripcion\tImporte\tCantidad\t\tID de proveerdor\n");
                        if(produ[j].idProveedor == prove[i].codigoDeProveedor){
                            mostrarProducto(produ[i]);
                    }
                }
            }
        }
    }
    break;
case 'H':
    casoh(produ,prove,tam,cant);
    break;
case 'I':

    break;
case 'J':
    break;
case 'K':
    break;
case 'L':
    break;
}







}
