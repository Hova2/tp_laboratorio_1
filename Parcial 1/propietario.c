/**
 * @brief Archivo de implementaciones de funciones de propietario (Parcial).
 *
 * El archivo contiene las implementaciones de todas las funciones de propietario del parcial.
 * @file propietario.c
 * @author Juan Ignacio Guglielmone
 * @date 08/05/2018
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "propietario.h"

void inisializarPropietario(EPropietario lista[]){
    int indice=0;

    while(!(lista[indice].idPropietario=0) && ++indice<CPROPIETARIO);
}

char existenPropietarioCargado(EPropietario lista[]){
    int indice=0;

    while((lista[indice].idPropietario==0) && ++indice<CPROPIETARIO);

    if(indice<CPROPIETARIO){
        return 1;
    }

    return 0;
}

int obtenerPropietarioLibre(EPropietario lista[]){
    int indice=0;

    while(lista[indice].idPropietario && ++indice<CPROPIETARIO);

    if(indice<CPROPIETARIO){
        return indice;
    }else{
        return -1;
    }
}

int buscarPropietario(EPropietario lista[], int idPropietario){
    int indice=0;

    while(!(lista[indice].idPropietario && lista[indice].idPropietario==idPropietario) && ++indice<CPROPIETARIO);

    if(indice<CPROPIETARIO){
        return indice;
    }else{
        return -1;
    }
}
