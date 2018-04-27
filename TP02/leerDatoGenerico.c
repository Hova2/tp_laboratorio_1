#include <stdio.h>
#include <stdlib.h>

void *leerDato(void);


void main(){

    int *num;
    num=(int *)leerDato();


    printf("El numero ingresado es: %d",*num);

    return;
}

void *leerDato(void){
    int *dato;

    scanf("%d",dato);
    return dato;
}
