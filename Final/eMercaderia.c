#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eMercaderia.h"

eMercaderia* eMercaderia_nuevo(){

     eMercaderia* this;

     if(this=(eMercaderia*)malloc(sizeof(eMercaderia)));

     return this;
}

int eMercaderia_setProducto(eMercaderia *this, int producto){
    this->producto=producto;

}
int eMercaderia_getProducto(eMercaderia *this){
    return this->producto;
}

char *eMercaderia_setDescripcion(eMercaderia *this, char *descripcion){
    strcpy(this->descripcion,descripcion);
}

char *eMercaderia_getDescripcion(eMercaderia *this){
    return this->descripcion;
}

int eMercaderia_setCantidad(eMercaderia *this, int cantidad){
    this->cantidad=cantidad;
}
int eMercaderia_getCantidad(eMercaderia *this){
    return this->cantidad;
}
