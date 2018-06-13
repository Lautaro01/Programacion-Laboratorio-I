#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define ESC 27
#define CANT 20
#define PRODUC 100


int main()
{
    eProveedor proveedor[CANT];
    eProducto producto[PRODUC];
    int opcion=0;
    int idProv=1;
    int idProd=1;

    int cantidadProductos=0;
    int totalProduc=0;

    inicializarEstadoPersona(proveedor,CANT);
    inicializarEstadoProducto(producto,PRODUC);

     do{
        int funcionMenu();
        switch(funcionMenu()){
            case '1':
                if(!altaProveedor(proveedor,CANT,idProv))
                    idProv++;
                break;
            case '2':
                if(!altaProducto(producto,proveedor,PRODUC,CANT,idProd,idProv))
                idProd++;
                break;
            case '3':
                modificar(producto,PRODUC);
                break;
            case '4':
                bajaProducto(producto,PRODUC);
                break;
            case '5':
                informarPromomedioYtotal(producto,PRODUC);
                break;
            case '6':
            case 27:
                    opcion = 'ESC';
                break;
        }
    }while(opcion != 'ESC');


    return 0;
}
