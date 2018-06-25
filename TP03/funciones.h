/**
 * @brief Archivo de definiciones de funciones (TP03).
 *
 * El archivo contiene las definiciones de todas las funciones del TP03.
 * @file funciones.h
 * @author Juan Ignacio Guglielmone
 * @date 01/06/2018
 *
*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "movie.h"

#define TARREGLO 20


/** @brief Imprime opciones del menu.
 *
 * Funcion que permite imprimir las opciones del menu mediante un codigo de menu.
 * @param codigo Es el codigo de menu, del tipo entero.
 * @return No se devuelve nada.
 */
void imprimirOpcionMenu(int);

/** @brief Imprime error.
 *
 * Funcion que permite imprimir un error que surge de las diferentes validaciones,
 * mediante un codigo de error.
 * @param codigo Es el codigo del error, del tipo entero.
 * @return No se devuelve nada.
 */
void imprimirError(int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista La lista de peliculas a ser agregadas en el archivo.
 *  @param nombre El nombre para el archivo.
 */
void generarPagina(EMovie[], char[]);

/**
 *  Pide un nombre de archivo y genera la pagina web mediante la utilizacion de la funcion generarPagina.
 *  @param lista La lista de peliculas a ser agregadas en el archivo. Del tipo arreglo de EMovie.
 *  @return No se devuelve nada.
 */
void generarPaginaWeb(EMovie[]);

char *cargarNombreDeArchivo(char *);

/** @brief Borrar puntero.
 *
 * Funcion que permite borrar un puntero a char.
 * @param dato Es el puntero que se quiere borrar, del tipo puntero un arreglo de char.
 * @return Devuelve un puntero nulo, del tipo puntero a un arreglo de char.
 */
char *borrarPuntero(char *);

/** @brief Leer validar dato.
 * Lee por entrada estandar una cadena de caracteres y valida que lo ingresado sea correcto.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @param tipo define el tipo de dato que se lee(1 - String, 2 - StringConEspacio, 3 - AlfaNumerico, 4 - AlfaNumericoConEspacio, 5 - NumeroEntero, 6 - NumeroConComa), del tipo char.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *leerDato(char *,char);

/** @brief Formatear nombre del archivo.
 * Le da un formato predefinido a una cadena de caracteres.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @param tam Es el tamaño del arreglo de char, del tipo entero.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *formatearNombreArchivo(char *,int);

/** @brief Formatear nombre de una pelicula..
 * Le da un formato predefinido a una cadena de caracteres.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @param tam Es el tamaño del arreglo de char, del tipo entero.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *formatearNombrePelicula(char *,int);

/** @brief Validar patente.
 * Valida que e formato de patente ingresado sea el correcto.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @return 0-Si el formato es invalido,1-Si el formato es valido, del tipo char.
 */
char validarPatente(char *);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

#endif // FUNCIONES_H_INCLUDED
