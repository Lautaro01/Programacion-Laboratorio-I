
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED




int suma(int a, int b)
{
    int resultado;
    resultado = a + b;
    return resultado;

}

int resta(int a,int b)
{
    int resultado;
    resultado = a - b;
    return resultado;
}

float division(float a,float b)
{
    float resultado;
    resultado = (float) a / b;
    return resultado;
}

int multiplicacion(int a, int b)
{
    int resultado;
    resultado = a * b;
    return resultado;
}

int factorial(int a)
{
    int i;
    int resultado=1;

    for(i=1;i<=a;i++)
    {
        resultado= resultado * i;
    }

    return resultado;
}

#endif // FUNCIONES_H_INCLUDED
