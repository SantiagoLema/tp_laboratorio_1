#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define TAM 1000


////MAIN//////
int main()
{
    int opcionIngresada;
    char seguir = 's';
    char confirma;
    int proximoLegajo = 500;
    int rta;
    int opcionOrdenar;
    int acumuladorSalarios = 0;
    int cantidadSalarios = 0;
    float promedioSalarios;
    int banderaAltaEmpleado = 0;

    Employee list[TAM];


    if(initEmployees(list, TAM)==0)
    {
        printf("Empleados inicializados con exito!\n\n");
        system("pause");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar los empleados\n");
        system("pause");
    }
    system("cls");


    do // comienzo del do while
    {
        //MENU
        printf("***ALTAS Y BAJAS DE EMPLEADOS***\n\n*OPCIONES*\n\n");
        printf("1-> ALTAS\n2-> MODIFICAR\n3-> BAJA\n4-> INFORMAR \n5-> SALIR\n\n");
        printf("Ingrese el numero de la opcion elegida: ");
        scanf("%d", &opcionIngresada);

        switch(opcionIngresada) // Seleccion de opcion
        {
        case 1://Alta de empleado
            if(addEmployee(list, TAM, proximoLegajo) == 0)
            {
                proximoLegajo++;
                printf("\nALTA EXITOSA!\n\n");
                system("pause");
                printEmployees(list, TAM);
                banderaAltaEmpleado = 1;
            }
            else
            {
                printf("\nProblema para realizar el alta\n\n");
            }
            break;
        case 2: //Modificacion de empleado
            if(banderaAltaEmpleado == 1)
            {
                rta = modifyEmployee(list, TAM);
                if( rta == 0)
                {
                    printf("\nModificacion exitosa\n\n");
                }
                else if(rta == 2)
                {
                    printf("\nLa modificacion ha sido cancelada por usuario\n\n");
                }
                else
                {
                    printf("\nSe ha producido un error en la modificacion\n\n");
                }
            }
            else
            {
                system("cls");
                printf("\nPara hacer modificaciones primero debe haber empleados dados de alta.\n\n");
            }
            break;
        case 3:// Baja de empleado
            if(banderaAltaEmpleado == 1)
            {
                rta = removeEmployee(list, TAM);
                if( rta == 0)
                {
                    printf("\nBaja exitosa!\n");
                }
                else if(rta == 2)
                {
                    printf("\nBaja cancelada por usuario\n");
                }
                else
                {
                    printf("\nSe ha producido un error en la baja\n");
                }
            }
            else
            {
                system("cls");
                printf("\nPara realizar bajas primero debe haber empleados dados de alta.\n\n");
            }
            break;
        case 4://Listar y ordenar empleados
            if(banderaAltaEmpleado == 1)
            {
                system("cls");
                printEmployees(list,TAM);
                printf("\n1-> Ordenar alfabeticamente y por sector de manera ascendente.\n");
                printf("\n2-> Ordenar alfabeticamente y por sector de manera descendente.\n");
                printf("\n3-> Mostrar total y promedio de los salarios.\n");
                scanf("%d", &opcionOrdenar);
                switch(opcionOrdenar)//Menu para listar y ordenar e empleados
                {
                case 1://Ordenamiento ascendente
                    sortEmployees(list, TAM, 1);
                    printEmployees(list, TAM);
                    break;
                case 2://Ordenamiento descendente
                    sortEmployees(list, TAM, 0);
                    printEmployees(list, TAM);
                    break;
                case 3://Muestra salarios y promedio

                    for(int i=0; i<TAM; i++)
                    {
                        if(list[i].isEmpty == 0)
                        {
                            acumuladorSalarios = acumuladorSalarios + list[i].salary;
                            cantidadSalarios++;
                        }
                    }
                    promedioSalarios = (float) acumuladorSalarios / cantidadSalarios;
                    printf("\nEl salario total acumulado es $ %d\n", acumuladorSalarios);
                    printf("\nEl salario promedio es $ %.2f\n\n", promedioSalarios);
                    break;
                }
            }
            else
            {
                system("cls");
                printf("\nPara listar y ordenar primero debe haber empleados dados de alta.\n\n");
            }
            //system("pause");
            break;
        case 5://Salida del programa
            printf("\nConfirma salida? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("\nOpcion invalida!\n");
        }
        system("pause");
        system("cls");
    }
    while( seguir == 's');//fin del do while
    return 0;
}

