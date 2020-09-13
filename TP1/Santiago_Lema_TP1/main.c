#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "calculadora.h"


int main()
{
    //Declaracion de variables
    int opcionIngresada;
    int primerOperando;
    int segundoOperando;
    int banderaPrimerOperando = 0;
    int banderaSegundoOperando = 0;
    int banderaOperaciones = 0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    long long int resultadoFactX;
    long long int resultadoFactY;


    do // comienzo del do while
    { //MENU
        printf("***CALCULADORA***\n\n-Suma-\n-Resta-\n-Division-\n-Multiplicacion-\n-Factorial-\n\n*OPCIONES*\n\n");
        if(banderaPrimerOperando == 0)
        {
            printf("1-> Ingrese el primer operando: A = X\n");
        }
        else
        {
            printf("1-> Ingrese el primer operando: A = %d\n", primerOperando);
        }
        if(banderaSegundoOperando == 0)
        {
            printf("2-> Ingrese el segundo operando: B = Y\n");
        }
        else
        {
            printf("2-> Ingrese el segundo operando: B = %d\n", segundoOperando);
        }
        printf("3-> Calcular todas las operaciones.\n4-> Informar resultados.\n5-> Salir.\n\n");
        printf("Ingrese el numero de la opcion elegida: ");
        scanf("%d", &opcionIngresada);

        switch(opcionIngresada) // Seleccion de opcion
        {
        case 1:
            if(banderaPrimerOperando == 0)
            {
                banderaPrimerOperando = 1;
                system("cls");
                printf("Ingrese el primer operando: "); // INGRESO PRIMER OPERANDO
                scanf("%d", &primerOperando);
            }
            else
            {
                if(banderaSegundoOperando == 0)
                {
                    system("cls");
                    printf("Primer operando ya ingresado. Por favor, ingrese el segundo.\n\n"); // Validacion primer operando ya ingresado
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("Los dos operandos ya fueron ingresados. Por favor, continue con las operaciones.\n\n"); //validacion operandos ya ingresados
                    system("pause");
                }
            }
            break;
        case 2:
            if(banderaPrimerOperando == 0)
            {
                system("cls");
                printf("Por favor, ingrese el primer operando antes que el segundo.\n\n"); //validacion orden de ingreso de operandos
                system("pause");
            }
            else
            {
                if(banderaSegundoOperando == 0)
                {
                    banderaSegundoOperando = 1;
                    system("cls");
                    printf("Ingrese el segundo operando: "); // INGRESO SEGUNDO OPERANDO
                    scanf("%d", &segundoOperando);
                }
                else
                {
                    system("cls");
                    printf("Segundo operando ya ingresado. Por favor, continue con las operaciones.\n\n"); //Validacion segundo operando ya ingresado
                    system("pause");
                }
            }
            break;
        case 3:
            if(banderaPrimerOperando == 0)
            {
                system("cls");
                printf("Para hacer las operaciones primero debe ingresar el primer operando, seleccionando la opcion 1.\n\n"); //validacion orden de ingreso de las opciones del menu
                system("pause");
            }
            else
            {
                if(banderaSegundoOperando == 0)
                {
                    system("cls");
                    printf("Para hacer las operaciones primero debe ingresar el segundo operando, seleccionando la opcion 2.\n\n"); //validacion orden de ingreso de las opciones del menu
                    system("pause");
                }
                else
                {   //CALCULO DE LAS OPERACIONES
                    system("cls");
                    banderaOperaciones = 1;
                    resultadoSuma = sumar(primerOperando, segundoOperando);
                    resultadoResta = restar(primerOperando, segundoOperando);
                    resultadoDivision = dividir(primerOperando, segundoOperando);
                    resultadoMultiplicacion = multiplicar(primerOperando, segundoOperando);
                    resultadoFactX = factorialX(primerOperando);
                    resultadoFactY = factorialY(segundoOperando);
                    printf("<<<Las operaciones fueron calculadas exitosamente>>>\n\n");
                    system("pause");
                }
            }
            break;
        case 4:
            if(banderaPrimerOperando == 0)
            {
                system("cls");
                printf("Para mostrar los resultados primero debe ingresar los operandos, y luego calcular las operaciones.\n\n"); //validacion orden de ingreso de las opciones del menu
                system("pause");
            }
            else
            {
                if(banderaSegundoOperando == 0)
                {
                    system("cls");
                    printf("Para mostrar los resultados primero debe ingresar el segundo operando, y luego calcular las operaciones.\n\n"); //validacion orden de ingreso de las opciones del menu
                    system("pause");
                }
                else
                {
                   if(banderaOperaciones == 0)
                    {
                        system("cls");
                        printf("Para mostrar los resultados primero debe calcular las operaciones, seleccionando la opcion 3.\n\n"); //validacion orden de ingreso de las opciones del menu
                        system("pause");
                    }
                    else
                    {   //MOSTRAR RESULTADOS
                        system("cls");
                        printf("La suma de ambos numeros es: %d\n\n", resultadoSuma);
                        printf("La resta de ambos numeros es: %d\n\n", resultadoResta);
                        if(segundoOperando == 0)
                        {
                            printf("Error. No es posible dividir por 0.\n\n");
                        }
                        else
                        {
                            printf("La division de ambos numeros es: %.1f\n\n", resultadoDivision);
                        }
                        printf("La multiplicacion de ambos numeros es: %d\n\n", resultadoMultiplicacion);
                        if(primerOperando < 0 )
                        {
                            printf("No se puede obtener el factorial de %d porque es un numero negativo y ", primerOperando);
                            banderaPrimerOperando = 0;
                            banderaSegundoOperando = 0;
                        }
                        else
                        {
                            if(primerOperando > 12)
                            {
                                printf("El resultado del factorial de %d es demasiado largo para ser mostrado y ", primerOperando);
                                banderaPrimerOperando = 0;
                                banderaSegundoOperando = 0;
                            }
                            else
                            {
                                printf("El factorial de %d es: %lld y ", primerOperando, resultadoFactX);
                                banderaPrimerOperando = 0;
                                banderaSegundoOperando = 0;
                            }
                        }
                        if(segundoOperando < 0 )
                        {
                            printf("no se puede obtener el factorial de %d porque es un numero negativo.\n\n", segundoOperando);
                            system("pause");
                            banderaPrimerOperando = 0;
                            banderaSegundoOperando = 0;
                        }
                        else
                        {
                            if(segundoOperando > 12)
                            {
                                printf("el resultado del factorial de %d es demasiado largo para ser mostrado.\n\n", segundoOperando);
                                system("pause");
                                banderaPrimerOperando = 0;
                                banderaSegundoOperando = 0;
                            }
                            else
                            {
                                //printf("El factorial de %d es %I64u y el factorial de %d es %I64u\n\n", primerOperando, resultadoFactX, segundoOperando, resultadoFactY);
                                printf("el factorial de %d es: %lld.\n\n", segundoOperando, resultadoFactY);
                                system("pause");
                                banderaPrimerOperando = 0;
                                banderaSegundoOperando = 0;
                            }
                        }

                    }
                }
            }
            break;
        case 5:
            break;
        default:
            printf("\nError. Por favor, ingrese un numero de opcion valido.\n\n"); //Validacion numero de opcion de menu ingresado
            system("pause");
            break;
        }
        system("cls");
    }
    while(opcionIngresada != 5); // fin de do while

    return 0;
}

