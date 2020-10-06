#include <stdio.h>
#include <stdlib.h>

////RELACIONES//// Relaciones con una base de datos a traves de una tabla. Cada fila de una tabla se le llama "tupla"
/*cada fila de la tabla es una persona, en cada celda de la fila va un campo, un atributo de esa persona. Cada fila seria una
estructura, y toda la tabla seria un array de estructuras.
*/


int main()
{

    return 0;
}

/*
isAlpha(), para validar si es una caracter, devuelve 1 si es caracter o 0 si no lo es
isDigit(), lo mismo pero para digitos
isSpace(), lo mismo pero para espacios
*/

                //Original
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


                //bis
                if((list[i].sector < list[j].sector && order == 1)
                        || (list[i].sector > list[j].sector && order == 0))
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                else if((strcmp(list[i].lastName, list[j].lastName) > 0 && order == 1)
                        || (strcmp(list[i].lastName, list[j].lastName) < 0 && order == 0)
                        )
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                else if((list[i].sector == list[j].sector)







int sortEmployees(ePersona gente[], int tam, int criterioS, int criterioA) //ordenarPersonasSexoAltura(lista, TAM, DESC, ASC) /DESC o ASC
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
