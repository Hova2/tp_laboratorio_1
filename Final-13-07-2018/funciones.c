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
        case 3:
            printf("La lista no contiene productos!!!\n");
            break;
        case 4:
            printf("El producto no existe!!!\n");
            break;
        case 5:
            printf("El producto ingresado es invalido!!!\n");
            break;
        case 6:
            printf("La cantidad debe ser mayor a cero!!!\n");
            break;
        case 7:
            printf("La cantidad ingresada es invalida!!!\n");
            break;
        case 8:
            printf("El producto no tiene la cantidad necesaria para poder descontar!!!\n");
            break;
        case 9:
            printf("El deposito origen no tiene productos!!!\n");
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

int parsearArchivo(ArrayList *lista, char *nombreArchivo){

    FILE* pArchivo;
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

int guardarArchivo(ArrayList *lista, char *nombreArchivo){
    FILE* pArchivo;
    int salida=0;

    pArchivo=fopen(nombreArchivo,"w");
    if(pArchivo){
        if(fprintf(pArchivo,"%s,%s,%s\n","PRODUCTO","DESCRIPCION","CANTIDAD")>0){
            int len=lista->len(lista);
            if(len>0){
                for(int i=0;i<len;i++){
                    eMercaderia *auxMercaderia=(eMercaderia*)lista->get(lista,i);
                    if(fprintf(pArchivo,"%d,%s,%d\n",eMercaderia_getProducto(auxMercaderia),eMercaderia_getDescripcion(auxMercaderia),eMercaderia_getCantidad(auxMercaderia))>0){
                        salida++;
                    }
                }
            }
        }
        fclose(pArchivo);
    }

    return salida;

}

char buscarRepetidos(ArrayList *lista, int len){
    char salida=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            eMercaderia *auxMercaderia1=(eMercaderia*)lista->get(lista,i);
            eMercaderia *auxMercaderia2=(eMercaderia*)lista->get(lista,j);
            if(eMercaderia_getProducto(auxMercaderia1)==eMercaderia_getProducto(auxMercaderia2)){
                salida=1;
                break;
            }
        }
    }
    return salida;
}

char buscarRepetidosEntreLosDos(ArrayList *lista1,int len1,ArrayList *lista2,int len2){
    char salida=0;
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            eMercaderia *auxMercaderia1=(eMercaderia*)lista1->get(lista1,i);
            eMercaderia *auxMercaderia2=(eMercaderia*)lista2->get(lista2,j);
            if(eMercaderia_getProducto(auxMercaderia1)==eMercaderia_getProducto(auxMercaderia2)){
                salida=1;
                break;
            }
        }
    }
    return salida;
}

void cargarDepositos(ArrayList *lista1,ArrayList *lista2){
    int salida1=parsearArchivo(lista1,ARCHIVO1);
    int salida2=parsearArchivo(lista2,ARCHIVO2);

    system("cls");

    if(salida1 && salida2){
        int len1=lista1->len(lista1);
        int len2=lista2->len(lista2);
        if(buscarRepetidos(lista1,len1)){
            printf("Se encontraron productos repetidos en el archivo 1. No se pueden cargar los archivos\n\n");
            lista1->clear(lista1);
            lista2->clear(lista2);
        }else{
            if(buscarRepetidos(lista2,len2)){
                printf("Se encontraron productos repetidos en el archivo 2. No se pueden cargar los archivo\n\n");
                lista1->clear(lista1);
                lista2->clear(lista2);
            }else{
                if(buscarRepetidosEntreLosDos(lista1,len1,lista2,len2)){
                    printf("Se encontraron productos que estan cargados en los dos archivos. No se pueden cargar los archivo\n\n");
                    lista1->clear(lista1);
                    lista2->clear(lista2);
                }else{
                    printf("Se cargaron %d registros correctamente del archivo 1\n\n",salida1);
                    printf("Se cargaron %d registros correctamente del archivo 2\n\n",salida2);
                }
            }
        }
    }else if(salida1){
        int len1=lista1->len(lista1);
        if(buscarRepetidos(lista1,len1)){
            printf("Se encontraron productos repetidos en el archivo 1. No se pueden cargar los archivos\n\n");
            lista1->clear(lista1);
            lista2->clear(lista2);
        }else{
            printf("Se cargaron %d registros correctamente del archivo 1\n\n",salida1);
            printf("El archivo 2 no contiene registros\n\n");
        }
    }else if(salida2){
        int len2=lista2->len(lista2);
        if(buscarRepetidos(lista2,len2)){
            printf("Se encontraron productos repetidos en el archivo 2. No se pueden cargar los archivos\n\n");
            lista1->clear(lista1);
            lista2->clear(lista2);
        }else{
            printf("Se cargaron %d registros correctamente del archivo 2\n\n",salida2);
            printf("El archivo 1 no contiene registros\n\n");
        }
    }else{
        printf("Los archivos no contienen registros\n\n");
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
        system("pause");
    }else{
        imprimirError(3);
    }

    return;
}

void listarProductosDeposito(ArrayList *lista1, ArrayList *lista2){
    int opcion=0;
    char seguir='s';

    while(seguir=='s'){
        system("cls");
        fflush(stdin);

        printf("Ingrese el numero de deposito para listar los productos: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                system("cls");
                printf("-----------------------------------------\n");
                printf(" La lista de productos del deposito 1 es\n");
                printf("-----------------------------------------\n");
                imprimirListaProductoDeposito(lista1);
                seguir = 'n';
                break;
            case 2:
                system("cls");
                printf("-----------------------------------------\n");
                printf(" La lista de productos del deposito 2 es\n");
                printf("-----------------------------------------\n");
                imprimirListaProductoDeposito(lista2);
                seguir = 'n';
                break;
            default:
                imprimirError(1);
                break;
            }
    }

    return;
}

int buscarProducto(ArrayList *lista, int producto){
    int len=lista->len(lista);
    int salida=-1;
    if(len>0){
        for(int i=0;i<len;i++){
            eMercaderia *auxMercaderia=(eMercaderia *)lista->get(lista,i);
            if(eMercaderia_getProducto(auxMercaderia)==producto){
                salida=i;
            }
        }
    }else{
        imprimirError(3);
    }

    return salida;
}

void moverProductoDeposito(ArrayList *lista1, ArrayList *lista2){
    int opcion=0;
    int origen=0;
    int destino=0;
    char seguir='s';

    while(seguir=='s'){
        system("cls");
        fflush(stdin);

        printf("Ingrese el numero de deposito origen para mover un producto: ");
        scanf("%d",&origen);

        system("cls");
        fflush(stdin);

        printf("Ingrese el numero de deposito destino para mover un producto: ");
        scanf("%d",&destino);

        if(origen==1 && destino==2){
            opcion=1;
        }else if(origen==2 && destino==1){
            opcion=2;
        }

        switch(opcion){
            case 1:
                if(!lista1->isEmpty(lista1)){
                    moverProducto(lista1,lista2);
                }else{
                    imprimirError(9);
                }
                seguir = 'n';
                break;
            case 2:
                if(!lista2->isEmpty(lista2)){
                    moverProducto(lista2,lista1);
                }else{
                    imprimirError(9);
                }
                seguir = 'n';
                break;
            default:
                imprimirError(1);
                break;
            }
    }

    guardarArchivo(lista1,ARCHIVO1);
    guardarArchivo(lista2,ARCHIVO2);

    return;
}

void moverProducto(ArrayList *origen, ArrayList *destino){
    char *dato;
    int *producto;
    int indice=0;
    char seguir='s';

    while(seguir=='s'){
        system("cls");
        printf("---------------------------------------------\n");
        printf(" La lista de productos del deposito origen es\n");
        printf("---------------------------------------------\n");
        imprimirListaProductoDeposito(origen);

        system("cls");
        fflush(stdin);

        printf("Ingrese el numero de producto que se quiere mover: ");
        dato=leerDatoPorPantalla();

        if(producto=(int *)validarYFormatearDato(dato,5,6)){
            if((indice=buscarProducto(origen,*producto))!=-1){
                eMercaderia *auxMercaderia=(eMercaderia*)origen->pop(origen,indice);
                destino->add(destino,auxMercaderia);
                seguir='n';
            }else{
                imprimirError(4);
            }
        }else{
            imprimirError(5);
        }
    }
    return;
}

void descontarProducto(ArrayList *lista,int indice){
    char *dato;
    int *cantidad;
    char seguir='s';

    while(seguir=='s'){
        system("cls");
        fflush(stdin);

        printf("Ingrese la cantidad que se quiere descontar: ");
        dato=leerDatoPorPantalla();

        if(cantidad=(int *)validarYFormatearDato(dato,5,6)){
            if(*cantidad>0){
                eMercaderia *auxMercaderia=(eMercaderia *)lista->get(lista,indice);
                int diferencia=eMercaderia_getCantidad(auxMercaderia)-*cantidad;
                if(diferencia>=0){
                    eMercaderia_setCantidad(auxMercaderia,diferencia);
                    lista->set(lista,indice,auxMercaderia);
                    seguir='n';
                }else{
                    imprimirError(8);
                    seguir='n';
                }
            }else{
                imprimirError(6);
            }
        }else{
            imprimirError(7);
        }
    }

    return;
}

void descontarProductosDeposito(ArrayList *lista1, ArrayList *lista2){
    char *dato;
    int *producto;
    int indice=0;
    char seguir='s';

    while(seguir=='s'){
        system("cls");
        printf("-------------------------------------------\n");
        printf(" La lista de productos del deposito 1 es\n");
        printf("-------------------------------------------\n");
        imprimirListaProductoDeposito(lista1);
        system("cls");
        printf("-------------------------------------------\n");
        printf(" La lista de productos del deposito 2 es\n");
        printf("-------------------------------------------\n");
        imprimirListaProductoDeposito(lista2);

        system("cls");
        fflush(stdin);

        printf("Ingrese el numero de producto: ");
        dato=leerDatoPorPantalla();
        if(producto=(int *)validarYFormatearDato(dato,5,6)){
            if((indice=buscarProducto(lista1,*producto))!=-1){
                descontarProducto(lista1,indice);
                seguir='n';
            }else if((indice=buscarProducto(lista2,*producto))!=-1){
                descontarProducto(lista2,indice);
                seguir='n';
            }else{
                imprimirError(4);
            }
        }else{
            imprimirError(5);
        }
    }

    guardarArchivo(lista1,ARCHIVO1);
    guardarArchivo(lista2,ARCHIVO2);

    return;
}

void agregarProducto(ArrayList *lista,int indice){
    char *dato;
    int *cantidad;
    char seguir='s';

    while(seguir=='s'){
        system("cls");
        fflush(stdin);

        printf("Ingrese la cantidad que se quiere agregar: ");
        dato=leerDatoPorPantalla();

        if(cantidad=(int *)validarYFormatearDato(dato,5,6)){
            if(*cantidad>0){
                eMercaderia *auxMercaderia=(eMercaderia *)lista->get(lista,indice);
                int suma=eMercaderia_getCantidad(auxMercaderia)+*cantidad;
                eMercaderia_setCantidad(auxMercaderia,suma);
                lista->set(lista,indice,auxMercaderia);
                seguir='n';
            }else{
                imprimirError(6);
            }
        }else{
            imprimirError(7);
        }
    }

    return;
}

void agregarProductosDeposito(ArrayList *lista1, ArrayList *lista2){
    char *dato;
    int *producto;
    int indice=0;
    char seguir='s';

    while(seguir=='s'){
        system("cls");
        printf("-------------------------------------------\n");
        printf(" La lista de productos del deposito 1 es\n");
        printf("-------------------------------------------\n");
        imprimirListaProductoDeposito(lista1);
        system("cls");
        printf("-------------------------------------------\n");
        printf(" La lista de productos del deposito 2 es\n");
        printf("-------------------------------------------\n");
        imprimirListaProductoDeposito(lista2);

        system("cls");
        fflush(stdin);

        printf("Ingrese el numero de producto: ");
        dato=leerDatoPorPantalla();
        if(producto=(int *)validarYFormatearDato(dato,5,6)){
            if((indice=buscarProducto(lista1,*producto))!=-1){
                agregarProducto(lista1,indice);
                seguir='n';
            }else if((indice=buscarProducto(lista2,*producto))!=-1){
                agregarProducto(lista2,indice);
                seguir='n';
            }else{
                imprimirError(4);
            }
        }else{
            imprimirError(5);
        }
    }

    guardarArchivo(lista1,ARCHIVO1);
    guardarArchivo(lista2,ARCHIVO2);

    return;
}
