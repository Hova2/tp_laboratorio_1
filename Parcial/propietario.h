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

/**
 * Busca dentro del arreglo de propietarios si hay algun propietario cargado.
 * @param lista el array se pasa como parametro, del tipo arreglo de EPropietario.
 * @return devuelve 0 si no hay personas cargadas o 1 si hay personas cargadas.
 */
char existenPropietarioCargado(EPropietario []);

int obtenerPropietarioLibre(EPropietario []);
int buscarPropietario(EPropietario [], int);


#endif // PROPIETARIO_H_INCLUDED
