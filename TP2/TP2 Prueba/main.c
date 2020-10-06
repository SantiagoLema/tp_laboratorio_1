#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "DataStore2.h"
#include <string.h>

#define TAM 10
#define ASC 1
#define DESC 0


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;


char menu();
int initEmployees(Employee list[], int len);
int printEmployees(Employee list[], int len);
void printEmployee(Employee anEmployee);
int searchFreeSpace(Employee list[], int len);
int addEmployee(Employee list[], int len, int id); //Ver que onda aca "legajo"
int modifyemployee(Employee list[], int len);
int searchEmployee(Employee list[], int len, int id); //Ver que onda aca "legajo"
int removeEmployee(Employee list[], int len);
int hardcodearPersonas(Employee list[], int len, int cantidad);//desp eliminar
int sortEmployees(Employee list[], int len, int order);
//int ordenarPersonasSexoAltura(ePersona gente[], int tam, int criterioS, int criterioA);



int main()
{
    char seguir = 's';
    char confirma;
    int proximoLegajo = 20000;
    int rta;
    int opcionOrdenar;
    int acumuladorSalarios = 0;
    int cantidadSalarios = 0;
    float promedioSalarios;



    Employee list [TAM] /*=
    {
        {1122, "Juan", 'm', 1.78, 0},
        {1132, "Jose", 'm', 1.75, 0},
        {1152, "Matias", 'm', 1.78, 0},
        {1132, "Nicolas", 'm', 1.75, 0},
        {1152, "Felix", 'm', 1.78, 0},
    }*/;

    if(initEmployees(list, TAM)==0)
    {
        printf("Personas inicializadas con exito!");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar personas");
    }

    hardcodearPersonas(list, TAM, 5);

    proximoLegajo += 5;

    do
    {
        switch(menu())
        {

        case 'a':
            if(addEmployee(list, TAM, proximoLegajo) == 0)
            {
                proximoLegajo++;
                printf("ALTA EXITOSA!\n");
            }
            else
            {
                printf("Problema para realizar el alta");
            }
            break;
        case 'b':
             rta = modifyemployee(list, TAM);

            if( rta == 0)
            {
                printf("Modificacion exitosa\n");
            }
            else if(rta == 2)
            {
                printf("La modificacion ha sido cancelada por usuario\n");
            }
            else
            {
                printf("Se ha producido un error en la modificacion\n");
            }




            break;
        case 'c':
            rta = removeEmployee(list, TAM);

            if( rta == 0)
            {
                printf("Baja exitosa\n");
            }
            else if(rta == 2)
            {
                printf("Baja cancelada por usuario\n");
            }
            else
            {
                printf("Se ha producido un error en la baja\n");
            }

            break;
        case 'd':
                system("cls");
            printEmployees(list,TAM);
            printf("\n1-> Ordenar alfabeticamente y por sector de manera ascendente.\n");
            printf("\n2-> Ordenar alfabeticamente y por sector de manera descendente.\n");
            printf("\n3-> Mostrar total y promedio de los salarios.\n");
            scanf("%d", &opcionOrdenar);
            switch(opcionOrdenar)
            {
            case 1:
                sortEmployees(list, TAM, 1);
                printEmployees(list, TAM);
                break;
            case 2:
                sortEmployees(list, TAM, 0);
                printEmployees(list, TAM);
                break;
            case 3:
                for(int i=0; i<TAM; i++)
                {
                    acumuladorSalarios = acumuladorSalarios + list[i].salary;
                    cantidadSalarios++;
                }
                promedioSalarios = acumuladorSalarios / cantidadSalarios;
                printf("\nEl salario total acumulado es $%d\n", acumuladorSalarios);
                printf("\nEl salario promedio es $%f.2\n", promedioSalarios);
                //AGREGAR que muestre los que se pasan del promedio
            }
            break;
        /*case 'e':
            if(ordenarPersonasSexoAltura(lista,TAM,ASC,DESC))
            {
                printf("\nHubo un problema al intentar ordenar las personas\n\n");
            }
            else
            {
                printf("\nPersonas ordenadas con exito!\n\n");
            }

            break;*/
        case 'z':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');

    return 0;
}

char menu()
{
    char opcion;
    system("cls");

    printf("*** ABM Personas ***\n\n");
    printf("A-> Alta\n");
    printf("B-> Modificar\n");
    printf("C-> Baja\n");
    printf("d Listar\n");
    printf("e Ordenar\n");
    printf("f Informes\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}



int initEmployees(Employee list[], int len)
{

    int error = 1;
    if (list!=NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int printEmployees(Employee list[], int len)
{

    int error = 1;
    int flag = 0;

    if( list != NULL && len > 0)
    {
        //system("cls");
        printf(" Legajo    Nombre    Apellido    Salario    Sector\n");
        printf("---------------------------------------------------\n\n");

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
            printf("    No hay personas en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}
void printEmployee(Employee anEmployee)
{
    printf("  %d    %s    %s    %.2f   %s\n", anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}

int searchFreeSpace(Employee list[], int len) //////para dar de alta
{
    int indice = -1;

    for(int i = 0; i < len; i++)
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

    if(list!=NULL && len > 0 && id > 0)
    {

        system("cls");
        printf("ALTA DE PERSONA\n\n");
        indice = searchFreeSpace(list, len);

        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            newEmployee.id = id;
            newEmployee.isEmpty = 0;

            printf("Ingrese nombre del empleado: ");
            fflush(stdin);
            gets(newEmployee.name);

            printf("Ingrese apellido del empleado: ");
            fflush(stdin);
            gets(newEmployee.lastName);

            printf("Ingrese sector del empleado: ");
            scanf("%d", &newEmployee.sector);

            printf("Ingrese salario del empleado: ");
            fflush(stdin);
            scanf("%.2f", &newEmployee.salary);

            list[indice] = newEmployee;
            error = 0;
        }
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

int removeEmployee(Employee list[], int len)
{
    int error = 1;
    int legajo;
    int indice;
    int confirma;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("    *** BAJA DE PERSONA ***\n");
        printEmployees(list, len);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = searchEmployee(list, len, legajo);

        if( indice == -1)
        {
            printf("No existe una persona con ese legajo.\n");
        }
        else
        {
            printEmployee(list[indice]);
            printf("Confirma baja: 1 - SI 2 - NO");
            scanf("%d", &confirma);
            if(confirma == 1)
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

int modifyemployee(Employee list[], int len)
{
    int error = 1;
    int legajo;
    int indice;
    char confirma;
    int opcion;
    Employee newEmployee;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("    *** MODIFICAR PERSONA ***\n");
        printEmployees(list, len);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = searchEmployee(list, len, legajo);

       if( indice == -1)
        {
            printf("No existe un empleado con ese legajo.\n");
        }
        else
        {
            printEmployee(list[indice]);
            printf("\n¿Que desea modificar? Ingrese el numero de opcion.\n1-> Nombre\n2-> Apellido\n3-> Salario\n4-> Sector\n");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(newEmployee.name);
                //list[indice].name = newEmployee.name;
                break;
            case 2:
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                gets(newEmployee.lastName);
                //scanf("%s", &newLastName);
                break;
            case 3:
                printf("Ingrese nuevo salario: ");
                scanf("%.2f", &newEmployee.salary);
                break;
            case 4:
                printf("Ingrese nuevo sector: ");
                fflush(stdin);
                //gets(newSector);
                scanf("%d", &newEmployee.sector);
                break;
            }

            printf("¿Confirma modificacion?\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                switch(opcion)
                {
                case 1:
                    strcpy(list[indice].name, newEmployee.name);
                    break;
                case 2:
                    strcpy(list[indice].lastName, newEmployee.lastName);
                    //list[indice].lastName = newEmployee.lastName;
                    break;
                case 3:
                    list[indice].salary = newEmployee.salary;
                    break;
                case 4:
                    list[indice].sector = newEmployee.sector;
                    break;
                }

                printf("Modificacion realizada con exito!\n");
                error = 0;
            }
            else
            {
                printf("Modificacion cancelada.\n");
                error = 2;
            }
        }
    }
    return error;
}



int hardcodearPersonas(Employee list[], int len, int cantidad)
{
    int error = 1;

    if(list!= NULL && len>0 && cantidad >= 0 && cantidad <= len)
    {

        for(int i=0; i<len; i++)
        {
            list[i].id = legajos[i];
            strcpy(list[i].name, nombres[i]);
            strcpy(list[i].lastName, apellidos[i]);
            list[i].sector = sectores[i];
            list[i].salary = sueldos[i];

            list[i].isEmpty = 0;
        }

        error = 0;
    }

    return error;
}

int sortEmployees(Employee list[], int len, int order)
{
    int error = 1;
    Employee auxEmployee;

    if(list!=NULL && len>0 && order>=0 && order<=1)
    {


        for(int i=0; i-len -1; i++)
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
                        && (strcmp(list[i].sector, list[j].sector) > 0 && order == 1)//sacar el strcmp de "sector"
                        || (strcmp(list[i].sector, list[j].sector) < 0 && order == 0))
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

