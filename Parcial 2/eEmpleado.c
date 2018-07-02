#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "eEmpleado.h"

eEmpleado* eEmpleado_nuevo(void){

    eEmpleado* returnAux = (eEmpleado*)malloc(sizeof(eEmpleado));
    return returnAux;
}

int eEmpleado_compararEmpleado(void* pEmpleadoA,void* pEmpleadoB){

    if(strcmp(((eEmpleado*)pEmpleadoA)->nombre,((eEmpleado*)pEmpleadoB)->nombre) > 0){
        return 1;
    }
    if(strcmp(((eEmpleado*)pEmpleadoA)->nombre,((eEmpleado*)pEmpleadoB)->nombre) < 0){
        return 0;
    }
    return 0;
}

void eEmpleado_Imprimir(eEmpleado* this){
    printf("Id: %d - Nombre:%s - Direccion:%s - Sueldo:%d\n",eEmpleado_getId(this),eEmpleado_getNombre(this),eEmpleado_getDireccion(this),eEmpleado_getSueldo(this));
}

int eEmpleado_calcularSueldo(void* pEmpleado){

    int resultado=1;

    if(pEmpleado){

        if(eEmpleado_getHoras((eEmpleado*)pEmpleado) >=80 && eEmpleado_getHoras((eEmpleado*)pEmpleado) <120){
            eEmpleado_setSueldo((eEmpleado*)pEmpleado,eEmpleado_getHoras((eEmpleado*)pEmpleado)*180);
        }else if(eEmpleado_getHoras((eEmpleado*)pEmpleado) >=120 && eEmpleado_getHoras((eEmpleado*)pEmpleado) <160){
            eEmpleado_setSueldo((eEmpleado*)pEmpleado,eEmpleado_getHoras((eEmpleado*)pEmpleado)*240);
        }else if(eEmpleado_getHoras((eEmpleado*)pEmpleado) >=160 && eEmpleado_getHoras((eEmpleado*)pEmpleado) <240){
            eEmpleado_setSueldo((eEmpleado*)pEmpleado,eEmpleado_getHoras((eEmpleado*)pEmpleado)*350);
        }else{
            resultado=0;
        }
        printf("\n");

    }else{
        resultado=0;
    }
    return resultado;
}

int eEmpleado_setId(eEmpleado* this, int id){
    this->id=id;
}

int eEmpleado_getId(eEmpleado* this){
    return this->id;
}

int eEmpleado_setHoras(eEmpleado* this, int horas){
    this->horas=horas;
}

int eEmpleado_getHoras(eEmpleado* this){
    return this->horas;
}

int eEmpleado_setSueldo(eEmpleado* this, int sueldo){
    this->sueldo=sueldo;
}

int eEmpleado_getSueldo(eEmpleado* this){
    return this->sueldo;
}

char *eEmpleado_setNombre(eEmpleado *this, char *nombre){
        strcpy(this->nombre,nombre);
}

char *eEmpleado_getNombre(eEmpleado* this){
    return this->nombre;
}

char *eEmpleado_setDireccion(eEmpleado* this, char *direccion){
    strcpy(this->direccion,direccion);
}

char *eEmpleado_getDireccion(eEmpleado* this){
    return this->direccion;
}
