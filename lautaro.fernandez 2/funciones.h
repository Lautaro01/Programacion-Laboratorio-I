
typedef struct{

    int codigoDeProveedor;
    char descripcion[51];
    int estado;
}eProveedor;

typedef struct{

    int codigoDeProducto;
    char descipcion[51];
    float importe;
    int cantidad;
    int idProveedor;
    int estado;
}eProducto;


int funcionMenu();

void inicializarEstadoPersona(eProveedor prov[],int tam);

void inicializarEstadoProducto(eProducto produ[],int tam);

int buscarLibre(eProveedor prov[],int tam);

int buscarProveedor(eProveedor prov[],int tam,int id);

int buscarProducto(eProducto produ[],int tam,int id);

int altaProducto(eProducto produ[],eProveedor prov[],int tam,int cant,int id,int idProvedor);

int altaProveedor(eProveedor prov[], int tam,int id);

void modificar(eProducto produ[],int tam);

void bajaProducto(eProducto produ[],int tam);
