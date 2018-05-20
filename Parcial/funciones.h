#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "propietario.h"
#include "auto.h"
#define TDATO 100
#define TNYA 50
#define TDIRE 75
#define TTARJETA 20
#define TPATENTE 6

void imprimirOpcionMenu(int);
void imprimirError(int);
void agregarPropietario(EPropietario []);
void agregarAuto(EAuto [],EPropietario []);
void modificarPropietario(EPropietario []);
void bajaPropietario(EPropietario [],EAuto []);
void bajaAutoManual(EAuto [],EPropietario []);
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
int devolverHorasEstadia();
int bajaAutoAutomatica(EAuto [],int);

#endif // FUNCIONES_H_INCLUDED
