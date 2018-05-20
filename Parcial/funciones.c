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

void bajaPropietario(EPropietario lista[], EAuto listaAuto[]){
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
                    int total=bajaAutoAutomatica(listaAuto,auxIdPropietario);
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
}

void bajaAutoManual(EAuto listaAuto[], EPropietario listaPropietario[]){
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
                             switch(listaAuto[indice].marca){
                                case 1:
                                    printf("Marca: %s\n",MARCA1);
                                    printf("El valor de la estadia es: %d\n",(devolverHorasEstadia() * 150));
                                    break;
                                case 2:
                                    printf("Marca: %s\n",MARCA2);
                                    printf("El valor de la estadia es: %d\n",(devolverHorasEstadia() * 175));
                                    break;
                                case 3:
                                    printf("Marca: %s\n",MARCA3);
                                    printf("El valor de la estadia es: %d\n",(devolverHorasEstadia() * 200));
                                    break;
                                case 4:
                                    printf("Marca: %s\n",MARCA4);
                                    printf("El valor de la estadia es: %d\n",(devolverHorasEstadia() * 250));
                                    break;
                            }
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
}

int devolverHorasEstadia(){
    int horas;
    srand(time(NULL));
    horas = (rand()%24)+1;

    return horas ;

}

int bajaAutoAutomatica(EAuto lista[],int idPropietario){
    int indice=0;
    int acum=0;

    do{
        if(lista[indice].idPropietario==idPropietario && (strcmp(lista[indice].patente,"0")!=0)){
            switch(lista[indice].marca){
                case 1:
                        acum+=(devolverHorasEstadia() * 150);
                        break;
                case 2:
                        acum+=(devolverHorasEstadia() * 175);
                        break;
                case 3:
                        acum+=(devolverHorasEstadia() * 200);
                        break;
                case 4:
                        acum+=(devolverHorasEstadia() * 250);
                        break;
            }
            strcpy(lista[indice].patente, "0");
        }
    }while(++indice<CPROPIETARIO);

    return acum;
}
