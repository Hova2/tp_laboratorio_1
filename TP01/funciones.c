/**
 * @brief Archivo de implementacion de funciones (TP01).
 *
 * El archivo contiene las implementaciones de todas las funciones del TP01.
 * @file funciones.c
 * @author Juan Ignacio Guglielmone
 * @date 14/04/2018
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <float.h>
#include "funciones.h"

float leerNumero(void){

    float num;

    fflush(stdin);
    printf("Ingrese un numero: ");
    scanf("%f",&num);

    return num;
}

char esEntero(float num){
    if((num-(int)num)==0){
        return 1;
    }
    return 0;
}

char rangoValido(float num){
    if(num>=-FLT_MAX && num<=FLT_MAX){
        return 1;
    }
    return 0;
}

void imprimirResultado(int codigo,float result){
    if(rangoValido(result)){
        if(codigo!=7){
            if(esEntero(result)){
                switch(codigo){
                    case 3:
                        printf("El resultado de la suma es: %.0f\n",result);
                        break;
                    case 4:
                        printf("El resultado de la resta es: %.0f\n",result);
                        break;
                    case 5:
                        printf("El resultado de la division es: %.0f\n",result);
                        break;
                    case 6:
                        printf("El resultado de la multiplicacion es: %.0f\n",result);
                        break;
                }
            }else{
                switch(codigo){
                    case 3:
                        printf("El resultado de la suma es: %.2f\n",result);
                        break;
                    case 4:
                        printf("El resultado de la resta es: %.2f\n",result);
                        break;
                    case 5:
                        printf("El resultado de la division es: %.2f\n",result);
                        break;
                    case 6:
                        printf("El resultado de la multiplicacion es: %.2f\n",result);
                        break;
                }
            }
        }else{
            printf("El resultado del factorial es: %.0f\n",result);
        }
     }else{
        imprimirError(8);
     }
}

void imprimirError(int codigo){
     switch(codigo){
        case 1:
            printf("Se deben ingresar los 2 operandos!!!!\n");
            break;
        case 2:
            printf("Se deben ingresar el operando A!!!!\n");
            break;
        case 3:
            printf("Error de division por 0!!!!\n");
            break;
        case 4:
            printf("El numero a factorear debe ser entero!!!!\n");
            break;
        case 5:
            printf("Para las operaciones de suma, resta, division y multiplicacion, ingresar los 2 operandos!!!!\n");
            break;
        case 6:
            printf("El numero a factorear debe ser cero o positivo!!!!\n");
            break;
        case 7:
            printf("El operando esta fuera de rango!!!!\n");
            break;
        case 8:
            printf("El resultado esta fuera de rango!!!!\n");
            break;
     }
}

void existenOperandos(char operando1,char operando2,int opcion, float num1, float num2){
    if(operando1 && operando2){
        switch(opcion){
            case 3:
                    imprimirResultado(3,funcionSuma(num1,num2));
                    break;
            case 4:
                    imprimirResultado(4,funcionResta(num1,num2));
                    break;
            case 5:
                    existeDivision(num1,num2);
                    break;
            case 6:
                    imprimirResultado(6,funcionMultiplicacion(num1,num2));
                    break;
            case 7:
                    existeFactorial(operando1,num1);
                    getche();
                    break;
            case 8:
                    imprimirResultado(3,funcionSuma(num1,num2));
                    imprimirResultado(4,funcionResta(num1,num2));
                    existeDivision(num1,num2);
                    imprimirResultado(6,funcionMultiplicacion(num1,num2));
                    existeFactorial(operando1,num1);
                    break;
        }
    }else{
        if(opcion==7){
            existeFactorial(operando1,num1);
        }else if(opcion==8){
            imprimirError(5);
            existeFactorial(operando1,num1);
        }else{
            imprimirError(1);
        }
    }
}

void existeDivision(float num1, float num2){
    if(num2!=0){
        imprimirResultado(5,funcionDivision(num1,num2));
    }else{
        imprimirError(3);
    }
}

void existeFactorial(char operando1,float num1){
    if(operando1){
        if(esEntero(num1)){
            if(num1>=0){
                imprimirResultado(7,funcionFactorial(num1));
            }else{
                imprimirError(6);
            }
        }else{
            imprimirError(4);
        }
    }else{
        imprimirError(2);
    }
}

float funcionSuma(float num1, float num2){
    return num1+num2;
}

float funcionResta(float num1, float num2){
    return num1-num2;
}

float funcionMultiplicacion(float num1, float num2){
    if(num1<0 && num2==0){
        return 0;
    }else{
        return num1*num2;
    }
}

float funcionDivision(float num1, float num2){
    return num1/num2;
}

float funcionFactorial(float num){
    if(num==0){
		return 1;
	}else{
		return num*funcionFactorial(num-1);
	}
}
