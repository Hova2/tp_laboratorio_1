#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "propietario.h"
#include "auto.h"
#define TDATO 50

void imprimirOpcionMenu(int);
void imprimirError(int);
void agregarPropietario(EPropietario []);
void agregarAuto(EAuto [],EPropietario []);
void modificarPropietario(EPropietario []);
void bajaPropietario(EPropietario []);

/*
1 - String
2 - StringConEspacio
3 - AlfaNumerico
4 - AlfaNumericoConEspacio
5 - NumeroEntero
6 - NumeroConComa
*/
char *leerValidarDato(char *,char);
char *formatearNombre(char *);
char *formatearPatente(char *);
int devolverHorasEstadia();

#endif // FUNCIONES_H_INCLUDED
