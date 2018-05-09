#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    char nombre[21];
    int edad;
    int dni;
    int estado;
}ePersona;

int obtenerEspacioLibre(ePersona pers[],int cantidad);

int buscarPorDni(ePersona pers[],int cantidad,int dni);

void inicializarEstadoPersona(ePersona pers[],int cantidad);

int funcionMenu();

void altaPersona(ePersona pers[], int cantidad);

void mostrarPersona(ePersona pers);

void mostrarPersonas(ePersona pers[],int cantidad);

void ordenarPersonas(ePersona pers[],int cantidad);

void graficoPorEdades(ePersona pers[], int cantidad);
#endif // FUNCIONES_H_INCLUDED
