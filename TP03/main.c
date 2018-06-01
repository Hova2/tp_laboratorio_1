#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    EMovie listaMovie[TARREGLO];
    inisializarListaMovie(listaMovie);
    int ultimoId=0;
    /*listaMovie[0].id=1;
    strcpy(listaMovie[0].titulo,"Pelicula1");
    strcpy(listaMovie[0].genero,"Terror");
    listaMovie[0].duracion=230;
    strcpy(listaMovie[0].descripcion,"Buena");
    listaMovie[0].puntaje=5;
    strcpy(listaMovie[0].linkImagen,"http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg");
    listaMovie[1].id=2;
    strcpy(listaMovie[1].titulo,"Pelicula2");
    strcpy(listaMovie[1].genero,"Suspenso");
    listaMovie[1].duracion=130;
    strcpy(listaMovie[1].descripcion,"Muy buena");
    listaMovie[1].puntaje=10;
    strcpy(listaMovie[1].linkImagen,"Link2");*/
    char seguir='s';
    int opcion=0;

    while(seguir=='s'){
        if(contarElementos(listaMovie)){
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(2);
            imprimirOpcionMenu(3);
            imprimirOpcionMenu(4);
            imprimirOpcionMenu(5);

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    ultimoId=agregarPeliculaMain(listaMovie,ultimoId);
                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:
                    generarPaginaWeb(listaMovie);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(14);
                    break;
            }
        }else{
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(5);

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    agregarPeliculaMain(listaMovie);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(14);
                    break;
            }
        }
    }

    return 0;
}
