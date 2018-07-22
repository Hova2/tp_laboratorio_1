#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "ArrayList.h"

void imprimirOpcionMenu(int);
void imprimirError(int);

/** @brief Leer datos por pantalla
 *
 * Lee los datos que se ingresan por la entrada estandar.
 *
 * @return puntero, del tipo puntero a char
 */
char *leerDatoPorPantalla();

/** @brief Validar datos
 *
 * Valida que los datos sean del tipo correcto.
 *
 * @param dato es un puntero a un arreglo de char, del tipo puntero char.
 * @param tipo define el tipo de dato que se lee, del tipo char.
 * 1 - String.
 * 2 - StringConEspacio.
 * 3 - AlfaNumerico.
 * 4 - AlfaNumericoConEspacio.
 * 5 - NumeroEntero.
 * 6 - NumeroConComa.
 * 7 - Cualquier caracter.
 *
 * @return 0 - Si la validacion es incorrecta, 1 - Si la validacion es correcta, del tipo char.
 */
char validarDato(char *,char);

/** @brief Formatear dato
 *
 * Formatea un dato dependiendo del tipo de dato que se quiera obtener.
 *
 * @param dato es un puntero a un arreglo de char, del tipo puntero a char.
 * @param tipo define el tipo de formato que se le quiera dar al dato, del tipo char:
 * 1 - Convierte todo el string a mayuscula.
 * 2 - Convierte todo el string a minuscula.
 * 3 - Pone la primera letra del string en mayuscula y el resto en minuscula.
 * 4 - Pone la primera letra despues de un espacio en mayuscula y el resto en minuscula.
 * 5 - Deja el string sin formato.
 * 6 - Convierte el string en un numero entero.
 * 7 - Convierte el string en un numero flotante.
 *
 * @return puntero, del tipo puntero a void.
 */
void *formatearDato(char *,char);

/** @brief Valida y formatea un dato
 *
 * Valida y formatea un dato cargado por cualquier medio utilizando las funciones validarDato y formatearDato.
 *
 * @param dato es un puntero a un arreglo de char, del tipo puntero a char.
 * @param tipoVal define el tipo de dato que se lee, del tipo char.
 * @param tipoFor define el tipo de formato que se le quiera dar al dato, del tipo char.
 *
 * @return puntero, del tipo puntero a void.
 */
void *validarYFormatearDato(char *,char,char);

int parserArchivo(ArrayList*, char*);
int guardarArchivo(ArrayList*, char*);

void cargarDepositos(ArrayList*,ArrayList*);
void imprimirListaProductoDeposito(ArrayList*);
void listarProductosDeposito(ArrayList*,ArrayList*);
int buscarProducto(ArrayList*,int);
void moverProductoDeposito(ArrayList*,ArrayList*);
void moverProducto(ArrayList*,ArrayList*);


#endif // FUNCIONES_H_INCLUDED
