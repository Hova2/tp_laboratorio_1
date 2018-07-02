#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "eEmpleado.h"

void cargarArreglo(ArrayList *lista){
    FILE* bd;
    int tmp;
    tmp=parserEmpleado(bd, lista);
}

void crearArchivoSueldo(ArrayList *lista){
    FILE* bd;
    bd=fopen("./sueldos.csv","w");
    if(bd){
        int tam=lista->len(lista);
        fprintf(bd,"ID,NOMBRE,DIRECCION,HORAS,SUELDO\n");
        for(int i=0;i<tam;i++){
            eEmpleado *empTmp=(eEmpleado*)lista->get(lista,i);
            fprintf(bd,"%d,%s,%s,%d,%d\n",eEmpleado_getId(empTmp),eEmpleado_getNombre(empTmp),eEmpleado_getDireccion(empTmp),eEmpleado_getHoras(empTmp),eEmpleado_getSueldo(empTmp));
        }
    }
    fclose(bd);

}
