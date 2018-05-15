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

    while(seguir=='s'){

        if(!existenPropietarioCargado(propietarios)){
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(6);
            imprimirOpcionMenu(10);

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    agregarPropietario(propietarios);
                    break;
                case 6:
                    break;
                case 10:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(14);
                    break;
            }
        }else{
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(2);
            imprimirOpcionMenu(3);
            imprimirOpcionMenu(4);

            if(!existenAutoCargado(autos)){
                imprimirOpcionMenu(6);
                imprimirOpcionMenu(10);

                scanf("%d",&opcion);

                switch(opcion){
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
                    case 6:
                        break;
                    case 10:
                        seguir = 'n';
                        break;
                    default:
                        imprimirError(14);
                        break;
                }
            }
            else{
                imprimirOpcionMenu(5);
                imprimirOpcionMenu(6);
                imprimirOpcionMenu(7);
                imprimirOpcionMenu(8);
                imprimirOpcionMenu(9);
                imprimirOpcionMenu(10);

                scanf("%d",&opcion);

                switch(opcion){
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
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 9:
                        break;
                    case 10:
                        seguir = 'n';
                        break;
                    default:
                        imprimirError(14);
                        break;
                }
            }
        }
    }

    return;
}
