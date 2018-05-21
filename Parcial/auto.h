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

/** @brief Inicializar auto.
 * Inicializa en cero la patente del auto del arreglo de autos.
 * @param lista Es el arreglo de autos, del tipo EAuto.
 * @return No se devuelve nada.
 */
void inisializarAuto(EAuto []);

/** @brief Ordenar auto.
 * Ordena alfabeticamente por patente el arreglo de autos.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @return No se devuelve nada.
 */
void ordenarAuto(EAuto []);

/** @brief Existe auto cargado.
 * Busca dentro del arreglo de autos si hay algun auto cargado.
 * @param lista Es el arreglo de autos, del tipo EAuto.
 * @return devuelve 0 si no hay autos cargados en el arreglo o 1 si hay autos cargados en el arreglo.
 */
char existenAutoCargado(EAuto []);

/** @brief Existe propietario con auto.
 * Busca dentro del arreglo de autos si un propietario tiene auto cargado dentro del mismo.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @return devuelve 0 si el propietario no tiene autos cargados en el arreglo o 1 si el propietario tiene autos cargados en el arreglo.
 */
char exitePropietarioConAuto(EAuto [],int);

/** @brief Existe auto AUDI.
 * Busca dentro del arreglo de autos si hay algun auto cargado que sea de la marca AUDI.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @return devuelve 0 si no hay autos de la marca AUDI cargados en el arreglo o 1 si hay autos de la marca AUDI cargados en el arreglo.
 */
char exiteAutoAudi(EAuto []);

/** @brief Obtener auto libre.
 * Busca dentro del arreglo de autos el primer espacio libre dentro del mismo.
 * @param lista Es el arreglo de autos, del tipo EAuto.
 * @return devuelve el primer indice libre o -1 si no hay mas espacio en el arreglo.
 */
int obtenerAutoLibre(EAuto []);

/** @brief Buscar auto.
 * Busca dentro del arreglo de autos, un auto mediante su patente.
 * @param lista Es el arreglo de autos, del tipo EAuto.
 * @param patente Es la patente del auto, del arreglo de char.
 * @return devuelve el indice donde encontro la patente buscada o -1 si no encontro la patente.
 */
int buscarAuto(EAuto [], char *);

#endif // AUTO_H_INCLUDED
