#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "auto.h"

void inisializarAuto(EAuto lista[]){
    int indice=0;

    while(strcpy(lista[indice].patente, "0") && ++indice<CAUTO);
}

char existenAutoCargado(EAuto lista[]){
    int indice=0;

    while((strcmp(lista[indice].patente,"0")==0) && ++indice<CAUTO);

    if(indice<CAUTO){
        return 1;
    }

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
