#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#define TDATO 50

int parserEmpleado(FILE* pArchivo, ArrayList *lista, char *nombreArchivo){

    int salida=0;
    int memoria=1;
    char* var1=(char *)malloc(sizeof(char)*TDATO);
    char* var2=(char *)malloc(sizeof(char)*TDATO);
    char* var3=(char *)malloc(sizeof(char)*TDATO);
    char* var4=(char *)malloc(sizeof(char)*TDATO);

    if(!(var1 && var2 && var3 && var4)){
        memoria=0;
    }

    pArchivo=fopen(nombreArchivo,"r");

    if(pArchivo && memoria){
        if(fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4)){
            while(!feof(pArchivo)){
                if(fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4)){
//                    eEmpleado *empTmp=eEmpleado_nuevo();
  //                  eEmpleado_setId(empTmp,atoi(var1));
    //                eEmpleado_setNombre(empTmp,var2);
      //              eEmpleado_setDireccion(empTmp,var3);
        //            eEmpleado_setHoras(empTmp,atoi(var4));
          //          lista->add(lista,empTmp);
                    salida++;
                }
            }
        }
        fclose(pArchivo);
    }

    return salida;
}
