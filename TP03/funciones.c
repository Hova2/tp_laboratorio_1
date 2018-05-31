/**
 * @brief Archivo de implementacion de funciones (Parcial).
 *
 * El archivo contiene las implementaciones de todas las funciones del parcial.
 * @file funciones.c
 * @author Juan Ignacio Guglielmone
 * @date 08/05/2018
 *
*/

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "propietario.h"
#include "auto.h"

void inisializarRecaudaciones(ERecaudaciones *recaudaciones){
    (*recaudaciones).recMarca1=0;
    (*recaudaciones).recMarca2=0;
    (*recaudaciones).recMarca3=0;
    (*recaudaciones).recMarca4=0;
}

void imprimirOpcionMenu(int opcion){

    switch(opcion){
        case 1:
            printf("1 - Agregar propietario\n");
            break;
        case 2:
            printf("2 - Modificar propietario\n");
            break;
        case 3:
            printf("3 - Baja propietario\n");
            break;
        case 4:
            printf("4 - Agregar auto\n");
            break;
        case 5:
            printf("5 - Egreso de auto\n");
            break;
        case 6:
            printf("6 - Recaudacion total\n");
            break;
        case 7:
            printf("7 - Recaudacion total por marca\n");
            break;
        case 8:
            printf("8 - Listado de autos de un propietario\n");
            break;
        case 9:
            printf("9 - Propietarios con autos AUDI estacionados\n");
            break;
        case 10:
            printf("10- Listado de autos estacionados\n");
            break;
        case 11:
            printf("11- Salir\n");
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
        case 15:
            printf("La patente tiene que comezar con 3 letras y seguir con 3 numeros!!!!\n");
            break;
        case 16:
            printf("El nombre y apellido no puede tener mas de 50 letras!!!!\n");
            break;
        case 17:
            printf("La direccion no puede tener mas de 75 letras!!!!\n");
            break;
        case 18:
            printf("La tarjeta debe tener 20 numeros!!!!\n");
            break;
        case 19:
            printf("La patente debe tener 6 caracteres!!!!\n");
            break;
        case 20:
            printf("La marca ingresada es incorrecta!!!!\n");
            break;
        case 21:
            printf("La patente no existe!!!!\n");
            break;
     }
     system("pause");
}

void imprimirAutosDePropietario(EAuto listaAuto[],int idPropietario){

    if(exitePropietarioConAuto(listaAuto,idPropietario)){
        int indice=0;
        printf("Patente - Marca\n\n");
        do{
            if(listaAuto[indice].idPropietario==idPropietario && (strcmp(listaAuto[indice].patente,"0")!=0)){
                printf("%s  - ",listaAuto[indice].patente);
                switch(listaAuto[indice].marca){
                    case 1:
                        printf("%s\n",MARCA1);
                        break;
                    case 2:
                        printf("%s\n",MARCA2);
                        break;
                    case 3:
                        printf("%s\n",MARCA3);
                        break;
                    case 4:
                        printf("%s\n",MARCA4);
                        break;
                }
            }
        }
        while(++indice<CAUTO);
    }else{
        printf("El propietario no tiene autos estacionados!!!\n");
    }

}

void agregarPropietario(EPropietario lista[]){
    char *idPropietario=NULL;
    char *nya=NULL;
    char *direccion=NULL;
    char *tarjeta=NULL;

    int indice=obtenerPropietarioLibre(lista);

    if(indice!=-1){
        while(!idPropietario || !nya || !direccion || !tarjeta){
        system("cls");
        fflush(stdin);
        printf("Cargar persona:\n");
        if(idPropietario){
            printf("ID Propietario: %s\n",idPropietario);
        }else{
            idPropietario=malloc(sizeof(char) * TDATO);
            printf("Ingrese ID Propietario: ");
            if(leerValidarDato(idPropietario,5)){
                strtok(idPropietario, "\n");
                int auxIdPropietario=atoi(idPropietario);
                if(auxIdPropietario>0){
                    if(buscarPropietario(lista,auxIdPropietario)==-1){
                        lista[indice].idPropietario=auxIdPropietario;
                    }else{
                        idPropietario=borrarPuntero(idPropietario);
                        imprimirError(5);
                    }
                }else{
                    idPropietario=borrarPuntero(idPropietario);
                    imprimirError(8);
                }
            }else{
                idPropietario=borrarPuntero(idPropietario);
                imprimirError(2);
            }
        }
        if(nya){
            printf("Nombre y apellido: %s\n",nya);
        }else{
            nya=malloc(sizeof(char) * TDATO);
            printf("Ingrese nombre y apellido: ");
            if(leerValidarDato(nya,2)){
                strtok(nya, "\n");
                int tam=strlen(nya);
                if(tam<=TNYA){
                    strcpy(lista[indice].nya,formatearNombre(nya,tam));
                }else{
                    nya=borrarPuntero(nya);
                    imprimirError(16);
                }

            }else{
                nya=borrarPuntero(nya);
                imprimirError(1);
            }
        }
        if(direccion){
            printf("Direccion: %s\n",direccion);
        }else{
            direccion=malloc(sizeof(char) * TDATO);
            printf("Ingrese direccion: ");
            if(leerValidarDato(direccion,4)){
                strtok(direccion, "\n");
                if(strlen(direccion)<=TDIRE){
                    strcpy(lista[indice].direccion,direccion);
                }else{
                    direccion=borrarPuntero(direccion);
                    imprimirError(17);
                }
            }else{
                direccion=borrarPuntero(direccion);
                imprimirError(3);
            }
        }
        if(tarjeta){
            printf("Tarjeta: %s\n",tarjeta);
        }else{
            tarjeta=malloc(sizeof(char) * TDATO);
            printf("Ingrese tarjeta: ");
            if(leerValidarDato(tarjeta,5)){
                strtok(tarjeta, "\n");
                if(strlen(tarjeta)==TTARJETA){
                    strcpy(lista[indice].tarjeta,tarjeta);
                }else{
                    tarjeta=borrarPuntero(tarjeta);
                    imprimirError(18);
                }
            }else{
                tarjeta=borrarPuntero(tarjeta);
                imprimirError(4);
            }
        }
        system("pause");
    }
        free(idPropietario);
        free(nya);
        free(direccion);
        free(tarjeta);
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
        while(!patente || !marca || !idPropietario){
        system("cls");
        fflush(stdin);
        printf("Cargar auto:\n");
        if(patente){
            printf("Patente: %s\n",patente);
        }else{
            patente=malloc(sizeof(char) * TDATO);
            printf("Ingrese patente: ");
            if(leerValidarDato(patente,3)){
                strtok(patente, "\n");
                if(strlen(patente)==TPATENTE){
                    if(strcmp(patente,"0")){
                        patente=formatearPatente(patente);
                        if(validarPatente(patente)){
                            if(buscarAuto(lista,patente)==-1){
                                strcpy(lista[indice].patente,patente);
                            }else{
                                patente=borrarPuntero(patente);
                                imprimirError(10);
                            }
                        }else{
                            patente=borrarPuntero(patente);
                            imprimirError(15);
                        }
                    }else{
                        patente=borrarPuntero(patente);
                        imprimirError(11);
                    }
                }else{
                    patente=borrarPuntero(patente);
                    imprimirError(19);
                }
            }else{
                patente=borrarPuntero(patente);
                imprimirError(12);
            }
        }
        if(marca){
            int auxMarca=atoi(marca);
            switch(auxMarca){
                case 1:
                        printf("Marca: %s\n",MARCA1);
                        break;
                case 2:
                        printf("Marca: %s\n",MARCA2);
                        break;
                case 3:
                        printf("Marca: %s\n",MARCA3);
                        break;
                case 4:
                        printf("Marca: %s\n",MARCA4);
                        break;
            }
        }else{
            marca=malloc(sizeof(char) * TDATO);
            printf("Ingrese marca 1-ALPHA ROMERO, 2-FERRARI, 3-AUDI, 4-OTRO: ");
            if(leerValidarDato(marca,5)){
                strtok(marca, "\n");
                int auxMarca=atoi(marca);
                if(auxMarca>0 && auxMarca<5){
                    lista[indice].marca=auxMarca;
                }else{
                    marca=borrarPuntero(marca);
                    imprimirError(14);
                }
            }else{
                marca=borrarPuntero(marca);
                imprimirError(20);
            }

        }
        if(idPropietario){
            printf("ID Propietario: %s\n",idPropietario);
        }else{
            idPropietario=malloc(sizeof(char) * TDATO);
            printf("Ingrese ID Propietario: ");
            if(leerValidarDato(idPropietario,5)){
                strtok(marca, "\n");
                int auxIdPropietario=atoi(idPropietario);
                if(auxIdPropietario>0){
                    if(buscarPropietario(listaPropietario,auxIdPropietario)!=-1){
                        lista[indice].idPropietario=auxIdPropietario;
                }else{
                    idPropietario=borrarPuntero(idPropietario);
                    imprimirError(7);
                }
                }else{
                    idPropietario=borrarPuntero(idPropietario);
                    imprimirError(8);
                }
            }else{
                idPropietario=borrarPuntero(idPropietario);
                imprimirError(2);
            }
        }
        system("pause");
    }
        free(patente);
        free(marca);
        free(idPropietario);
    }else{
        imprimirError(13);
    }
}

void modificarPropietario(EPropietario lista[]){
    char *idPropietario=NULL;
    char *tarjeta=NULL;
    int indice;
    while(!idPropietario || !tarjeta){
        fflush(stdin);
        system("cls");
        printf("Modificar tarjeta del propietario\n");
        if(idPropietario){
            printf("ID Propietario: %s\n",idPropietario);
            if((indice=buscarPropietario(lista,atoi(idPropietario)))!=-1){
                tarjeta=malloc(sizeof(char) * TDATO);
                printf("Ingrese tarjeta: ");
                if(leerValidarDato(tarjeta,5)){
                    strtok(tarjeta, "\n");
                    if(strlen(tarjeta)==TTARJETA){
                        strcpy(lista[indice].tarjeta,tarjeta);
                    }else{
                        tarjeta=borrarPuntero(tarjeta);
                        imprimirError(18);
                    }
                }else{
                    tarjeta=borrarPuntero(tarjeta);
                    imprimirError(4);
                }
            }else{
                idPropietario=borrarPuntero(idPropietario);
                imprimirError(7);
            }
        }else{
            idPropietario=malloc(sizeof(char) * TDATO);
            printf("Ingrese ID Propietario: ");
            if(leerValidarDato(idPropietario,5)){
                strtok(idPropietario, "\n");
                if(!(atoi(idPropietario)>0)){
                    idPropietario=borrarPuntero(idPropietario);
                    imprimirError(8);
                }
            }else{
                idPropietario=borrarPuntero(idPropietario);
                imprimirError(2);
            }
        }
    }
    free(idPropietario);
    free(tarjeta);
}

void bajaPropietario(EPropietario lista[], EAuto listaAuto[], ERecaudaciones *recaudaciones){
    char *idPropietario=NULL;
    int indice;
    while(!idPropietario){
        fflush(stdin);
        system("cls");
        printf("Baja de propietario\n");
        idPropietario=malloc(sizeof(char) * TDATO);
        printf("Ingrese ID Propietario: ");
        if(leerValidarDato(idPropietario,5)){
            strtok(idPropietario, "\n");
            int auxIdPropietario=atoi(idPropietario);
            if(auxIdPropietario>0){
                if((indice=buscarPropietario(lista,auxIdPropietario))!=-1){
                    lista[indice].idPropietario=0;
                    printf("Baja exitosa!!!!\n");
                    int total=bajaAutoAutomatica(listaAuto,auxIdPropietario,recaudaciones);
                    if(total){
                        printf("El total que el propietario debe abonar es: %d\n",total);
                    }else{
                        printf("El propietario no debe abonar nada, porque no tiene autos estacionados!!!!\n");
                    }
                }else{
                    idPropietario=borrarPuntero(idPropietario);
                    imprimirError(7);
                }
            }else{
                idPropietario=borrarPuntero(idPropietario);
                imprimirError(8);
            }
        }else{
            idPropietario=borrarPuntero(idPropietario);
            imprimirError(2);
        }
    }
    free(idPropietario);
    system("pause");
    return;
}

void bajaAutoManual(EAuto listaAuto[], EPropietario listaPropietario[],ERecaudaciones *recaudaciones){
    char *patente=NULL;
    int indice;
    while(!patente){
        fflush(stdin);
        system("cls");
        printf("Egreso de auto\n");
        patente=malloc(sizeof(char) * TDATO);
        printf("Ingrese la patente del auto: ");
        if(leerValidarDato(patente,3)){
            strtok(patente, "\n");
            if(strlen(patente)==TPATENTE){
                if(strcmp(patente,"0")){
                    patente=formatearPatente(patente);
                    if(validarPatente(patente)){
                        if((indice=buscarAuto(listaAuto,patente))!=-1){
                            int indicePropietario=buscarPropietario(listaPropietario, listaAuto[indice].idPropietario);
                            printf("El propietario es: %s\n",listaPropietario[indicePropietario].nya);
                            printf("La patente es: %s\n",listaAuto[indice].patente);
                            int total;
                            switch(listaAuto[indice].marca){
                                case 1:
                                    printf("Marca: %s\n",MARCA1);
                                    total=(devolverHorasEstadia() * 150);
                                    (*recaudaciones).recMarca1+=total;
                                    break;
                                case 2:
                                    printf("Marca: %s\n",MARCA2);
                                    total=(devolverHorasEstadia() * 175);
                                    (*recaudaciones).recMarca2+=total;
                                    break;
                                case 3:
                                    printf("Marca: %s\n",MARCA3);
                                    total=(devolverHorasEstadia() * 200);
                                    (*recaudaciones).recMarca3+=total;
                                    break;
                                case 4:
                                    printf("Marca: %s\n",MARCA4);
                                    total=(devolverHorasEstadia() * 250);
                                    (*recaudaciones).recMarca4+=total;
                                    break;
                            }
                            printf("El valor de la estadia es: %d\n",total);
                            strcpy(listaAuto[indice].patente,"0");
                            printf("Baja exitosa!!!!\n");
                        }else{
                            patente=borrarPuntero(patente);
                            imprimirError(21);
                        }
                    }else{
                        patente=borrarPuntero(patente);
                        imprimirError(15);
                    }
                }else{
                    patente=borrarPuntero(patente);
                    imprimirError(11);
                }
            }else{
                patente=borrarPuntero(patente);
                imprimirError(19);
            }
        }else{
            patente=borrarPuntero(patente);
            imprimirError(12);
        }
    }
    free(patente);
    system("pause");
    return;
}

void recaudacionTotal(int total){
    system("cls");
    if(total){
        printf("La recaudacion total es: %d\n",total);
    }else{
        printf("Actualmente no hay recaudacion\n");
    }
    system("pause");
}

void recaudacionTotalPorMarca(int marca1,int marca2,int marca3,int marca4){
    system("cls");
    if(marca1){
        printf("La recaudacion de los autos de la marca %s es: %d\n",MARCA1,marca1);
    }else{
        printf("Nunca se estacionaron autos de la marca %s\n",MARCA1);
    }
    if(marca2){
        printf("La recaudacion de los autos de la marca %s es: %d\n",MARCA2,marca2);
    }else{
        printf("Nunca se estacionaron autos de la marca %s\n",MARCA2);
    }
    if(marca3){
        printf("La recaudacion de los autos de la marca %s es: %d\n",MARCA3,marca3);
    }else{
        printf("Nunca se estacionaron autos de la marca %s\n",MARCA3);
    }
    if(marca4){
        printf("La recaudacion de los autos que pertenecen a otras marcas es: %d\n",marca4);
    }else{
        printf("Nunca se estacionaron autos de otras marcas\n");
    }
    system("pause");
}

void imprimirPropietario(EPropietario listaPropietario[],EAuto listaAuto[]){
    char *idPropietario=NULL;
    int indice;
    while(!idPropietario){
        fflush(stdin);
        system("cls");
        printf("Listar autos de un propietario\n");
        idPropietario=malloc(sizeof(char) * TDATO);
        printf("Ingrese ID Propietario: ");
        if(leerValidarDato(idPropietario,5)){
            strtok(idPropietario, "\n");
            int auxIdPropietario=atoi(idPropietario);
            if(auxIdPropietario>0){
                if((indice=buscarPropietario(listaPropietario,auxIdPropietario))!=-1){
                    printf("El nombre del propietario es: %s\n\n",listaPropietario[indice].nya);
                    imprimirAutosDePropietario(listaAuto,auxIdPropietario);
                }else{
                    idPropietario=borrarPuntero(idPropietario);
                    imprimirError(7);
                }
            }else{
                idPropietario=borrarPuntero(idPropietario);
                imprimirError(8);
            }
        }else{
            idPropietario=borrarPuntero(idPropietario);
            imprimirError(2);
        }
    }
    free(idPropietario);
    system("pause");
    return;
}

void imprimirAutosAudi(EPropietario listaPropietario[],EAuto listaAuto[]){
    system("cls");
    printf("Lista de propietarios con autos de la marca %s:\n\n",MARCA3);

    if(exiteAutoAudi(listaAuto)){
        int indiceAuto=0;
        printf("ID - Nombre y apellido - Direccion - Tarjeta\n\n");
        do{
            if(listaAuto[indiceAuto].marca==3 && (strcmp(listaAuto[indiceAuto].patente,"0")!=0)){
                int indicePropietario=0;
                do{
                    if(listaPropietario[indicePropietario].idPropietario==listaAuto[indiceAuto].idPropietario && listaPropietario[indicePropietario].idPropietario!=0){
                        printf("%d  - ",listaPropietario[indicePropietario].idPropietario);
                        printf("%s  - ",listaPropietario[indicePropietario].nya);
                        printf("%s  - ",listaPropietario[indicePropietario].direccion);
                        printf("%s\n",listaPropietario[indicePropietario].tarjeta);
                    }
                }while(++indicePropietario<CPROPIETARIO);
            }
        }while(++indiceAuto<CAUTO);
    }else{
        printf("No existen propietarios con autos %s estacionados!!!\n",MARCA3);
    }
    system("pause");
}

void imprimirAutosOrdenados(EPropietario listaPropietario[],EAuto listaAuto[]){
    system("cls");
    printf("Listado de autos estacionados:\n\n");
    ordenarAuto(listaAuto);
    int indice=0;
    do{
        if(listaPropietario[indice].idPropietario!=0){
           if(exitePropietarioConAuto(listaAuto,listaPropietario[indice].idPropietario)){
                printf("ID: %d  - ",listaPropietario[indice].idPropietario);
                printf("Nombre y Apellido: %s  - ",listaPropietario[indice].nya);
                printf("Direccion: %s  - ",listaPropietario[indice].direccion);
                printf("Tarjeta: %s\n\n",listaPropietario[indice].tarjeta);
                imprimirAutosDePropietario(listaAuto,listaPropietario[indice].idPropietario);
                printf("\n\n");
           }
        }
    }while(++indice<CPROPIETARIO);
    system("pause");
    return;

}

char* borrarPuntero(char *dato){
     free(dato);
     return NULL;
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

char *formatearNombre(char *dato, int tam){
    char *aux=malloc(sizeof(char) * TDATO);
    int cont=1;
    aux=dato;
    *aux=toupper(*aux);
    while(cont<tam){
        ++aux;
        cont++;
        if(*aux==' '){
            ++aux;
            cont++;
            *aux=toupper(*aux);
        }else{
            *aux=tolower(*aux);
        }
    }

    return dato;
}

char *formatearPatente(char *dato){
    char *aux=malloc(sizeof(char) * TDATO);
    int cont=0;
    aux=dato;
    do{
        *aux=toupper(*aux);
        cont++;
        aux++;
    }while(cont<TPATENTE);
    return dato;
}

char validarPatente(char *dato){
    char *aux=malloc(sizeof(char) * TDATO);
    int cont=0;
    aux=dato;
    do{
        if(!(cont<3 && isalpha(*aux))){
            if(!(cont>=3)){
                return 0;
            }else{
                if(!isdigit(*aux)){
                    return 0;
                }
            }
        }
        cont++;
        aux++;
    }while(cont<TPATENTE);

    return 1;
}

int bajaAutoAutomatica(EAuto lista[],int idPropietario,ERecaudaciones *recaudaciones){
    int indice=0;
    int acum=0;

    do{
        if(lista[indice].idPropietario==idPropietario && (strcmp(lista[indice].patente,"0")!=0)){
            int subToral;
            switch(lista[indice].marca){
                case 1:
                        subToral=(devolverHorasEstadia() * 150);
                        (*recaudaciones).recMarca1+=subToral;
                        acum+=subToral;
                        break;
                case 2:
                        subToral=(devolverHorasEstadia() * 175);
                        (*recaudaciones).recMarca2+=subToral;
                        acum+=subToral;
                        break;
                case 3:
                        subToral=(devolverHorasEstadia() * 200);
                        (*recaudaciones).recMarca3+=subToral;
                        acum+=subToral;
                        break;
                case 4:
                        subToral=(devolverHorasEstadia() * 250);
                        (*recaudaciones).recMarca4+=subToral;
                        acum+=subToral;
                        break;
            }
            strcpy(lista[indice].patente, "0");
        }
    }while(++indice<CPROPIETARIO);

    return acum;
}

int devolverHorasEstadia(){
    int horas;
    srand(time(NULL));
    horas = (rand()%24)+1;

    return horas ;

}
