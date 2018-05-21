/**
 * @brief Archivo de implementaciones de funciones de auto (Parcial).
 *
 * El archivo contiene las implementaciones de todas las funciones de auto del parcial.
 * @file auto.c
 * @author Juan Ignacio Guglielmone
 * @date 08/05/2018
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "auto.h"

void inisializarAuto(EAuto lista[]){
    int indice=0;

    while(strcpy(lista[indice].patente, "0") && ++indice<CAUTO);
}

void ordenarAuto(EAuto listaAuto[]){
    int indiceUno=0;

    do{
        int indiceDos;
        if((indiceDos=indiceUno+1)<19){
            do{
                if((strcmp(listaAuto[indiceUno].patente,"0")!=0) && (strcmp(listaAuto[indiceDos].patente,"0")!=0)){
                    if(strcmp(listaAuto[indiceDos].patente,listaAuto[indiceUno].patente)<0){
                        EAuto auxAuto;
                        auxAuto=listaAuto[indiceUno];
                        listaAuto[indiceUno]=listaAuto[indiceDos];
                        listaAuto[indiceDos]=auxAuto;
                    }
                }
            }while(++indiceDos<CAUTO);
        }
    }
    while(++indiceUno<CAUTO);

    return;
}

char existenAutoCargado(EAuto lista[]){
    int indice=0;

    while((strcmp(lista[indice].patente,"0")==0) && ++indice<CAUTO);

    if(indice<CAUTO){
        return 1;
    }

    return 0;
}

char exitePropietarioConAuto(EAuto listaAuto[],int idPropietario){
    int indice=0;

    do{
        if(listaAuto[indice].idPropietario==idPropietario && (strcmp(listaAuto[indice].patente,"0")!=0)){
            return 1;
        }
    }
    while(++indice<CAUTO);

    return 0;
}

char exiteAutoAudi(EAuto listaAuto[]){
    int indice=0;

    do{
        if(listaAuto[indice].marca==3 && (strcmp(listaAuto[indice].patente,"0")!=0)){
            return 1;
        }
    }
    while(++indice<CAUTO);

    return 0;
}

int obtenerAutoLibre(EAuto lista[]){
    int indice=0;

    while(!(strcmp(lista[indice].patente,"0")==0) && ++indice<CAUTO);

    if(indice<CAUTO){
        return indice;
    }else{
        return -1;
    }
}

int buscarAuto(EAuto lista[], char *patente){
    int indice=0;

    while(strcmp(lista[indice].patente, patente) && ++indice<CAUTO);

    if(indice<CAUTO){
        return indice;
    }else{
        return -1;
    }
}
