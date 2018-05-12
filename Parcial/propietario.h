#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

#include "funciones.h"
#define CPROPIETARIO 20
#define TDATO 50


typedef struct {

    int idPropietario;
    char nya[TDATO];
    char direccion[TDATO];
    int tarjeta;

}EPropietario;


void inisializarPropietario(EPropietario []);
int obtenerPropietarioLibre(EPropietario []);
int buscarPropietario(EPropietario [], int);


#endif // PROPIETARIO_H_INCLUDED
