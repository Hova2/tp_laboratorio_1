#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "eMercaderia.h"

int parserEmpleado(FILE* pArchivo, ArrayList *lista, char *nombreArchivo){

    int salida=0;
    int memoria=1;
    char* var1=(char *)malloc(sizeof(char)*TDATO);
    char* var2=(char *)malloc(sizeof(char)*TDATO);
    char* var3=(char *)malloc(sizeof(char)*TDATO);

    if(!(var1 && var2 && var3)){
        memoria=0;
    }

    pArchivo=fopen(nombreArchivo,"r");

    if(pArchivo && memoria){
        if(fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",var1,var2,var3)>0){
            while(!feof(pArchivo)){
                if(fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",var1,var2,var3)>0){
                    void *auxProducto=validarYFormatearDato(var1,5,6);
                    void *auxDescripcion=validarYFormatearDato(var2,4,3);
                    void *auxCantidad=validarYFormatearDato(var3,5,6);

                    if(auxProducto && auxDescripcion && auxCantidad){
                        eMercaderia *auxMercaderia=eMercaderia_nuevo();
                        eMercaderia_setProducto(auxMercaderia,*(int *)auxProducto);
                        eMercaderia_setDescripcion(auxMercaderia,(char *)auxDescripcion);
                        eMercaderia_setCantidad(auxMercaderia,*(int *)auxCantidad);
                        lista->add(lista,auxMercaderia);
                        free(auxProducto);
                        free(auxCantidad);
                        salida++;
                    }
                }
            }
        }
        fclose(pArchivo);
    }
    if(memoria){
        free(var1);
        free(var2);
        free(var3);
    }

    return salida;
}
