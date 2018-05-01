#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define NULL 0
#define TPERSONA 20
#define TDATO 50

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
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona []);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona [], int);

char *leerValidarDato(char *,char);
char *formatearNombre(char *);
void inisializarListaPersona(EPersona[]);
void agregarPersona(EPersona[]);
void borrarPersona(EPersona []);
void imprimirListaOrdenada(EPersona []);
void imprimirGrafico(EPersona []);

#endif // FUNCIONES_H_INCLUDED
