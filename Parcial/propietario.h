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

/** @brief Inicializar propietario.
 * Inicializa en cero el id del propietario del arreglo de propietarios.
 * @param lista Es el arreglo de propietarios, del tipo EPropietario.
 * @return No se devuelve nada.
 */
void inisializarPropietario(EPropietario []);

/** @brief Existen propietarios cargados.
 * Busca dentro del arreglo de propietarios si hay algun propietario cargado.
 * @param lista Es el arreglo de propietarios, del tipo EPropietario.
 * @return devuelve 0 si no hay personas cargadas o 1 si hay personas cargadas.
 */
char existenPropietarioCargado(EPropietario []);

/** @brief Obtener propietario libre.
 * Busca dentro del arreglo de propietarios el primer espacio libre dentro del mismo.
 * @param lista Es el arreglo de propietarios, del tipo EPropietario.
 * @return devuelve el primer indice libre o -1 si no hay mas espacio en el arreglo.
 */
int obtenerPropietarioLibre(EPropietario []);

/** @brief Buscar propietario.
 * Busca dentro del arreglo de propietarios a un propietario mediante su id.
 * @param lista Es el arreglo de propietarios, del tipo EPropietario.
 * @param idPropietario Es el id del propietario, del tipo entero.
 * @return devuelve el indice donde encontro al propietario buscado o -1 si no encontro al propietario.
 */
int buscarPropietario(EPropietario [], int);
#endif // PROPIETARIO_H_INCLUDED
