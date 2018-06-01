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
            printf("2 - Modificar propietario\n");
            break;
        case 3:
            printf("3 - Baja propietario\n");
            break;
        case 4:
            printf("4 - Agregar auto\n");
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
            printf("La direccion ingresada es incorrecta!!!!\n");
            break;
        case 4:
            printf("La tarjeta ingresada es incorrecta!!!!\n");
            break;
        case 5:
            printf("El ID ya existe!!!!\n");
            break;
        case 6:
            printf("No hay mas espacio para cargar peliculas!!!!\n");
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
                imprimirError(2);
            }
        }else{
            nombre=borrarPuntero(nombre);
            imprimirError(1);
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
int devolverHorasEstadia(){
    int horas;
    srand(time(NULL));
    horas = (rand()%24)+1;

    return horas ;

}
int contarElementos(EMovie lista[]){
    int cont=0;
    for(int i=0;i<TARREGLO;i++){
        if(lista[i].id){
            cont++;
        }
    }
    if(cont){
        return cont;
    }
    return cont;
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
                strcpy(movieTmp.descripcion,formatearNombrePelicula(titulo,strlen(titulo)));
            }else{
                titulo=borrarPuntero(titulo);
                imprimirError(2);
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
                imprimirError(2);
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
                    imprimirError(8);
                }
            }else{
                duracion=borrarPuntero(duracion);
                imprimirError(2);
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
                imprimirError(2);
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
                    imprimirError(8);
                }
            }else{
                puntaje=borrarPuntero(puntaje);
                imprimirError(2);
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
                imprimirError(2);
            }
        }
        system("pause");
    }
        movieTmp.id=ultimoId;
        ultimoId++;
        lista[indice]=movieTmp;
        agregarPelicula(movieTmp);
        free(titulo);
        free(genero);
        free(duracion);
        free(descripcion);
        free(puntaje);
        free(link);
    }else{
        imprimirError(6);
    }



    return ultimoId;
}

agregarPelicula(EMovie pelicula){
    FILE *bd;
    if(bd=fopen("./bd/bd.dat","rb")!=NULL){
        fclose(bd);
        bd=fopen("./bd/bd.dat","wb");
        fwrite(&pelicula,sizeof(EMovie),1,bd);
    }else{
        bd=fopen("./bd/bd.dat","wb");
        fwrite(&pelicula,sizeof(EMovie),1,bd);
    }
    fclose(bd);
}






