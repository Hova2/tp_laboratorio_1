#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eReparto.h"

eReparto* eReparto_nuevo(){

     eReparto* this;

     if(this=(eReparto*)malloc(sizeof(eReparto)));

     return this;
}


char *eReparto_setDireccion(eReparto*, char*);
char *eReparto_getDireccion(eReparto*);

char *eReparto_setLocalidad(eReparto*, char*);
char *eReparto_getLocalidad(eReparto*);

char *eReparto_setRecibe(eReparto*, char*);
char *eReparto_getRecibe(eReparto*);

int eReparto_setId(eReparto *this, int id){
    this->id=id;

}
int eReparto_getId(eReparto *this){
    return this->id;
}

char* eReparto_setProducto(eReparto *this, char *producto){
    strcpy(this->producto,producto);

}
char* eReparto_getProducto(eReparto *this){
    return this->producto;
}

char* eReparto_setDireccion(eReparto *this, char *direccion){
    strcpy(this->direccion,direccion);

}
char* eReparto_getDireccion(eReparto *this){
    return this->direccion;
}

char* eReparto_setLocalidad(eReparto *this, char *localidad){
    strcpy(this->localidad,localidad);

}
char* eReparto_getLocalidad(eReparto *this){
    return this->localidad;
}
char* eReparto_setRecibe(eReparto *this, char *recibe){
    strcpy(this->recibe,recibe);

}
char* eReparto_getRecibe(eReparto *this){
    return this->recibe;
}

int comparar(void *reparto,char *localidad){
    int salida=0;

    char *auxLocalidad=eReparto_getLocalidad((eReparto *)reparto);

    if(strcmp(auxLocalidad,localidad)==0){
        salida=1;
    }

    return salida;
}
