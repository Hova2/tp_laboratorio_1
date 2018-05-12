/**
 * @brief Archivo principal (TP02).
 *
 * El archivo contiene el main principal del TP02.
 * @file main.c
 * @author Juan Ignacio Guglielmone
 * @date 04/05/2018
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona listaPersona[TPERSONA];

    inisializarListaPersona(listaPersona);

    while(seguir=='s')
    {
        system("cls");
        fflush(stdin);
        opcion=0;

        if(existenPersonasCargadas(listaPersona)){
            printf("1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por nombre\n");
            printf("4- Imprimir grafico de edades\n\n");
            printf("5- Salir\n");

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    agregarPersona(listaPersona);
                    break;
                case 2:
                    borrarPersona(listaPersona);
                    break;
                case 3:
                    imprimirListaOrdenada(listaPersona);
                    break;
                case 4:
                    imprimirGrafico(listaPersona);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(9);
                    break;
            }
        }else{
            printf("1- Agregar persona\n");
            printf("5- Salir\n");

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    agregarPersona(listaPersona);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(9);
                    break;
            }
        }
    }
    return 0;
}
