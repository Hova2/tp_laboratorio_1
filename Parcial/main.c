/**
 * @brief Archivo principal de la aplicaion (Parcial).
 *
 * El archivo contiene la funcion main(principal) del parcial.
 * @file main.c
 * @author Juan Ignacio Guglielmone
 * @date 08/05/2018
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "propietario.h"
#include "auto.h"

void main(){

    char seguir='s';
    int opcion=0;
    ERecaudaciones recaudaciones;
    EPropietario propietarios[CPROPIETARIO];
    EAuto autos[CAUTO];

    inisializarPropietario(propietarios);
    inisializarAuto(autos);
    inisializarRecaudaciones(&recaudaciones);

    //Datos hardcodeados
    /*propietarios[0].idPropietario=1;
    strcpy(propietarios[0].nya,"Juan Ignacio");
    strcpy(propietarios[0].direccion,"Tres arroyos 416 Depto D");
    strcpy(propietarios[0].tarjeta,"12345678912345678900");
    propietarios[5].idPropietario=30;
    strcpy(propietarios[5].nya,"Ignacio Juan");
    strcpy(propietarios[5].direccion,"Arroyos Tres  416 Depto D");
    strcpy(propietarios[5].tarjeta,"12345678900123456789");
    propietarios[10].idPropietario=15;
    strcpy(propietarios[10].nya,"Ignacio");
    strcpy(propietarios[10].direccion,"Arroyos 416 Depto D");
    strcpy(propietarios[10].tarjeta,"00123456789123456789");
    propietarios[3].idPropietario=20;
    strcpy(propietarios[3].nya,"Sin autos");
    strcpy(propietarios[3].direccion,"Tres 416 Depto D");
    strcpy(propietarios[3].tarjeta,"12345678912345670089");
    propietarios[15].idPropietario=100;
    strcpy(propietarios[15].nya,"Sin audi");
    strcpy(propietarios[15].direccion,"Casa 416 Depto D");
    strcpy(propietarios[15].tarjeta,"12345670089123456789");
    autos[0].idPropietario=30;
    strcpy(autos[0].patente,"QWE123");
    autos[0].marca=1;
    autos[2].idPropietario=30;
    strcpy(autos[2].patente,"ASD123");
    autos[2].marca=2;
    autos[5].idPropietario=30;
    strcpy(autos[5].patente,"XCV123");
    autos[5].marca=3;
    autos[7].idPropietario=30;
    strcpy(autos[7].patente,"ERT123");
    autos[7].marca=4;
    autos[10].idPropietario=30;
    strcpy(autos[10].patente,"GHJ123");
    autos[10].marca=3;
    autos[4].idPropietario=15;
    strcpy(autos[4].patente,"ZXC123");
    autos[4].marca=3;
    autos[1].idPropietario=15;
    strcpy(autos[1].patente,"SDF123");
    autos[1].marca=1;
    autos[15].idPropietario=1;
    strcpy(autos[15].patente,"PQW123");
    autos[15].marca=3;
    autos[19].idPropietario=100;
    strcpy(autos[19].patente,"BGT123");
    autos[19].marca=4;*/


    while(seguir=='s'){

        if(!existenPropietarioCargado(propietarios)){
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(6);
            imprimirOpcionMenu(7);
            imprimirOpcionMenu(11);

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    agregarPropietario(propietarios);
                    break;
                case 6:
                    recaudacionTotal(recaudaciones.recMarca1+recaudaciones.recMarca2+recaudaciones.recMarca3+recaudaciones.recMarca4);
                    break;
                case 7:
                    recaudacionTotalPorMarca(recaudaciones.recMarca1,recaudaciones.recMarca2,recaudaciones.recMarca3,recaudaciones.recMarca4);
                    break;
                case 11:
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
                imprimirOpcionMenu(7);
                imprimirOpcionMenu(11);

                scanf("%d",&opcion);

                switch(opcion){
                    case 1:
                        agregarPropietario(propietarios);
                        break;
                    case 2:
                        modificarPropietario(propietarios);
                        break;
                    case 3:
                        bajaPropietario(propietarios,autos,&recaudaciones);
                        break;
                    case 4:
                        agregarAuto(autos,propietarios);
                        break;
                    case 6:
                        recaudacionTotal(recaudaciones.recMarca1+recaudaciones.recMarca2+recaudaciones.recMarca3+recaudaciones.recMarca4);
                        break;
                     case 7:
                        recaudacionTotalPorMarca(recaudaciones.recMarca1,recaudaciones.recMarca2,recaudaciones.recMarca3,recaudaciones.recMarca4);
                        break;
                    case 11:
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
                imprimirOpcionMenu(11);

                scanf("%d",&opcion);

                switch(opcion){
                    case 1:
                        agregarPropietario(propietarios);
                        break;
                    case 2:
                        modificarPropietario(propietarios);
                        break;
                    case 3:
                        bajaPropietario(propietarios,autos,&recaudaciones);
                        break;
                    case 4:
                        agregarAuto(autos,propietarios);
                        break;
                    case 5:
                        bajaAutoManual(autos,propietarios,&recaudaciones);
                        break;
                    case 6:
                        recaudacionTotal(recaudaciones.recMarca1+recaudaciones.recMarca2+recaudaciones.recMarca3+recaudaciones.recMarca4);
                        break;
                    case 7:
                        recaudacionTotalPorMarca(recaudaciones.recMarca1,recaudaciones.recMarca2,recaudaciones.recMarca3,recaudaciones.recMarca4);
                        break;
                    case 8:
                        imprimirPropietario(propietarios,autos);
                        break;
                    case 9:
                        imprimirAutosAudi(propietarios,autos);
                        break;
                    case 10:
                        imprimirAutosOrdenados(propietarios,autos);
                        break;
                    case 11:
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
