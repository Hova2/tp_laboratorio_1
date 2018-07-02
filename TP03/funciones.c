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
#include "movie.h"

void imprimirOpcionMenu(int opcion){

    switch(opcion){
        case 1:
            printf("1 - Agregar pelicula\n");
            break;
        case 2:
            printf("2 - Modificar pelicula\n");
            break;
        case 3:
            printf("3 - Borrar pelicula\n");
            break;
        case 4:
            printf("4 - Generar archivo html de peliculas\n");
            break;
        case 5:
            printf("5 - Salir\n");
            break;
    }

    return;
}

void imprimirError(int codigo){
     switch(codigo){
        case 1:
            printf("El nombre ingresado es incorrecto!!!!\n");
            break;
        case 2:
            printf("El nombre debe tener 8 caracteres como maximo!!!!\n");
            break;
        case 3:
            printf("El titulo ingresado es incorrecto!!!!\n");
            break;
        case 4:
            printf("El genero ingresado es incorrecto!!!!\n");
            break;
        case 5:
            printf("La duracion ingresada es incorrecta!!!!\n");
            break;
        case 6:
            printf("La descripcion ingresada es incorrecta!!!!\n");
            break;
        case 7:
            printf("El puntaje ingresado es incorrecto!!!!\n");
            break;
        case 8:
            printf("El link ingresado es incorrecto!!!!\n");
            break;
        case 9:
            printf("La duracion debe ser mayor a 0 y menor o igual a 240!!!!\n");
            break;
        case 10:
            printf("El puntaje debe ser mayor a 0 y menor o igual a 10!!!!\n");
            break;
        case 11:
            printf("No hay espacio para cargar peliculas!!!!\n");
            break;
        case 12:
            printf("El id ingresado es incorrecto!!!!\n");
            break;
        case 13:
            printf("No se encuentra el id ingresado!!!!\n");
            break;
        case 14:
            printf("La opcion ingresada es invalida!!!!\n");
            break;
        case 15:
            printf("El nombre de archivo ingresado es incorrecto!!!!\n");
            break;
        case 16:
            printf("El nombre de archivo debe tener como maximo 8 caracteres!!!!\n");
            break;
     }
     system("pause");
}

void generarPagina(EMovie lista[], char *nombre){
    FILE *archivo;
    FILE *templateparte1;
    FILE *templateparte2;
    char pathArchivo[24]="./template/";
    char *tmp=malloc(sizeof(char) * 150);
    strcat(pathArchivo,nombre);
    strcat(pathArchivo,".html");

    archivo=fopen(pathArchivo,"w");

    templateparte1=fopen("./template/templateparte1.temp","r");
    while(!feof(templateparte1)){
         fprintf(archivo,fgets(tmp,150, templateparte1));
    }
    fclose(templateparte1);

    for(int i=0;i<TARREGLO;i++){

        if(lista[i].id){
            fprintf(archivo,"<article class='col-md-4 article-intro'>\n");

            fprintf(archivo,"<a href='#'><img class='img-responsive img-rounded' src='");
            fprintf(archivo,lista[i].linkImagen);
            fprintf(archivo,"' alt=''></a>\n");

            fprintf(archivo,"<h3>\n");
            fprintf(archivo,"<a href='#'>");
            fprintf(archivo,lista[i].titulo);
            fprintf(archivo,"</a>\n");
            fprintf(archivo,"</h3>\n");

            fprintf(archivo,"<ul>\n");
            fprintf(archivo,"<li>Genero:");
            fprintf(archivo,lista[i].genero);
            fprintf(archivo,"</li>\n");

            fprintf(archivo,"<li>Puntaje:");
            fprintf(archivo,"%d",lista[i].puntaje);
            fprintf(archivo,"</li>\n");

            fprintf(archivo,"<li>Duracion:");
            fprintf(archivo,"%d",lista[i].duracion);
            fprintf(archivo,"</li>\n");
            fprintf(archivo,"</ul>\n");

            fprintf(archivo,"<p>");
            fprintf(archivo,lista[i].descripcion);
            fprintf(archivo,"</p>\n");

            fprintf(archivo,"</article>\n");
        }
    }

    templateparte2=fopen("./template/templateparte2.temp","r");
    while(!feof(templateparte2)){
         fprintf(archivo,fgets(tmp,150, templateparte2));
    }
    fclose(templateparte2);

    fclose(archivo);
}

void generarPaginaWeb(EMovie lista[]){
    char *nombre=NULL;
    nombre=cargarNombreDeArchivo(nombre);
    generarPagina(lista,nombre);
}

char *cargarNombreDeArchivo(char *nombre){
    while(nombre==NULL){
        system("cls");
        fflush(stdin);
        printf("Cargar nombre de archivo:\n");
        nombre=malloc(sizeof(char) * TDATO);
        printf("Ingrese nombre: ");
        if(leerDato(nombre,1)){
            int tam=strlen(nombre);
            if(tam<=8){
                nombre=formatearNombreArchivo(nombre,tam);
                return nombre;
            }else{
                nombre=borrarPuntero(nombre);
                imprimirError(16);
            }
        }else{
            nombre=borrarPuntero(nombre);
            imprimirError(15);
        }
    }
}

char* borrarPuntero(char *dato){
     free(dato);
     return NULL;
}

char *leerDato(char *dato,char tipo){

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

char *formatearNombrePelicula(char *dato, int tam){
    char *aux=malloc(sizeof(char) * TDATO);
    int cont=1;
    strtok(dato, "\n");
    aux=dato;
    *aux=toupper(*aux);
    while(cont<tam){
        ++aux;
        cont++;
        *aux=tolower(*aux);
    }

    return dato;
}

int agregarPeliculaMain(EMovie lista[],int ultimoId){
    char *titulo=NULL;
    char *genero=NULL;
    char *duracion=NULL;
    char *descripcion=NULL;
    char *puntaje=NULL;
    char *link=NULL;
    EMovie movieTmp;

    int indice=obtenerMovieLibre(lista);

    if(indice!=-1){
        while(!titulo || !genero || !duracion || !descripcion || !puntaje || !link){
        system("cls");
        fflush(stdin);
        printf("Cargar pelicula:\n");
        if(titulo){
            printf("Titulo: %s\n",titulo);
        }else{
            titulo=malloc(sizeof(char) * TDATO);
            printf("Ingrese el titulo de la pelicula: ");
            if(leerDato(titulo,2)){
                strcpy(movieTmp.titulo,formatearNombrePelicula(titulo,strlen(titulo)));
            }else{
                titulo=borrarPuntero(titulo);
                imprimirError(3);
            }
        }
        if(genero){
            printf("Genero: %s\n",genero);
        }else{
            genero=malloc(sizeof(char) * TDATO);
            printf("Ingrese el genero de la pelicula: ");
            if(leerDato(genero,2)){
                strcpy(movieTmp.genero,formatearNombrePelicula(genero,strlen(genero)));
            }else{
                genero=borrarPuntero(genero);
                imprimirError(4);
            }
        }
       if(duracion){
            printf("Duracion: %s\n",duracion);
        }else{
            duracion=malloc(sizeof(char) * TDATO);
            printf("Ingrese la duracion de la pelicula: ");
            if(leerDato(duracion,5)){
                strtok(duracion, "\n");
                int auxDuracion=atoi(duracion);
                if(auxDuracion>0 && auxDuracion<=240){
                    movieTmp.duracion=auxDuracion;
                }else{
                    duracion=borrarPuntero(duracion);
                    imprimirError(9);
                }
            }else{
                duracion=borrarPuntero(duracion);
                imprimirError(5);
            }
        }
        if(descripcion){
            printf("Descripcion: %s\n",descripcion);
        }else{
            descripcion=malloc(sizeof(char) * TDATO);
            printf("Ingrese la descripcion de la pelicula: ");
            if(leerDato(descripcion,2)){
                strcpy(movieTmp.descripcion,formatearNombrePelicula(descripcion,strlen(descripcion)));
            }else{
                descripcion=borrarPuntero(descripcion);
                imprimirError(6);
            }
        }
        if(puntaje){
            printf("Puntaje: %s\n",puntaje);
        }else{
            puntaje=malloc(sizeof(char) * TDATO);
            printf("Ingrese el puntaje de la pelicula: ");
            if(leerDato(puntaje,5)){
                strtok(puntaje, "\n");
                int auxPuntaje=atoi(puntaje);
                if(auxPuntaje>0 && auxPuntaje<=10){
                    movieTmp.puntaje=auxPuntaje;
                }else{
                    puntaje=borrarPuntero(puntaje);
                    imprimirError(10);
                }
            }else{
                puntaje=borrarPuntero(puntaje);
                imprimirError(7);
            }
        }
        if(link){
            printf("Link: %s\n",link);
        }else{
            link=malloc(sizeof(char) * TDATO);
            printf("Ingrese el link de la imagen de la pelicula: ");
            if(leerDato(link,1)){
                strtok(link, "\n");
                strcpy(movieTmp.linkImagen,link);
            }else{
                link=borrarPuntero(link);
                imprimirError(8);
            }
        }
        system("pause");
    }
        movieTmp.id=ultimoId;
        ultimoId++;
        lista[indice]=movieTmp;
        actualizarArchivo(lista);
        free(titulo);
        free(genero);
        free(duracion);
        free(descripcion);
        free(puntaje);
        free(link);
    }else{
        imprimirError(11);
    }

    return ultimoId;
}

int buscarPorId(EMovie lista[], int id){
    int indice=0;

    while(!(lista[indice].id && lista[indice].id==id) && ++indice<TARREGLO);

    if(indice<TARREGLO){
        return indice;
    }else{
        return -1;
    }
}

void borrarPelicula(EMovie lista[]){
    char *id=NULL;
    int indice;
    while(!id){
        system("cls");
        if(!id){
            id=malloc(sizeof(char) * TDATO);
            printf("Ingrese el id de pelicula a borrar: ");
            if(!leerDato(id,5)){
                id=borrarPuntero(id);
                imprimirError(12);
            }
        }
    }
    if((indice=buscarPorId(lista,atoi(id)))!=-1){
        lista[indice].id=0;
        printf("Se borro el id de pelicula ingresado!!!\n");
        actualizarArchivo(lista);
        system("pause");
    }else{
           imprimirError(13);
    }

}

void modificarPelicula(EMovie lista[]){
    char *titulo=NULL;
    char *genero=NULL;
    char *duracion=NULL;
    char *descripcion=NULL;
    char *puntaje=NULL;
    char *link=NULL;
    EMovie movieTmp;

    char *id=NULL;
    int indice;
    while(!id){
        system("cls");
        if(!id){
            id=malloc(sizeof(char) * TDATO);
            printf("Ingrese el id de pelicula a modificar: ");
            if(!leerDato(id,5)){
                id=borrarPuntero(id);
                imprimirError(12);
            }
        }
    }

    if((indice=buscarPorId(lista,atoi(id)))!=-1){
        while(!titulo || !genero || !duracion || !descripcion || !puntaje || !link){
        system("cls");
        fflush(stdin);
        printf("Modificar pelicula:\n");
        if(titulo){
            printf("Titulo: %s\n",titulo);
        }else{
            titulo=malloc(sizeof(char) * TDATO);
            printf("Ingrese el titulo de la pelicula: ");
            if(leerDato(titulo,2)){
                strcpy(movieTmp.titulo,formatearNombrePelicula(titulo,strlen(titulo)));
            }else{
                titulo=borrarPuntero(titulo);
                imprimirError(3);
            }
        }
        if(genero){
            printf("Genero: %s\n",genero);
        }else{
            genero=malloc(sizeof(char) * TDATO);
            printf("Ingrese el genero de la pelicula: ");
            if(leerDato(genero,2)){
                strcpy(movieTmp.genero,formatearNombrePelicula(genero,strlen(genero)));
            }else{
                genero=borrarPuntero(genero);
                imprimirError(4);
            }
        }
       if(duracion){
            printf("Duracion: %s\n",duracion);
        }else{
            duracion=malloc(sizeof(char) * TDATO);
            printf("Ingrese la duracion de la pelicula: ");
            if(leerDato(duracion,5)){
                strtok(duracion, "\n");
                int auxDuracion=atoi(duracion);
                if(auxDuracion>0 && auxDuracion<=240){
                    movieTmp.duracion=auxDuracion;
                }else{
                    duracion=borrarPuntero(duracion);
                    imprimirError(9);
                }
            }else{
                duracion=borrarPuntero(duracion);
                imprimirError(5);
            }
        }
        if(descripcion){
            printf("Descripcion: %s\n",descripcion);
        }else{
            descripcion=malloc(sizeof(char) * TDATO);
            printf("Ingrese la descripcion de la pelicula: ");
            if(leerDato(descripcion,2)){
                strcpy(movieTmp.descripcion,formatearNombrePelicula(descripcion,strlen(descripcion)));
            }else{
                descripcion=borrarPuntero(descripcion);
                imprimirError(6);
            }
        }
        if(puntaje){
            printf("Puntaje: %s\n",puntaje);
        }else{
            puntaje=malloc(sizeof(char) * TDATO);
            printf("Ingrese el puntaje de la pelicula: ");
            if(leerDato(puntaje,5)){
                strtok(puntaje, "\n");
                int auxPuntaje=atoi(puntaje);
                if(auxPuntaje>0 && auxPuntaje<=10){
                    movieTmp.puntaje=auxPuntaje;
                }else{
                    puntaje=borrarPuntero(puntaje);
                    imprimirError(10);
                }
            }else{
                puntaje=borrarPuntero(puntaje);
                imprimirError(7);
            }
        }
        if(link){
            printf("Link: %s\n",link);
        }else{
            link=malloc(sizeof(char) * TDATO);
            printf("Ingrese el link de la imagen de la pelicula: ");
            if(leerDato(link,1)){
                strtok(link, "\n");
                strcpy(movieTmp.linkImagen,link);
            }else{
                link=borrarPuntero(link);
                imprimirError(8);
            }
        }
        system("pause");
    }
        movieTmp.id=lista[indice].id;
        lista[indice]=movieTmp;
        actualizarArchivo(lista);
        free(titulo);
        free(genero);
        free(duracion);
        free(descripcion);
        free(puntaje);
        free(link);
    }else{
        imprimirError(13);
    }

}


void actualizarArchivo(EMovie lista[]){

    int cant=contarElementos(lista);
    FILE *bd=devuelveArchivo(2);

    fwrite(&cant,sizeof(int),1,bd);
    fwrite(lista,sizeof(EMovie),TARREGLO,bd);
    fclose(bd);
}

FILE *devuelveArchivo(int opcion){
    FILE *bd;

    switch(opcion){
    case 1:
        bd=fopen("./bd/bd.dat","rb");
        break;
    case 2:
        bd=fopen("./bd/bd.dat","wb");
        break;
    }

    return bd;
}

void cargarArreglo(EMovie lista[]){

    int cant;
    FILE* bd=devuelveArchivo(1);
    fread(&cant,sizeof(int),1,bd);
    fread(lista,sizeof(EMovie),TARREGLO,bd);
    fclose(bd);
}

int buscarUltimoID(EMovie lista[]){
    int ultimo=0;
    for(int i=0;i<TARREGLO;i++){
        if(lista[i].id>ultimo){
            ultimo=lista[i].id;
        }
    }

    return ultimo+1;
}






