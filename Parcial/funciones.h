#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "propietario.h"
#include "auto.h"
#define TDATO 50

void imprimirMenu(int);
void imprimirOpcionMenu(int);
void imprimirError(int);
void agregarPropietario(EPropietario []);
void agregarAuto(EAuto [],EPropietario []);
void modificarPropietario(EPropietario []);
void bajaPropietario(EPropietario []);
char *leerValidarDato(char *,char);
char *formatearNombre(char *);
int devolverHorasEstadia();

#endif // FUNCIONES_H_INCLUDED
