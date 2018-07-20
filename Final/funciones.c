#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#define TDATO 50

/*void cargarArreglo(ArrayList *lista){
    FILE* bd;
    int tmp;
    tmp=parserEmpleado(bd, lista);
}*/

/*void crearArchivoSueldo(ArrayList *lista){
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

}*/

char validarDato(char *dato,char tipo){

    char contPunto=0;
    char numero=0;
    char letra=0;
    char salida=1;
    char *aux=dato;

    if(*aux!='\n'){
        do{
            switch(tipo){
                case 1:
                    if (!((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z') || (*aux=='\n'))){
                        salida=0;
                    }
                    break;
                case 2:
                    if (!((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z') || (*aux==' ') || (*aux=='\n'))){
                        salida=0;
                    }
                    break;
                case 3:
                    if (!((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z') || (*aux >= '0' && *aux <= '9') || (*aux=='\n'))){
                        salida=0;
                    }else{
                        if((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z')){
                            letra=1;
                        }else{
                            if(*aux!='\n'){
                                numero=1;
                            }
                        }
                    }
                    break;
                case 4:
                    if (!((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z') || (*aux >= '0' && *aux <= '9') || (*aux==' ') || (*aux=='\n'))){
                        salida=0;
                    }else{
                        if((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z')){
                            letra=1;
                        }else{
                            if(*aux!=' ' && *aux!='\n'){
                                numero=1;
                            }
                        }
                    }
                    break;
                case 5:
                    if (!((*aux >= '0' && *aux <= '9') || (*aux=='\n'))){
                        salida=0;
                    }
                    break;
                case 6:
                    if (!((*aux >= '0' && *aux <= '9') || (*aux==',') || (*aux=='.') || (*aux=='\n'))){
                        salida=0;
                    }else{
                        if((*aux==',') || (*aux=='.')){
                            contPunto++;
                        }
                    }
                    break;
                case 7:
                    break;
            }
            if(!salida){
                break;
            }
        }while(*++aux!='\0');
        if(salida){
            if( ((tipo==3) || (tipo==4)) && !(letra && numero)){
                salida=0;
            }
            if((tipo==6) && !(contPunto<=1)){
                salida=0;
            }
        }
    }else{
        salida=0;
    }

    if(salida){
        strtok(dato, "\n");
    }

    return salida;
}

char *leerDato(){
    char *salida=malloc(sizeof(char) * TDATO);

    if(salida){
        fflush(stdin);
        fgets(salida, TDATO, stdin);
    }

    return salida;
}

void *formatearDato(char *dato,char tipo){

    void *salida;

    if(tipo>0 && tipo<6){
        char *aux=dato;
        int tam=strlen(dato);
        int cont=0;
        switch(tipo){
        case 1:
                while(cont<tam){
                    *aux=toupper(*aux);
                    aux++;
                    cont++;
                }
                salida=(void *)aux;
                break;
        case 2:
                while(cont<tam){
                    *aux=tolower(*aux);
                    aux++;
                    cont++;
                }
                salida=(void *)aux;
                break;
        case 3:
                *aux=toupper(*aux);
                aux++;
                cont++;
                while(cont<tam){
                    *aux=tolower(*aux);
                    aux++;
                    cont++;
                }
                salida=(void *)aux;
                break;
        case 4:
                *aux=toupper(*aux);
                aux++;
                cont++;
                while(cont<tam){
                    if(*aux==' '){
                        while(*aux==' ' && cont<tam){
                            aux++;
                            cont++;
                        }
                        if(cont<tam){
                            *aux=toupper(*aux);
                        }
                    }else{
                        *aux=tolower(*aux);
                    }
                    if(cont<tam){
                        aux++;
                        cont++;
                    }
                }
                salida=(void *)aux;
                break;
        case 5:
                salida=(void *)aux;
                break;
        }
    }else{
        if(tipo==6){
            int entero=atoi(dato);
            salida=(void *)&entero;
        }else if(tipo==7){
            double flotante=atof(dato);
            salida=(void *)&flotante;
        }
    }

    return salida;
}

char *formatearNombreArchivo(char *dato, int tam){
    char *aux=malloc(sizeof(char) * TDATO);
    int cont=1;
    strtok(dato, "\n");
    aux=dato;

    while(cont<tam){
        ++aux;
        cont++;
        *aux=tolower(*aux);
    }

    return dato;
}

