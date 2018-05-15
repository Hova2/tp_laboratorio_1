#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "funciones.h"
#define CAUTO 20
#define MARCA1 "ALPHA_ROMERO"
#define MARCA2 "FERRARI"
#define MARCA3 "AUDI"
#define MARCA4 "OTRO"
#define TDATO 50

typedef struct {

    char patente[TDATO];
    char marca[TDATO];
    int idPropietario;

}EAuto;

void inisializarAuto(EAuto []);

/**
 * Busca dentro del arreglo de autos si hay algun auto cargado.
 * @param lista el array se pasa como parametro, del tipo arreglo de EAuto.
 * @return devuelve 0 si no hay personas cargadas o 1 si hay personas cargadas.
 */
char existenAutoCargado(EAuto []);

int obtenerAutoLibre(EAuto []);
int buscarAuto(EAuto [], char *);

#endif // AUTO_H_INCLUDED
