#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "propietario.h"

void inisializarPropietario(EPropietario lista[]){
    int indice=0;

    while(!(lista[indice].idPropietario=0) && ++indice<CPROPIETARIO);
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
