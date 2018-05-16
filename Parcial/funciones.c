#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "propietario.h"
#include "auto.h"

void imprimirOpcionMenu(int opcion){

    switch(opcion){
        case 1:
            printf("1- Agregar propietario\n");
            break;
        case 2:
            printf("2- Modificar propietario\n");
            break;
        case 3:
            printf("3- Baja propietario\n");
            break;
        case 4:
            printf("4- Agregar auto\n");
            break;
        case 5:
            printf("5- Egreso de auto\n");
            break;
        case 6:
            printf("6- Recaudacion total\n");
            break;
        case 7:
            printf("7- Recaudacion total por marca\n");
            break;
        case 8:
            printf("8- Propietarios con autos AUDI estacionados\n");
            break;
        case 9:
            printf("9- Autos estacionados\n");
            break;
        case 10:
            printf("10- Salir\n");
            break;
    }

    return;
}

void imprimirError(int codigo){
     switch(codigo){
        case 1:
            printf("El nombre y apellido ingresados son incorrecto!!!!\n");
            break;
        case 2:
            printf("El ID ingresado es incorrecto!!!!\n");
            break;
        case 3:
            printf("La direccion ingresada es incorrecta!!!!\n");
            break;
        case 4:
            printf("La tarjeta ingresada es incorrecta!!!!\n");
            break;
        case 5:
            printf("El ID ya existe!!!!\n");
            break;
        case 6:
            printf("No hay mas espacio para cargar propietarios!!!!\n");
            break;
        case 7:
            printf("El ID no existe!!!!\n");
            break;
        case 8:
            printf("El ID debe ser mayor a 0!!!!\n");
            break;
        case 9:
            printf("La patente debe ser mayor a 0!!!!\n");
            break;
        case 10:
            printf("La patente ya existe!!!!\n");
            break;
        case 11:
            printf("La patente debe ser mayor a 0!!!!\n");
            break;
        case 12:
            printf("La patente ingresada es incorrecta!!!!\n");
            break;
        case 13:
            printf("No hay espacio para cargar autos!!!!\n");
            break;
        case 14:
            printf("La opcion ingresada es invalida!!!!\n");
            break;
     }
     system("pause");
}

void agregarPropietario(EPropietario lista[]){
    char *idPropietario=NULL;
    char *nya=NULL;
    char *direccion=NULL;
    char *tarjeta=NULL;

    int indice=obtenerPropietarioLibre(lista);

    if(indice!=-1){
        while(idPropietario==NULL || nya==NULL || direccion==NULL || tarjeta==NULL){
        system("cls");
        fflush(stdin);
        printf("Cargar persona:\n");
        if(idPropietario){
            printf("ID Propietario: %s\n",idPropietario);
        }else{
            idPropietario=malloc(sizeof(char) * TDATO);
            printf("Ingrese ID Propietario: ");
            if(leerValidarDato(idPropietario,5)){
                int auxIdPropietario=atoi(idPropietario);
                if(auxIdPropietario>0){
                    if(buscarPropietario(lista,auxIdPropietario)==-1){
                        lista[indice].idPropietario=auxIdPropietario;
                    }else{
                        free(idPropietario);
                        idPropietario=NULL;
                        imprimirError(5);
                    }
                }else{
                    free(idPropietario);
                    idPropietario=NULL;
                    imprimirError(8);
                }
            }else{
                free(idPropietario);
                idPropietario=NULL;
                imprimirError(2);
            }
        }
        if(nya){
            printf("Nombre y apellido: %s\n",nya);
        }else{
            nya=malloc(sizeof(char) * TDATO);
            printf("Ingrese nombre y apellido: ");
            if(leerValidarDato(nya,2)){
                strcpy(lista[indice].nya,formatearNombre(nya));
            }else{
                free(nya);
                nya=NULL;
                imprimirError(1);
            }
        }
        if(direccion){
            printf("Direccion: %s\n",direccion);
        }else{
            direccion=malloc(sizeof(char) * TDATO);
            printf("Ingrese direccion: ");
            if(leerValidarDato(direccion,4)){
                strcpy(lista[indice].direccion,direccion);
            }else{
                free(direccion);
                direccion=NULL;
                imprimirError(3);
            }
        }
        if(tarjeta){
            printf("Tarjeta: %s\n",tarjeta);
        }else{
            tarjeta=malloc(sizeof(char) * TDATO);
            printf("Ingrese tarjeta: ");
            if(leerValidarDato(tarjeta,5)){
                lista[indice].tarjeta=atoi(tarjeta);
            }else{
                free(tarjeta);
                tarjeta=NULL;
                imprimirError(4);
            }
        }
    }
        free(idPropietario);
        free(nya);
        free(direccion);
        free(tarjeta);
        system("pause");
    }else{
        imprimirError(6);
    }
}

void agregarAuto(EAuto lista[],EPropietario listaPropietario[]){
    char *patente=NULL;
    char *marca=NULL;
    char *idPropietario=NULL;

    int indice=obtenerAutoLibre(lista);

    if(indice!=-1){
        while(patente==NULL || marca==NULL || idPropietario==NULL){
        system("cls");
        fflush(stdin);
        printf("Cargar auto:\n");
        if(patente){
            printf("Patente: %s\n",patente);
        }else{
            patente=malloc(sizeof(char) * TDATO);
            printf("Ingrese patente: ");
            if(leerValidarDato(patente,3)){
                if(strcmp(patente,"0")){
                    patente=formatearPatente(patente);
                    if(buscarAuto(lista,patente)==-1){
                        strcpy(lista[indice].patente,patente);
                    }else{
                        free(patente);
                        patente=NULL;
                        imprimirError(10);
                    }
                }else{
                    free(patente);
                    patente=NULL;
                    imprimirError(11);
                }
            }else{
                free(patente);
                patente=NULL;
                imprimirError(12);
            }
        }
        if(marca){
            printf("Marca: %s\n",marca);
        }else{
            marca=malloc(sizeof(char) * TDATO);
            printf("Ingrese marca 1-ALPHA ROMERO, 2-FERRARI, 3-AUDI, 4-OTRO: ");
            int opcion;
            scanf("%d",&opcion);
            switch(opcion){
                case 1:
                        strcpy(marca,MARCA1);
                        break;
                case 2:
                        strcpy(marca,MARCA2);
                        break;
                case 3:
                        strcpy(marca,MARCA3);
                        break;
                case 4:
                        strcpy(marca,MARCA4);
                        break;
                default:
                        marca=NULL;
                        break;

            }
            if(marca){
                strcpy(lista[indice].marca,marca);
            }else{
                imprimirError(14);
            }
        }
        if(idPropietario){
            printf("ID Propietario: %s\n",idPropietario);
        }else{
            idPropietario=malloc(sizeof(char) * TDATO);
            printf("Ingrese ID Propietario: ");
            if(leerValidarDato(idPropietario,5)){
                int auxIdPropietario=atoi(idPropietario);
                if(auxIdPropietario>0){
                    if(buscarPropietario(listaPropietario,auxIdPropietario)!=-1){
                        lista[indice].idPropietario=auxIdPropietario;
                }else{
                    free(idPropietario);
                    idPropietario=NULL;
                    imprimirError(7);
                }
                }else{
                    free(idPropietario);
                    idPropietario=NULL;
                    imprimirError(8);
                }
            }else{
                free(idPropietario);
                idPropietario=NULL;
                imprimirError(2);
            }
        }
    }
        free(patente);
        free(marca);
        free(idPropietario);
        system("pause");
    }else{
        imprimirError(13);
    }
}

char *leerValidarDato(char *dato,char tipo){

    char contPunto=0;
    char numero=0;
    char letra=0;
    char *aux;

    fflush(stdin);

    aux=fgets(dato, TDATO, stdin);

    if(*aux!='\n'){
        do{

            switch(tipo){

            case 1:
                if (!((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z') || (*aux=='\n'))){
                    dato=NULL;
                }
                break;
            case 2:
                if (!((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z') || (*aux==' ') || (*aux=='\n'))){
                    dato=NULL;
                }
                break;
            case 3:
                if (!((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z') || (*aux >= '0' && *aux <= '9') || (*aux=='\n'))){
                    dato=NULL;
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
                    dato=NULL;
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
                    dato=NULL;
                }
                break;
            case 6:
                if (!((*aux >= '0' && *aux <= '9') || (*aux=='.') || (*aux=='\n'))){
                    dato=NULL;
                }else{
                    if(*aux=='.'){
                        contPunto++;
                    }
                }
                break;
            }
            if(!dato){
                break;
            }
        }while(*++aux!='\0');
        if(dato){
            if( ((tipo==3) || (tipo==4)) && !(letra && numero)){
                dato=NULL;
            }
            if((tipo==6) && !(contPunto<=1)){
                dato=NULL;
            }
        }
    }else{
        dato=NULL;
    }

    return dato;
}

char *formatearNombre(char *dato){
    char *aux=malloc(sizeof(char) * TDATO);
    aux=dato;
    *aux=toupper(*aux);
    while(*(++aux)!='\n'){
        if(*aux==' '){
            aux++;
            *aux=toupper(*aux);
        }else{
            *aux=tolower(*aux);
        }
    }

    return dato;
}

char *formatearPatente(char *dato){
    char *aux=malloc(sizeof(char) * TDATO);
    aux=dato;
    do{
        *aux=toupper(*aux);
    }while(*(++aux)!='\n');
    return dato;
}

void modificarPropietario(EPropietario lista[]){
    char *idPropietario=NULL;
    char *tarjeta=NULL;
    int indice;
    while(!idPropietario){
        system("cls");
        if(!idPropietario){
            idPropietario=malloc(sizeof(char) * TDATO);
            printf("Ingrese el ID a modificar: ");
            if(!leerValidarDato(idPropietario,5)){
                free(idPropietario);
                idPropietario=NULL;
                imprimirError(2);
            }
        }
    }

    if((indice=buscarPropietario(lista,atoi(idPropietario)))!=-1){
        tarjeta=malloc(sizeof(char) * TDATO);
        printf("Ingrese tarjeta: ");
        if(leerValidarDato(tarjeta,5)){
            lista[indice].tarjeta=atoi(tarjeta);
        }else{
            free(tarjeta);
            tarjeta=NULL;
            imprimirError(4);
        }
    }else{
           imprimirError(7);
    }
}

void bajaPropietario(EPropietario lista[]){
    char *idPropietario=NULL;
    int indice;
    while(!idPropietario){
        system("cls");
        if(!idPropietario){
            idPropietario=malloc(sizeof(char) * TDATO);
            printf("Ingrese el ID a borar: ");
            if(!leerValidarDato(idPropietario,5)){
                free(idPropietario);
                idPropietario=NULL;
                imprimirError(2);
            }
        }
    }

    if((indice=buscarPropietario(lista,atoi(idPropietario)))!=-1){
        lista[indice].idPropietario=0;
        printf("Se borro el id ingresado!!!\n");
        system("pause");
    }else{
           imprimirError(7);
    }
}

void bajaAuto(EAuto listaAuto[], EPropietario listaPropietario[]){
    char *patente=NULL;
    int indice;
    while(!patente){
        system("cls");
        if(!patente){
            patente=malloc(sizeof(char) * TDATO);
            printf("Ingrese la patente del auto: ");
            if(!leerValidarDato(patente,3)){
                free(patente);
                patente=NULL;
                imprimirError(12);
            }
        }
    }
    patente=formatearPatente(patente);
    if((indice=buscarAuto(listaAuto,patente))!=-1){
        int indicePropietario=buscarPropietario(listaPropietario, listaAuto[indice].idPropietario);
        printf("El propietario es: %s\n",listaPropietario[indicePropietario].nya);
        printf("La patente es: %s\n",listaAuto[indice].patente);
        printf("La marca es: %s\n",listaAuto[indice].marca);
        if(!(strcmp(listaAuto[indice].marca,MARCA1))){
            printf("El valor de la estadia es: %d\n",150 * devolverHorasEstadia());
        }
        if(!(strcmp(listaAuto[indice].marca,MARCA2))){
            printf("El valor de la estadia es: %d\n",175 * devolverHorasEstadia());
        }
        if(!(strcmp(listaAuto[indice].marca,MARCA3))){
            printf("El valor de la estadia es: %d\n",200 * devolverHorasEstadia());
        }
        if(!(strcmp(listaAuto[indice].marca,MARCA4))){
            printf("El valor de la estadia es: %d\n",250 * devolverHorasEstadia());
        }

        strcpy(listaAuto[indice].patente,"0");
        system("pause");

    }else{
           imprimirError(7);
    }
}

int devolverHorasEstadia(){
    int horas;
    srand(time(NULL));
    horas = (rand()%24)+1;

    return horas ;

}
