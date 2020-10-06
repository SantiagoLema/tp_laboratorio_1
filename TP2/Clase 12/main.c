#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "datastore.h"

#define TAM 5
#define ASC 1
#define DESC 0

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float altura;
    eFecha fNac;
    int isEmpty; //agrego este campo a la estructura para usar 0 o 1 y saber si esta vacio o no (0=false lleno/1=true vacio)

} ePersona;

int inicializarPersonas(ePersona gente[], int tam); //tmb se puede escribir como puntero "(ePersona* gente)", con * y sin [].
int mostrarPersonas(ePersona gente[], int tam);
void mostrarPersona(ePersona unaPersona);
int buscarLibre(ePersona gente[], int tam);
int altaPersona(ePersona gente[], int tam, int legajo);
int bajaPersona(ePersona gente[], int tam);
int modificarPersona(ePersona gente[], int tam);
int buscarPersona(ePersona gente[], int tam, int legajo);
int harcodearPersonas(ePersona gente[], int tam, int cantidad);//esto es para harcodear pero no anda mi funcion.
int ordenarPersonasNombre(ePersona gente[], int tam, int criterio);
int ordenarPersonasSexoAltura(ePersona gente[], int tam, int criterioS, int criterioA);//funcion de prueba y practica

char menu();

int main()
{
    char seguir = 's';
    char confirma;
    int proximoLegajo=2000;
    int rta;
    ePersona lista[TAM];

    if(inicializarPersonas(lista, TAM) == 0)
    {
        printf("Personas inicializadas con exito!\n");
    }
    else
    {
        printf("Problema al inicializar personas...\n");
    }

    harcodearPersonas(lista, TAM, 5);
    proximoLegajo += 5;

    do
    {
        switch(menu())
        {

        case 'a':
            if(altaPersona(lista, TAM, proximoLegajo) == 0)
            {
                proximoLegajo++;
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("Problema para realizar el alta.\n\n");
            }

            break;
        case 'b':
            rta = bajaPersona(lista, TAM);
            if(rta == 0)
            {
                printf("Baja exitosa!!!\n\n");
            }
            else if(rta == 2)
            {
                printf("La baja se ha cancelado por el usuario.\n\n");
            }
            else
            {
                printf("Se ha producido un error en la baja\n\n");
            }

            break;
        case 'c':
            rta = modificarPersona(lista, TAM);
            if(rta == 0)
            {
                printf("Modificacion exitosa!!!\n\n");
            }
            else if(rta == 2)
            {
                printf("La modificacion se ha cancelado por el usuario.\n\n");
            }
            else
            {
                printf("Se ha producido un error en la modificacion\n\n");
            }

            break;
        case 'd':
            system("cls");
            mostrarPersonas(lista, TAM);

            break;
        case 'e':
            if(ordenarPersonasNombre(lista, TAM, ASC))
            {
                printf("Hubo un problema al intentar ordenar las personas.\n\n");
            }
            else
            {
                printf("\n Personas ordenadas con exito!!!\n\n");
            }

            break;
        case 'f':

            break;
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
    printf("a Alta\n");
    printf("b Baja\n");
    printf("c Modificacion\n");
    printf("d Listar\n");
    printf("e Ordenar\n");
    printf("f Informes\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

int inicializarPersonas(ePersona gente[], int tam)// setea el campo isEmpty en 1.
{
    int error = 1;

    if(gente != NULL && tam > 0) //para validar un vector, se pregunta si el nombre del vector es distinto de NULL.
    {
        for(int i=0; i<tam; i++)
        {
            gente[i].isEmpty = 1;
        }
        error = 0;
    }

    return error;
}

void mostrarPersona(ePersona unaPersona) // nombre de la estructura y tipo de variable que va a recibir
{
    printf(" %d   %10s  %c  %3.2f %02d/%02d/%02d", unaPersona.legajo, unaPersona.nombre, unaPersona.sexo, unaPersona.altura, unaPersona.fNac.dia, unaPersona.fNac.mes, unaPersona.fNac.anio);
}

int mostrarPersonas(ePersona gente[], int tam) //falta pulir esta funcion para que lo muestre todo bien
{
    int error=1;
    int flag = 0;

    if(gente!=NULL && tam>0)
    {
        printf(" Legajo Nombre Sexo Altura Fecha Nacimiento\n");
        printf("-------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(gente[i].isEmpty == 0)
            {
                mostrarPersona(gente[i]);
                flag = 1; // para saber si hubo personas cargadas o no
            }
            //printf(" %d %s %c %.2f\n", gente[i].legajo, gente[i].nombre, gente[i].sexo, gente[i].altura);
        }
        if(flag == 0) // creo que este if va adenrto del for anterior VER
        {
            printf("No hay personas en la lista");
        }
        printf("\n\n");

        int error = 0; //
    }
    return error;
}

int ordenarPersonasNombre(ePersona gente[], int tam, int criterio) //burbujeo sobre el array para ordenar. El aux tiene que ser tipo struct
{
    int error=1;
    ePersona auxPersona;
    if(gente != NULL && tam>0 && criterio >= 0 && criterio <= 1)
    {

        for(int i=0; i<tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(gente[i].nombre, gente[j].nombre) > 0 && criterio) //aca en vez de swapear campo x campo, se swapea estructuras enteras directo
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }//si quiero ordenar alfabeticamente comparo cadenas de caract, comparo las cadenas con "strcmp"
                else if(strcmp(gente[i].nombre, gente[j].nombre) < 0 && !criterio)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }
        error = 0;
    }
    return error;
}

int buscarLibre(ePersona gente[], int tam) //devuelve el N° del primer indice q encuentre libre. Si esta lleno devuelve un -1.
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(gente[i].isEmpty == 1)
        {
            indice = i;
            break; //Porq si ya encontro un espacio libre debe terminar de recorrer el vector. Funcionaria igual pero rinde mal
        }          // con el "break;" rompes la iteracion y te vas, total ya conseguiste lo que querias
    }
    return indice;
}

int altaPersona(ePersona gente[], int tam, int legajo)//Si devuelve 0, todo ok. dio de alta. Si devuelve 1, falló el alta.
{
    //FALLA
    int error = 1;
    int indice;
    ePersona nuevaPersona;

    if(gente != NULL && tam > 0 && legajo > 0)
    {
        system("cls");
        printf("**** Alta de Persona ****\n");

        indice = buscarLibre(gente, tam);
        printf("%d", indice);// esto tiro para ver que onda
        system("pause");//esto tiro para ver que onda
        if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }
        else
        {
            nuevaPersona.legajo = legajo;
            nuevaPersona.isEmpty = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevaPersona.sexo);

            printf("Ingrese altura: ");
            scanf("%f", &nuevaPersona.altura);

            printf("Ingrese fecha de nacimiento dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevaPersona.fNac.dia, &nuevaPersona.fNac.mes, &nuevaPersona.fNac.anio);

            gente[indice] = nuevaPersona;
            error = 0;
        }
    }

    return error;
}

int buscarPersona(ePersona gente[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(gente[i].legajo == legajo && gente[i].isEmpty == 0)
        {
            int indiceLibre = i;
            break;
        }
    }
    return indice;
}

int bajaPersona(ePersona gente[], int tam) //corregir codigo
{
    int error = 1;
    int legajo;
    int indice;
    char confirma;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Baja de Persona *** \n\n");
        mostrarPersonas(gente, tam);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(gente, tam, legajo);

        if(indice == -1)
        {
            printf("No existe una persona con ese legajo\n");
        }
        else
        {
            mostrarPersona(gente[indice]);
            printf("Confirma baja? ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                gente[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                //error=2;
                printf("La baja se ha cancelado por el usuario.\n\n");
            }
        }
    }

    return error;
}

int modificarPersona(ePersona gente[], int tam)//Corregir codigo
{
    int error = 1;
    int legajo;
    int indice;
    char confirma;
    eFecha nuevaFecha;

    if(gente != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Baja de Persona *** \n\n");
        mostrarPersonas(gente, tam);
        printf("Ingrese el legajo: ");
        scanf("%d", &legajo);

        indice = buscarPersona(gente, tam, legajo);

        if(indice == -1)
        {
            printf("No existe una persona con ese legajo\n");
        }
        else
        {
            mostrarPersona(gente[indice]);

            printf("\nIngrese nueva fecha de nacimiento: ");
            scanf("%d/%d/%d", &nuevaFecha.dia, &nuevaFecha.mes, &nuevaFecha.anio);

            printf("Confirma modificacion? ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                gente[indice].fNac = nuevaFecha;
                error = 0;
            }
            else
            {
                error = 2;
                //printf("La baja se ha cancelado por el usuario.\n\n");
            }
        }
    }

    return error;
}

int harcodearPersonas(ePersona gente[], int tam, int cantidad)
{
    int error=1;

    if(gente != NULL && tam > 0 && cantidad >= 0 && cantidad<= tam)
    {
        for(int i=0; i<tam; i++)
        {
            gente[i].legajo = legajos[i];
            strcpy(gente[i].nombre, nombres[i]);
            gente[i].sexo = sexos[i];
            gente[i].altura = alturas[i];
            gente[i].fNac.dia = dias[i];
            gente[i].fNac.mes = meses[i];
            gente[i].fNac.anio = anios[i];
            gente[i].isEmpty = 0;
        }
        error = 0;
    }

    return error;
}

int ordenarPersonasSexoAltura(ePersona gente[], int tam, int criterioS, int criterioA) //ordenarPersonasSexoAltura(lista, TAM, DESC, ASC) /DESC o ASC
{
    int error=1;
    ePersona auxPersona;
    if(gente != NULL && tam>0 && criterioS >= 0 && criterioS <= 1 && criterioA >=0 && criterioA <= 1)
    {

        for(int i=0; i<tam -1; i++)
        {
            for(int j=i+1; j<tam; j++)//cuando dos pers comparten el primer criterio, desempata el segundo criterio
            {
                if(gente[i].sexo > gente[j].sexo && criterioS == 1) //ordena por mayor o menor segun codigo ascii de la m o f
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }//si quiero ordenar alfabeticamente comparo cadenas de caract, comparo las cadenas con "strcmp"
                else if(gente[i].sexo < gente[j].sexo && criterioS == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].sexo == gente[j].sexo && gente[i].altura > gente[j].altura && criterioA == 1)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
                else if(gente[i].sexo == gente[j].sexo && gente[i].altura < gente[j].altura && criterioA == 0)
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }
        error = 0;
    }
    return error;
}


