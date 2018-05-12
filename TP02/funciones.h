/**
 * @brief Archivo de definiciones de funciones (TP02).
 *
 * El archivo contiene las definiciones de todas las funciones del TP02.
 * @file funciones.h
 * @author Juan Ignacio Guglielmone
 * @date 04/05/2018
 *
*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TPERSONA 20
#define TDATO 50
#define EDADMIN 0
#define EDADMAX 125

typedef struct {

    char nombre[TDATO];
    int edad;
    int estado;
    int dni;

}EPersona;

/** @brief Imprime error.
 *
 * Funcion que permite imprimir un error que surge de las diferentes validaciones,
 * mediante un codigo de error.
 * @param codigo Es el codigo del error, del tipo entero.
 * @return No se devuelve nada.
 */
void imprimirError(int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro, del tipo arreglo de EPersona.
 * @return el primer indice disponible, del tipo entero.
 */
int obtenerEspacioLibre(EPersona []);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro, del tipo arreglo de EPersona.
 * @param dni el dni a ser buscado en el array, del tipo entero.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni, del tipo entero.
 */
int buscarPorDni(EPersona [], int);


/**
 * Busca dentro del arreglo de personas si hay alguna persona cargada.
 * @param lista el array se pasa como parametro, del tipo arreglo de EPersona.
 * @return devuelve 0 si no hay personas cargadas o 1 si hay personas cargadas.
 */
char existenPersonasCargadas(EPersona []);
/**
 * Lee por entrada estandar una cadena de caracteres y valida que lo ingresado sea correcto.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @param tipo define el tipo de dato que se lee(1 - cadena de caracteres, 2 - entero, 3 - punto flotante), del tipo char.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *leerValidarDato(char *,char);

/**
 * Le da un formato predefinido a una cadena de caracteres.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *formatearNombre(char *);

/**
 * Inicializa en cero el estado del arreglo de personas.
 * @param lista es un puntero a un arreglo de personas, del tipo arreglo de EPersona..
 * @return No se devuelve nada.
 */
void inisializarListaPersona(EPersona[]);

/**
 * Carga una persona dentro del arreglo de personas.
 * @param lista es un puntero a un arreglo de personas, del tipo arreglo de EPersona..
 * @return No se devuelve nada.
 */
void agregarPersona(EPersona[]);

/**
 * Borra una persona que existe dentro del arreglo de personas.
 * @param lista es un puntero a un arreglo de personas, del tipo arreglo de EPersona..
 * @return No se devuelve nada.
 */
void borrarPersona(EPersona []);

/**
 * Imprime por pantalla el listado del arreglo de personas ordenado de la A a la Z.
 * @param lista es un puntero a un arreglo de personas, del tipo arreglo de EPersona..
 * @return No se devuelve nada.
 */
void imprimirListaOrdenada(EPersona []);

/**
 * Imprime por pantalla un grafico del arreglo de personas ordenado por edad.
 * @param lista es un puntero a un arreglo de personas, del tipo arreglo de EPersona..
 * @return No se devuelve nada.
 */
void imprimirGrafico(EPersona []);

#endif // FUNCIONES_H_INCLUDED
