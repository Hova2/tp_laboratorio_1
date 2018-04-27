#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int obtenerEspacioLibre(EPersona lista[]){
    int indice=0;

    while(lista[indice].estado && ++indice<TPERSONA);

    if(indice<TPERSONA){
        return indice;
    }else{
        return -1;
    }
}

int buscarPorDni(EPersona lista[], int dni){
    int indice=0;

    do{
        if(lista[indice].dni==dni && lista[indice].estado){
            break;
        }
    }while(++indice<TPERSONA);

    if(indice<TPERSONA){
        return indice;
    }else{
        return -1;
    }


    while(lista[indice].dni!=dni && ++indice<TPERSONA);

    if(indice<TPERSONA){
        return indice-1;
    }else{
        return -1;
    }
}

void inisializarListaPersona(EPersona lista[]){
    int indice=0;

    while(!(lista[indice].estado=0) && ++indice<TPERSONA);
}

void agregarPersona(EPersona lista[]){
    char *nombre=NULL;
    char *edad=NULL;
    char *dni=NULL;
    int indice=obtenerEspacioLibre(lista);

    if(indice!=-1){
        while(nombre==NULL || edad==NULL || dni==NULL){
        system("cls");
        fflush(stdin);
        printf("Cargar persona\n");
        if(nombre){
            printf("Nombre: %s\n",nombre);
        }else{
            nombre=malloc(sizeof(char) * TDATO);
            printf("Ingrese nombre: ");
            if(leerValidarDato(nombre,1)){
                strcpy(lista[indice].nombre,nombre);
            }else{
                free(nombre);
                nombre=NULL;
            }
        }
        if(edad){
            printf("Edad: %s\n",edad);
        }else{
            edad=malloc(sizeof(char) * TDATO);
            printf("Ingrese edad: ");
            if(leerValidarDato(edad,2)){
                lista[indice].edad=atoi(edad);
            }else{
                free(edad);
                edad=NULL;
            }
        }
        if(dni){
            printf("DNI: %s\n",dni);
        }else{
            dni=malloc(sizeof(char) * TDATO);
            printf("Ingrese dni: ");
            if(leerValidarDato(dni,2)){
                int parDni=atoi(dni);
                if(buscarPorDni(lista,parDni)==-1){
                    lista[indice].dni=parDni;
                }else{
                    printf("\nEl dni ya existe!!!");
                    free(dni);
                    dni=NULL;
                }
            }else{
                free(dni);
                dni=NULL;
            }
        }
        system("pause");
    }
        lista[indice].estado=1;
        free(nombre);
        free(edad);
        free(dni);
    }else{
        printf("No hay espacio para cargar personas");
    }
}

char *leerValidarDato(char *dato,char tipo){

    fflush(stdin);
    gets(dato);

    int tam=strlen(dato);

    if(!(tam>TDATO) && tam!=0){
        do{
            switch(tipo){

            case 1:
                if (!(*dato >= 'A' && *dato <= 'Z' || *dato >= 'a' && *dato <= 'z')){
                    dato=NULL;
                }
                break;
            case 2:
                if (!(*dato >= '0' && *dato <= '9')){
                    dato=NULL;
                }
                break;
            case 3:
                if (!(*dato >= '0' && *dato <= '9') && *dato!='.'){
                    dato=NULL;
                }
                break;
            }
            if(dato==NULL){
                break;
            }
        }while(*++dato!='\0');
    }else{
        dato=NULL;
    }

    return dato;
}

void imprimirListaOrdenada(EPersona lista[]){
    system("cls");
    for(int i=0;i<TPERSONA;i++){
        if(lista[i].estado){
            printf("Nombre: %s\n",lista[i].nombre);
            printf("Edad  : %d\n",lista[i].edad);
            printf("DNI   : %d\n",lista[i].dni);
            printf("-----------------------------------\n");
        }
    }
    for(int i=0;i<TPERSONA;i++){
        for(int j=0;j<TPERSONA;j++){
            if(lista[i].estado && lista[j].estado){
                if(strcmp(lista[j].nombre,lista[i].nombre)>0){
                    char auxNombre[TDATO];
                    strcpy(auxNombre,lista[i].nombre);
                    strcpy(lista[i].nombre,lista[j].nombre);
                    strcpy(lista[j].nombre,auxNombre);

                    int auxEdad;
                    auxEdad=lista[i].edad;
                    lista[i].edad=lista[j].edad;
                    lista[j].edad=auxEdad;

                    int auxDni;
                    auxDni=lista[i].dni;
                    lista[i].dni=lista[j].dni;
                    lista[j].dni=auxDni;
                }
            }
        }
    }
    printf("-----------------------------------\n");
    printf("----------ORDEN--------------------\n");
    printf("-----------------------------------\n");
    for(int i=0;i<TPERSONA;i++){
        if(lista[i].estado){
            printf("Nombre: %s\n",lista[i].nombre);
            printf("Edad  : %d\n",lista[i].edad);
            printf("DNI   : %d\n",lista[i].dni);
            printf("-----------------------------------\n");
        }
    }
}

void borrarPersona(EPersona lista[]){
    char *dni=NULL;
    int indice;
    while(!dni){
        system("cls");
        if(!dni){
            dni=malloc(sizeof(char) * TDATO);
            printf("Ingrese dni a borrar: ");
            if(!leerValidarDato(dni,2)){
                free(dni);
                dni=NULL;
            }
        }
    }
    if((indice=buscarPorDni(lista,atoi(dni)))!=-1){
        lista[indice].estado=0;
        printf("Se borro el dni");
    }else{
           printf("DNI no encontrado");
    }

}

void imprimirGrafico(EPersona lista[]){

    int menor=0;
    int entre=0;
    int mayor=0;

    for(int i=0;i<TPERSONA;i++){
        if(lista[i].estado!=0){
            if(lista[i].edad<=18){
                menor++;
            }else if(lista[i].edad>18 && lista[i].edad<35){
                entre++;
            }else{
                mayor++;
            }
        }
    }

    if(menor!=0 || entre!=0 || mayor!=0){
        system("cls");
        printf(" Grafico edades: \n");
        printf("-----------------\n");
        for(int i=TPERSONA;i>=0;i--){
            if((menor-i)>0){
                printf(" *  |");
            }else{
                printf("    |");
            }
            if((entre-i)>0){
                printf("   *   |");
            }else{
                printf("       |");
            }
            if((mayor-i)>0){
                printf("  *");
            }
            printf("\n");
        }
        printf("-----------------\n");
        printf("<18 | 19-35 | >35\n");
    }else{
        printf("No hay personas cargadas!!!\n");
    }
}

