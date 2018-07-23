#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#include "eReparto.h"


int main(){
    ArrayList *lista=al_newArrayList();
    char seguir='s';
    int opcion=0;

    while(seguir=='s'){
        if(lista->isEmpty(lista)){
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(5);

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    cargarReparto(lista);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(1);
                    break;
            }
        }else{
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
                    imprimirError(2);
                    break;
                case 2:
                    imprimirListaReparto(lista);
                    break;
                case 3:
                    mostrarLocalidades(lista);
                    break;
                case 4:
                    generarArchivoRepartoLocalidad(lista);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(1);
                    break;
            }
        }
    }




    return 0;
}
