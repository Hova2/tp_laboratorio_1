#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eEmpleado.h"

int main(){
    ArrayList *lista=al_newArrayList();
    cargarArreglo(lista);
     ArrayList *listaTmp=al_clone(lista);

    int tam=listaTmp->len();



    /*for(int i=0;i<tam;i++){
        eEmpleado_Imprimir((eEmpleado*)listaTmp->get(lista,i));
    }*/

    listaTmp->sort(listaTmp,eEmpleado_compararEmpleado,1);

    //printf("\n");

    /*for(int i=0;i<tam;i++){
        eEmpleado_Imprimir((eEmpleado*)listaTmp->get(lista,i));
    }*/

     /*for(int i=0;i<tam;i++){
        eEmpleado_Imprimir((eEmpleado*)listaTmp->get(lista,i));
    }*/


    for(int i=0;i<tam;i++){
        eEmpleado_Imprimir((eEmpleado*)listaTmp->get(lista,i));
    }

    if(!listaTmp->map(listaTmp,eEmpleado_calcularSueldo)){
        printf("No se pudieron calcular los sueldos");
    }

    for(int i=0;i<tam;i++){
        eEmpleado_Imprimir((eEmpleado*)listaTmp->get(lista,i));
    }


    return 0;
}
