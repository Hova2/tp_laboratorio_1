#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "propietario.h"
#include "auto.h"
#include "propietarioauto.h"

void main(){

    char seguir='s';
    int opcion=0;
    EPropietario propietarios[CPROPIETARIO];
    EAuto autos[CAUTO];

    inisializarPropietario(propietarios);
    inisializarAuto(autos);

    while(seguir=='s')
    {
        system("cls");
        fflush(stdin);

        printf("1- Agregar propietario\n");
        printf("2- Modificar propietario\n");
        printf("3- Baja propietario\n");
        printf("4- Agregar auto\n");
        printf("5- Egreso auto\n\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPropietario(propietarios);
                break;
            case 2:
                modificarPropietario(propietarios);
                break;
            case 3:
                bajaPropietario(propietarios);
                break;
            case 4:
                agregarAuto(autos,propietarios);
                break;
            case 5:
                bajaAuto(autos,propietarios);
                system("pause");
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }
    return;
}
