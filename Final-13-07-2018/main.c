#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
#include "eMercaderia.h"


int main(){
    ArrayList *lista1=al_newArrayList();
    ArrayList *lista2=al_newArrayList();
    char seguir='s';
    int opcion=0;

    while(seguir=='s'){
        if(lista1->isEmpty(lista1) && lista2->isEmpty(lista2)){
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(6);

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    lista1->clear(lista1);
                    lista2->clear(lista2);
                    cargarDepositos(lista1,lista2);
                    break;
                case 6:
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
            imprimirOpcionMenu(6);

            scanf("%d",&opcion);

            switch(opcion){
                case 1:
                    imprimirError(2);
                    break;
                case 2:
                    listarProductosDeposito(lista1,lista2);
                    break;
                case 3:
                    moverProductoDeposito(lista1,lista2);
                    break;
                case 4:
                    descontarProductosDeposito(lista1,lista2);
                    break;
                case 5:
                    agregarProductosDeposito(lista1,lista2);
                    break;
                case 6:
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
