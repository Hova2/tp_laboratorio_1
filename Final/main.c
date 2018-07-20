#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "parser.h"
#include "ArrayList.h"
#include "eMercaderia.h"
#define ARCHIVO1 "./bd/dep0.csv"
#define ARCHIVO2 "./bd/dep1.csv"

int main(){

    FILE* archivo;
    ArrayList *lista1=al_newArrayList();
    ArrayList *lista2=al_newArrayList();

    parserEmpleado(archivo,lista1,ARCHIVO1);
    parserEmpleado(archivo,lista2,ARCHIVO2);
    if(lista1->isEmpty(lista1)){
        printf("La lista esta vacia\n");
    }else{
        printf("La lista no esta vacia\n");
    }
    if(lista2->isEmpty(lista2)){
        printf("La lista esta vacia\n");
    }else{
        printf("La lista no esta vacia\n");
    }

    int tam=lista1->len(lista1);

    for(int i=0;i<tam;i++){
        printf("El numero de producto es: %d\n",eMercaderia_getProducto((eMercaderia *)lista1->get(lista1,i)));
        printf("La descripcion de producto es: %s\n",eMercaderia_getDescripcion((eMercaderia *)lista1->get(lista1,i)));
        printf("La cantidad que hay de producto es: %d\n",eMercaderia_getCantidad((eMercaderia *)lista1->get(lista1,i)));
        printf("\n");
    }


    return 0;
}
