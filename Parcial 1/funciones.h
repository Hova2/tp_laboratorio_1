/**
 * @brief Archivo de definiciones de funciones (Parcial).
 *
 * El archivo contiene las definiciones de todas las funciones del parcial.
 * @file funciones.h
 * @author Juan Ignacio Guglielmone
 * @date 08/05/2018
 *
*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "propietario.h"
#include "auto.h"
#define TDATO 100
#define TNYA 50
#define TDIRE 75
#define TTARJETA 20
#define TPATENTE 6

typedef struct {

    int recMarca1;
    int recMarca2;
    int recMarca3;
    int recMarca4;

}ERecaudaciones;

/** @brief Inicializar recaudaciones.
 *
 * Funcion que permite inicializar la estructura de recaudaciones poniendo los datos en cero.
 * @param recaudaciones Es la estructura de recaudaciones, del tipo puntero a ERecaudaciones.
 * @return No se devuelve nada.
 */
void inisializarRecaudaciones(ERecaudaciones *);

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

/** @brief Imprime autos de un propietario.
 *
 * Funcion que permite imprimir los autos que tiene estacionados un propietario,
 * o devuelve un mensaje si no tiene autos estacionados.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @param idPropietario Es el numero de id de un propietario, del tipo entero.
 * @return No se devuelve nada.
 */
void imprimirAutosDePropietario(EAuto[],int);

/** @brief Agrega propietario.
 *
 * Funcion que permite dar de alta un nuevo propietario.
 * @param lista Es el arreglo de propietarios, del tipo EPropietario.
 * @return No se devuelve nada.
 */

void agregarPropietario(EPropietario []);

/** @brief Agrega auto.
 *
 * Funcion que permite dar de alta un nuevo auto.
 * @param lista Es el arreglo de autos, del tipo EAuto.
 * @param listaPropietario Es el arreglo de propietarios, del tipo EPropietario.
 * @return No se devuelve nada.
 */
void agregarAuto(EAuto [],EPropietario []);

/** @brief Modifica propietario.
 *
 * Funcion que permite modificar la tarjeta de credito de un propietario.
 * @param lista Es el arreglo de propietarios, del tipo EPropietario.
 * @return No se devuelve nada.
 */
void modificarPropietario(EPropietario []);

/** @brief Baja propietario.
 *
 * Funcion que permite dar de baja a un propietario. Tambien imprime el total
 * que el propietario debe abona si tiene autos estacionados. Si no tiene
 * autos estacionados, imprime un mensaje que avisa que no debe abonar
 * ningun monto.
 * @param lista Es el arreglo de propietarios, del tipo EPropietario.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @param recaudaciones Es la estructura de recaudaciones, del tipo puntero a ERecaudaciones.
 * @return No se devuelve nada.
 */
void bajaPropietario(EPropietario [],EAuto [],ERecaudaciones *);

/** @brief Baja auto manual.
 *
 * Funcion que permite dar de baja a un auto. Tambien imprime el total
 * que el propietario debe abona.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @param listaPropietario Es el arreglo de propietarios, del tipo EPropietario.
 * @param recaudaciones Es la estructura de recaudaciones, del tipo puntero a ERecaudaciones.
 * @return No se devuelve nada.
 */
void bajaAutoManual(EAuto [],EPropietario [],ERecaudaciones *);

/** @brief Recaudacion total.
 *
 * Funcion que permite imprimir la recaudacion total del estacionamiento. Si no hay
 * recaudacion, imprime un mensaje de aviso.
 * @param total Es el total recaudado por el estacionamiento, del tipo entero.
 * @return No se devuelve nada.
 */
void recaudacionTotal(int);

/** @brief Recaudacion por marca.
 *
 * Funcion que permite imprimir la recaudacion total del estacionamiento especificado
 * por marca. Si no hay recaudacion, imprime un mensaje de aviso.
 * @param marca1 Es el total recaudado por los autos de la marca ALPHA_ROMEO, del tipo entero.
 * @param marca2 Es el total recaudado por los autos de la marca FERRARI, del tipo entero.
 * @param marca3 Es el total recaudado por los autos de la marca AUDI, del tipo entero.
 * @param marca1 Es el total recaudado por los autos de otras marcas, del tipo entero.
 * @return No se devuelve nada.
 */
void recaudacionTotalPorMarca(int,int,int,int);

/** @brief Imprimir propietario.
 *
 * Funcion que permite imprimir todos los autos que tiene estacionados un propietario. Si no hay
 * autos estacionados, imprime un mensaje de aviso.
 * @param listaPropietario Es el arreglo de propietarios, del tipo EPropietario.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @return No se devuelve nada.
 */
void imprimirPropietario(EPropietario[],EAuto[]);

/** @brief Imprimir propietarios de audi.
 *
 * Funcion que permite imprimir todos datos de los propietarios que tiene estacionados un auto de la marca AUDI.
 * Si no hay autos estacionados, imprime un mensaje de aviso.
 * @param listaPropietario Es el arreglo de propietarios, del tipo EPropietario.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @return No se devuelve nada.
 */
void imprimirAutosAudi(EPropietario[],EAuto[]);

/** @brief Imprimir propietarios ordenados.
 *
 * Funcion que permite imprimir todos datos de los propietarios que tiene autos estacionados.
 * Las patentes de los autos de cada propietario estan ordenadas alfabeticamente.
 * @param listaPropietario Es el arreglo de propietarios, del tipo EPropietario.
 * @param listaAuto Es el arreglo de autos, del tipo EAuto.
 * @return No se devuelve nada.
 */
void imprimirAutosOrdenados(EPropietario[],EAuto[]);

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
char *leerValidarDato(char *,char);

/** @brief Formatear nombre.
 * Le da un formato predefinido a una cadena de caracteres.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *formatearNombre(char *,int);

/** @brief Formatear patente.
 * Le da un formato predefinido a una cadena de caracteres.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @return puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 */
char *formatearPatente(char *);

/** @brief Validar patente.
 * Valida que e formato de patente ingresado sea el correcto.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @return 0-Si el formato es invalido,1-Si el formato es valido, del tipo char.
 */
char validarPatente(char *);

/** @brief Baja auto automatica.
 *
 * Funcion que permite dar de baja a un auto. Tambien imprime el total
 * que el propietario debe abona.
 * @param lista Es el arreglo de autos, del tipo EAuto.
 * @param idPropietario Es el id de un propietario, del tipo entero.
 * @param recaudaciones Es la estructura de recaudaciones, del tipo puntero a ERecaudaciones.
 * @return devuelve el total que el propietario debe aboran, del tipo entero.
 */
int bajaAutoAutomatica(EAuto [],int,ERecaudaciones *);

/** @brief Devolver horas estadia.
 *
 * Funcion que permite devolver las horas que estubo estacionado un auto.
 * @return devuelve el total de horas (Entre 1 y 24), del tipo entero.
 */
int devolverHorasEstadia();

#endif // FUNCIONES_H_INCLUDED
