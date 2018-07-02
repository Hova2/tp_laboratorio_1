#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eEmpleado.h"

int parserEmpleado(FILE* pFile, ArrayList *lista){

    int auxPars=-1;

    pFile=fopen("./data.csv","r");

    if(pFile){
        char* var1=(char *)malloc(sizeof(char)*TDATO);
        char* var2=(char *)malloc(sizeof(char)*TDATO);
        char* var3=(char *)malloc(sizeof(char)*TDATO);
        char* var4=(char *)malloc(sizeof(char)*TDATO);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        while(!feof(pFile)){
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            eEmpleado *empTmp=eEmpleado_nuevo();
            eEmpleado_setId(empTmp,atoi(var1));
            eEmpleado_setNombre(empTmp,var2);
            eEmpleado_setDireccion(empTmp,var3);
            eEmpleado_setHoras(empTmp,atoi(var4));
            lista->add(lista,empTmp);
        }
    }
    fclose(pFile);
}
