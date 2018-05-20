#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "propietario.h"
#include "auto.h"
#define TDATO 100
#define TNYA 50
#define TDIRE 75
#define TTARJETA 20
#define TPATENTE 6

typedef struct {

    int recTotal;
    int recMarca1;
    int recMarca2;
    int recMarca3;
    int recMarca4;

}ERecaudaciones;

void imprimirOpcionMenu(int);
void imprimirError(int);
void agregarPropietario(EPropietario []);
void agregarAuto(EAuto [],EPropietario []);
void modificarPropietario(EPropietario []);
void bajaPropietario(EPropietario [],EAuto [],ERecaudaciones *);
void bajaAutoManual(EAuto [],EPropietario [],ERecaudaciones *);
void recaudacionTotal(int);
void recaudacionTotalPorMarca(int,int,int,int);
void inisializarRecaudaciones(ERecaudaciones *);
void imprimirPropietario(EPropietario[],EAuto[]);
void imprimirAutosAudi(EPropietario[],EAuto[]);
void imprimirAutosDePropietario(EAuto[],int);
void imprimirAutosOrdenados(EPropietario[],EAuto[]);
char *borrarPuntero(char *);

/*
1 - String
2 - StringConEspacio
3 - AlfaNumerico
4 - AlfaNumericoConEspacio
5 - NumeroEntero
6 - NumeroConComa
*/
char *leerValidarDato(char *,char);
char *formatearNombre(char *,int);
char *formatearPatente(char *);
char validarPatente(char *);
int bajaAutoAutomatica(EAuto [],int,ERecaudaciones *);
int devolverHorasEstadia();

#endif // FUNCIONES_H_INCLUDED
