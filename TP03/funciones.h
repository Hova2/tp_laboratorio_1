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

/** @brief Generar pagina.
 *
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista La lista de peliculas a ser agregadas en el archivo.
 *  @param nombre El nombre para el archivo.
 */
void generarPagina(EMovie[], char[]);

/** @brief Generar pagina web.
 *
 *  Genera la pagina web mediante la utilizacion de la funcion generarPagina.
 *  @param lista La lista de peliculas a ser agregadas en el archivo. Del tipo arreglo de EMovie.
 *  @return No se devuelve nada.
 */
void generarPaginaWeb(EMovie[]);

/** @brief Cargar nombre de archivo.
 *
 *  Solicita por pantalla que se ingrese un nombre de archivo para la pagina web.
 *  @param nombre Es el nombre del archivo. Del tipo puntero a char.
 *  @return El nombre del archivo. Del tipo puntero a char.
 */

char *cargarNombreDeArchivo(char *);

/** @brief Borrar puntero.
 *
 * Funcion que permite borrar un puntero a char.
 * @param dato Es el puntero que se quiere borrar, del tipo puntero un arreglo de char.
 * @return Devuelve un puntero nulo, del tipo puntero a un arreglo de char.
 */
char *borrarPuntero(char *);

/** @brief Leer validar dato.
 *
 * Lee por entrada estandar una cadena de caracteres y valida que lo ingresado sea correcto.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @param tipo define el tipo de dato que se lee(1 - String, 2 - StringConEspacio, 3 - AlfaNumerico, 4 - AlfaNumericoConEspacio, 5 - NumeroEntero, 6 - NumeroConComa), del tipo char.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *leerDato(char *,char);

/** @brief Formatear nombre del archivo.
 *
 * Le da un formato predefinido a una cadena de caracteres.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @param tam Es el tamaño del arreglo de char, del tipo entero.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *formatearNombreArchivo(char *,int);

/** @brief Formatear nombre de una pelicula.
 *
 * Le da un formato predefinido a una cadena de caracteres.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @param tam Es el tamaño del arreglo de char, del tipo entero.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *formatearNombrePelicula(char *,int);

/** @brief Actualizar archivo de peliculas.
 *
 *  Escribe nuevamente el archivo binario con los cambios que se realizaron.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @return No devuelve nada.
 */
void actualizarArchivo(EMovie[]);

/** @brief Borrar pelicula.
 *
 *  Borra una pelicula del archivo binario.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @return No devuelve nada.
 */
void borrarPelicula(EMovie[]);

/** @brief Modificar pelicula.
 *
 *  Modifica una pelicula del archivo binario.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @return No devuelve nada.
 */
void modificarPelicula(EMovie []);

/** @brief Buscar id.
 *
 *  Busca dentro del arreglo de peliculas un id espesifico.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @param id Es el id de la pelicula que se esta buscando. Del tipo entero.
 *  @return Devuelve el indice donde se encuentra la pelicula. Del tipo entero.
 */
int buscarPorId(EMovie[], int);

/** @brief Devuelve archivo.
 *
 *  Devuelve un puntero a archivo y dependiendo del parametro de la funcion lo devuelve en modo lectura o escritura.
 *  @param opcion Es el modo en que se va a abrir el archivo. 1-Se abre en modo lectura, 2-Se abre en modo escritura. Del tipo entero.
 *  @return Devuelve el puntero al archivo. Del tipo puntero a archivo.
 */
FILE *devuelveArchivo(int);

/** @brief Cargar arreglo.
 *
 *  Carga en memoria el archivo de peliculas.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @return No devuelve nada.
 */
void cargarArreglo(EMovie[]);


/** @brief Buscar ultimo id.
 *
 *  Busca dentro del arreglo de peliculas cual es el ultimo id que se cargo y le suma uno.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @return Devuelve el ultimo id que se puede utilizar para cargar una pelicula nueva. De tipo entero.
 */
int buscarUltimoID(EMovie[]);

#endif // FUNCIONES_H_INCLUDED
