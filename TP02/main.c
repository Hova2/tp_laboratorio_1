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

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
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
        }
        system("pause");
    }
    return 0;
}
