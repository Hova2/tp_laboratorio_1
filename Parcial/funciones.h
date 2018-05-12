#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "propietario.h"
#include "auto.h"
#define TDATO 50

void agregarPropietario(EPropietario []);
void agregarAuto(EAuto [],EPropietario []);
char *leerValidarDato(char *,char);
char *formatearNombre(char *);
void imprimirError(int);
void modificarPropietario(EPropietario []);
void bajaPropietario(EPropietario []);
int devolverHorasEstadia();

#endif // FUNCIONES_H_INCLUDED
