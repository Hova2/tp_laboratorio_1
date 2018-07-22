#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "eMercaderia.h"
#define ARCHIVO1 "./bd/dep0.csv"
#define ARCHIVO2 "./bd/dep1.csv"

void imprimirOpcionMenu(int opcion){

    switch(opcion){
        case 1:
            printf("1 - Cargar depositos\n");
            break;
        case 2:
            printf("2 - Listar productos de deposito\n");
            break;
        case 3:
            printf("3 - Mover productos a deposito\n");
            break;
        case 4:
            printf("4 - Descontar productos de deposito\n");
            break;
        case 5:
            printf("5 - Agregar productos de deposito\n");
            break;
        case 6:
            printf("6 - Salir\n");
            break;
    }

    return;
}

void imprimirError(int codigo){
     switch(codigo){
        case 1:
            printf("La opcion ingresada es incorrecta!!!!\n");
            break;
        case 2:
            printf("Los archivos de deposito ya se encuentran cargados!!!!\n");
            break;
     }
     system("pause");
}



char *leerDatoPorPantalla(){
    char *salida=malloc(sizeof(char) * TDATO);

    if(salida){
        fflush(stdin);
        fgets(salida, TDATO, stdin);
    }

    return salida;
}

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
                    if (!((*aux >= '0' && *aux <= '9') || (*aux=='.') || (*aux=='\n'))){
                        salida=0;
                    }else{
                        if(*aux=='.'){
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

    return salida;
}

void *formatearDato(char *dato,char tipo){

    strtok(dato, "\n");

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
                salida=(void *)dato;
                break;
            case 2:
                while(cont<tam){
                    *aux=tolower(*aux);
                     aux++;
                     cont++;
                }
                salida=(void *)dato;
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
                salida=(void *)dato;
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
                salida=(void *)dato;
                break;
            case 5:
                salida=(void *)dato;
                break;
        }
    }else if(tipo==6){
        int *pEntero=malloc(sizeof(int));
        if(pEntero){
            *pEntero=atoi(dato);
            salida=(void *)pEntero;
        }
    }else if(tipo==7){
        double *pFlotante=malloc(sizeof(double));
        if(pFlotante){
            *pFlotante=atof(dato);
            salida=(void *)pFlotante;
        }
    }

    return salida;
}

void *validarYFormatearDato(char *dato,char tipoVal,char tipoFor){
    void *salida=NULL;

    if(validarDato(dato,tipoVal)){
        salida=formatearDato(dato,tipoFor);
    }

    return salida;
}

int parser(FILE* pArchivo, ArrayList *lista, char *nombreArchivo){

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

void cargarDepositos(ArrayList *lista1,ArrayList *lista2){
    FILE* pArchivo;
    int salida1=parser(pArchivo,lista1,ARCHIVO1);
    int salida2=parser(pArchivo,lista2,ARCHIVO2);

    system("cls");

    if(salida1){
        printf("Se cargaron %d registros correctamente del archivo 1\n\n",salida1);
    }else{
        printf("El archivo 1 no contenia registros\n\n");
    }
    if(salida2){
        printf("Se cargaron %d registros correctamente del archivo 2\n\n",salida2);
    }else{
        printf("El archivo 2 no contenia registros\n\n");
    }

    system("pause");

    return;
}

void imprimirListaProductoDeposito(ArrayList *lista){
    int len=lista->len(lista);
    if(len>0){
        printf ("%s%15s%s\n", "Producto | ", "Descripcion", "     | Cantidad");
        printf("-----------------------------------------\n");
        for(int i=0; i<len;i++){
            eMercaderia *auxMercaderia=(eMercaderia *)lista->get(lista,i);
            printf ("%-8d | %-15.15s     | %8d\n",eMercaderia_getProducto(auxMercaderia), eMercaderia_getDescripcion(auxMercaderia), eMercaderia_getCantidad(auxMercaderia));
        }
    }else{
        printf("La lista no contiene productos");
    }

    system("pause");
    return;
}

void listarProductosDeposito(ArrayList *lista1, ArrayList *lista2){
    char seguir='s';
    int opcion=0;

    while(seguir=='s'){
        system("cls");
        fflush(stdin);

        printf("1 - Listar productos del deposito 1\n");
        printf("2 - Listar productos del deposito 2\n");
        imprimirOpcionMenu(6);

        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                system("cls");
                printf("-----------------------------------------\n");
                printf(" La lista de productos del deposito 1 es\n");
                printf("-----------------------------------------\n");
                imprimirListaProductoDeposito(lista1);
                break;
            case 2:
                system("cls");
                printf("-----------------------------------------\n");
                printf(" La lista de productos del deposito 2 es\n");
                printf("-----------------------------------------\n");
                imprimirListaProductoDeposito(lista2);
                break;
            case 6:
                seguir = 'n';
                break;
            default:
                imprimirError(1);
                break;
            }
    }
    return;
}

