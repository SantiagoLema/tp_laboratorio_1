#include "calculadora.h"

int sumar(int X, int Y) // Funcion SUMAR
{
    int resultado;

    resultado = X + Y;

    return resultado;
}

int restar(int X, int Y) // Funcion RESTAR
{
    int resultado;

    resultado = X - Y;

    return resultado;
}

float dividir(int X, int Y) // Funcion DIVIDIR
{
    float resultado;

    resultado = (float)X / (float)Y;

    return resultado;
}

int multiplicar(int X, int Y) // Funcion MULTIPLICAR
{
    int resultado;

    resultado = X * Y;

    return resultado;
}


long long int factorialX(int X) // Funcion FACTORIAL X
{
    int fact = 1;
    for( int i = 1; i <= X; i++ )
    {
        fact = fact*i;
    }
    return fact;
}


long long int factorialY(int Y) // // Funcion FACTORIAL Y
{
    int fact = 1;
    for( int i = 1; i <= Y; i++ )
    {
        fact = fact*i;
    }
    return fact;
}
