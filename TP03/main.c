#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    EMovie listaMovie[TARREGLO];
    inisializarListaMovie(listaMovie);
    cargarArreglo(listaMovie);

    int ultimoId=buscarUltimoID(listaMovie);
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
                    modificarPelicula(listaMovie);
                    break;
                case 3:
                    borrarPelicula(listaMovie);
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
                    ultimoId=agregarPeliculaMain(listaMovie,ultimoId);
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
