#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "funciones.h"

void inisializarListaMovie(EMovie lista[]){
    int indice=0;

    while(!(lista[indice].id=0) && ++indice<TARREGLO);
}

int obtenerMovieLibre(EMovie lista[]){
    int indice=0;

    while(lista[indice].id && ++indice<TARREGLO);

    if(indice<TARREGLO){
        return indice;
    }else{
        return -1;
    }
}

int contarElementos(EMovie lista[]){
    int cont=0;
    for(int i=0;i<TARREGLO;i++){
        if(lista[i].id){
            cont++;
        }
    }
    if(cont){
        return cont;
    }
    return cont;
}
