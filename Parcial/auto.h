/**
 * @brief Archivo de definiciones de funciones de auto (Parcial).
 *
 * El archivo contiene las definiciones de todas las funciones de auto del parcial.
 * @file auto.h
 * @author Juan Ignacio Guglielmone
 * @date 08/05/2018
 *
*/

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "funciones.h"
#define CAUTO 20
#define TDATO 100
#define MARCA1 "ALPHA_ROMERO"
#define MARCA2 "FERRARI"
#define MARCA3 "AUDI"
#define MARCA4 "OTRO"

typedef struct {

    char patente[TDATO];
    int marca;
    int idPropietario;

}EAuto;

void inisializarAuto(EAuto []);
void ordenarAuto(EAuto []);

/**
 * Busca dentro del arreglo de autos si hay algun auto cargado.
 * @param lista el array se pasa como parametro, del tipo arreglo de EAuto.
 * @return devuelve 0 si no hay personas cargadas o 1 si hay personas cargadas.
 */

char existenAutoCargado(EAuto []);
char exitePropietarioConAuto(EAuto [],int);
char exiteAutoAudi(EAuto []);
int obtenerAutoLibre(EAuto []);
int buscarAuto(EAuto [], char *);

#endif // AUTO_H_INCLUDED
