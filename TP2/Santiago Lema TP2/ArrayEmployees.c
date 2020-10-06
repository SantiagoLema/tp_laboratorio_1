#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/////FUNCIONES///////
int initEmployees(Employee list[], int len)
{
    int error = 1;
    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int findFreeSpace(Employee list[], int len)
{
    int indice = -1;
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int addEmployee(Employee list[], int len, int id)
{
    int error = 1;
    int indice;
    Employee newEmployee;

    if(list != NULL && len > 0 && id > 0)
    {
        system("cls");
        printf("ALTA DE EMPLEADO\n\n");
        indice = findFreeSpace(list, len);

        if(indice == -1)
        {
            printf("\nNo hay espacio para una nueva alta.\n");
        }
        else
        {
            newEmployee.id = id;
            newEmployee.isEmpty = 0;

            printf("\nIngrese nombre del empleado: ");
            fflush(stdin);
            gets(newEmployee.name);

            printf("\nIngrese apellido del empleado: ");
            fflush(stdin);
            gets(newEmployee.lastName);

            printf("\nIngrese sector del empleado: ");
            printf("\n1-> RRHH\n2-> Administracion\n3-> Sistemas\n4-> Maestranza\n");
            scanf("%d", &newEmployee.sector);

            printf("\nIngrese salario del empleado: ");
            scanf("%f", &newEmployee.salary);

            list[indice] = newEmployee;
            error = 0;
        }
    }

    return error;
}

int findEmployeeById(Employee list[], int len, int id)
{
    int indice = -1;
    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int removeEmployee(Employee list[], int len)
{
    int error = 1;
    int legajo;
    int indice;
    char confirma;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("    *** BAJA DE EMPLEADO ***\n");
        printEmployees(list, len);
        printf("\nIngrese legajo del empleado: ");
        scanf("%d", &legajo);

        indice = searchEmployee(list, len, legajo);

        if( indice == -1)
        {
            printf("\nNo existe un empleado con ese legajo.\n");
        }
        else
        {
            printEmployee(list[indice]);
            printf("\nConfirma la baja del empleado?: s/n\n");
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                list[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
    return error;
}

int sortEmployees(Employee list[], int len, int order)
{
    int error = 1;
    Employee auxEmployee;

    if(list!=NULL && len>0 && order>=0 && order<=1)
    {
        for(int i=0; i<len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if((strcmp(list[i].lastName, list[j].lastName) > 0 && order == 1)
                        || (strcmp(list[i].lastName, list[j].lastName) < 0 && order == 0))
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                else if((strcmp(list[i].lastName, list[j].lastName) == 0)
                        && (list[i].sector < list[j].sector && order == 1)
                        || (list[i].sector > list[j].sector && order == 0))
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }
        error = 0;
    }
    return error;
}

void printEmployee(Employee anEmployee)
{
    printf("  %d        %s         %s         %.0f          %d\n", anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}

int printEmployees(Employee list[], int len)
{
    int error = 1;
    int flag = 0;

    if( list != NULL && len > 0)
    {
        system("cls");
        printf(" Legajo     Nombre     Apellido     Salario     Sector\n");
        printf("------------------------------------------------------\n\n");

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printEmployee(list[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("\nNo hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

int searchEmployee(Employee list[], int len, int id)
{
    int indice = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modifyEmployee(Employee list[], int len)
{
    int error = 1;
    int legajo;
    int indice;
    int opcion;
    char confirma;
    Employee newEmployee;


    if(list != NULL && len > 0)
    {
        system("cls");
        printf("    *** MODIFICAR EMPLEADO ***\n");
        printEmployees(list, len);
        printf("\nIngrese el legajo del empleado a modificar: ");
        scanf("%d", &legajo);

        indice = searchEmployee(list, len, legajo);

        if( indice == -1)
        {
            printf("\nNo existe un empleado con ese legajo.\n");
        }
        else
        {
            printEmployee(list[indice]);
            printf("\nQue desea modificar? Ingrese el numero de opcion.\n1-> Nombre\n2-> Apellido\n3-> Salario\n4-> Sector\n");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(newEmployee.name);
                break;
            case 2:
                printf("\nIngrese nuevo apellido: ");
                fflush(stdin);
                gets(newEmployee.lastName);
                break;
            case 3:
                printf("\nIngrese nuevo salario: ");
                scanf("%f", &newEmployee.salary);
                break;
            case 4:
                printf("\nIngrese nuevo sector: ");
                fflush(stdin);
                scanf("%d", &newEmployee.sector);
                break;
            }

            printf("\nConfirma modificacion? s/n\n");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if (confirma == 's')
            {
                switch(opcion)
                {
                case 1:
                    strcpy(list[indice].name, newEmployee.name);
                    break;
                case 2:
                    strcpy(list[indice].lastName, newEmployee.lastName);
                    break;
                case 3:
                    list[indice].salary = newEmployee.salary;
                    break;
                case 4:
                    list[indice].sector = newEmployee.sector;
                    break;
                default:
                    printf("Error. Ingrese una opcion valida.");
                }
                error = 0;
            }
            else
            {
                printf("\nModificacion cancelada.\n");
                error = 2;
            }
        }
    }
    return error;
}
