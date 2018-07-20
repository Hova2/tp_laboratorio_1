#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//void cargarArreglo(ArrayList*);
//void crearArchivoSueldo(ArrayList*);

char *leerDato();
/** @brief Validar datos
 *
 * Valida que los datos sean del tipo correcto.
 * @param dato es un puntero a un arreglo de char, del tipo puntero a un arreglo de char.
 * @param tipo define el tipo de dato que se lee(1 - String, 2 - StringConEspacio, 3 - AlfaNumerico, 4 - AlfaNumericoConEspacio, 5 - NumeroEntero, 6 - NumeroConComa, 7 - Cualquier caracter), del tipo char.
 * @return 0 - Si la validacion es incorrecta, 1 - Si la validacion es correcta, del tipo char.
 */
char validarDato(char *,char);
void *formatearDato(char *,char);


#endif // FUNCIONES_H_INCLUDED
