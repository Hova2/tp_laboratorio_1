/**
 * @brief Archivo de definiciones de funciones de propietario (Parcial).
 *
 * El archivo contiene las definiciones de todas las funciones de propietario del parcial.
 * @file propietario.h
 * @author Juan Ignacio Guglielmone
 * @date 08/05/2018
 *
*/

#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

#include "funciones.h"
#define CPROPIETARIO 20
#define TDATO 100

typedef struct {

    int idPropietario;
    char nya[TDATO];
    char direccion[TDATO];
    char tarjeta[TDATO];

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
