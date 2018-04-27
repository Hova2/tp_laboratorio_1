/**
 * @file funciones.h
 * @author Juan Ignacio Guglielmone
 * @date 14/04/2018
 * @brief Archivo de funciones del TP01
 *
 * El archivo contiene la definiciond e todas las funciones del TP01.
 *
*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** @brief Leer numero.
 *
 * Funcion que permite leer un numero desde la entrada estandar y devolverlo.
 * @return Devuelve un numero, del tipo float.
 *
 */
float leerNumero(void);

/** @brief Sumar.
 *
 * Funcion que permite sumar dos operandos y devolver el resultado.
 * @param num1 Primer operando de la funcion.
 * @param num2 Segundo operando de la funcion.
 * @return Devuelve un numero, del tipo float.
 *
 */
float funcionSuma(float,float);

/** @brief Resta.
 *
 * Funcion que permite restar dos operandos y devolver el resultado.
 * @param num1 Primer operando de la funcion.
 * @param num2 Segundo operando de la funcion.
 * @return Devuelve un numero, del tipo float.
 *
 */
float funcionResta(float,float);

/** @brief Multiplicacion.
 *
 * Funcion que permite multiplicar dos operandos y devolver el resultado.
 * @param num1 Primer operando de la funcion, del tipo float.
 * @param num2 Segundo operando de la funcion, del tipo float.
 * @return Devuelve un numero, del tipo float.
 *
 */
float funcionMultiplicacion(float,float);

/** @brief Division.
 *
 * Funcion que permite dividir dos operandos y devolver el resultado.
 * @param num1 Primer operando de la funcion, del tipo float.
 * @param num2 Segundo operando de la funcion, del tipo float.
 * @return Devuelve un numero, del tipo float.
 *
 */
float funcionDivision(float,float);

/** @brief Factorial.
 *
 * Funcion que permite calcular el factorial de un numero y devolver el resultado.
 * @param num Operando de la funcion, del tipo float.
 * @return Devuelve un numero, del tipo float.
 *
 */
float funcionFactorial(float);

/** @brief Determinar entero.
 *
 * Funcion que permite determinar si un numero del tipo float es entero
 * o no.
 * @param num Numero a determinar si es entero o no, del tipo float.
 * @return Devuelve un 0 si no es entero, o un 1 si es entero, del tipo char.
 *
 */
char esEntero(float);

/** @brief Determinar si el rango es correcto.
 *
 * Funcion que permite determinar si un numero esta dentro del rango
 * minimo y maximo del tipo de dato asignado.
 * @param num Numero a determinar si esta dentro del rango, del tipo float.
 * @return Devuelve un 0 si no es un rango valido, o un 1 si esta dentro del rango valido
 * , del tipo char.
 *
 */
char rangoValido(float);

/** @brief Imprime resultado.
 *
 * Funcion que permite imprimir el resultado de las operaciones (suma, resta,
 * multiplicacion, division y factorial), formateandolo dependiendo si el
 * resultado de la operacion es un numero entero o no.
 * @param codigo Es el codigo de la operacion (3-Suma,4-Resta,5-Multiplicacion,
 * 6-Division,7-Factorial), del tipo entero.
 * @param result Es el resultado de la operacion realizada, del tipo float.
 * @return No se devuelve nada.
 */
void imprimirResultado(int,float);

/** @brief Imprime error.
 *
 * Funcion que permite imprimir un error que surge de las diferentes validaciones,
 * mediante un codigo de error.
 * @param codigo Es el codigo del error, del tipo entero.
 * @return No se devuelve nada.
 */
void imprimirError(int);

/** @brief Validacion operandos.
 *
 * Funcion que permite validar que todas las operaciones tengan la cantidad necesaria
 * de operandos para que las mismas se puedan efectuar. Luego de la validacion, se
 * procede a efectuar la operacion.
 * @param operando1 Bandera que permite determinar si el operando 1 esta cargado. Si es un 0
 * el operando no esta cargado, si es un 1 el operando esta cargado. Del tipo char.
 * @param operando2 Bandera que permite determinar si el operando 2 esta cargado. Si es un 0
 * el operando no esta cargado, si es un 1 el operando esta cargado. Del tipo char.
 * @param opcion Es el codigo de la operacion (3-Suma,4-Resta,5-Multiplicacion,
 * 6-Division,7-Factorial), del tipo entero.
 * @param num1 Primer operando de la funcion, del tipo float.
 * @param num2 Segundo operando de la funcion, del tipo float.
 * @return No se devuelve nada.
 */
void existenOperandos(char,char,int,float,float);

/** @brief Validacion division.
 *
 * Funcion que permite validar que la division se pueda efectuar y que no exista un error de division por 0.
 * Luego de la validacion, se procede a efectuar la operacion.
 * @param num1 Primer operando de la funcion, del tipo float.
 * @param num2 Segundo operando de la funcion, del tipo float.
 * @return No se devuelve nada.
 */
void existeDivision(float,float);

/** @brief Validacion factorial.
 *
 * Funcion que permite validar que el factorial se pueda efectuar, determinando que exista
 * el operando A y que sea un numero entero.Luego de la validacion, se procede a efectuar la operacion.
 * @param operando1 Bandera que permite determinar si el operando 1 esta cargado. Si es un 0
 * el operando no esta cargado, si es un 1 el operando esta cargado. Del tipo char.
 * @param num1 Operando de la funcion, del tipo float.
 * @return No se devuelve nada.
 */
void existeFactorial(char,float);

#endif // FUNCIONES_H_INCLUDED
