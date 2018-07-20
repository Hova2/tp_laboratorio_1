#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#define TDATO 10000

typedef struct{
    unsigned int id;
    char titulo[TDATO];
    char genero[TDATO];
    unsigned int duracion;
    char descripcion[TDATO];
    unsigned int puntaje;
    char linkImagen[TDATO];
}EMovie;


/** @brief Inicializar lista de peliculas.
 *
 *  Inicializa la lista de peliculas poniendo todos los id en cero.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @return No devuelve nada.
 */
void inisializarListaMovie(EMovie []);

/** @brief Obtener pelicula libre.
 *
 *  Busca dentro de la lista de peliculas cual es el primer id en cero.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @return Devuelve el indicie del primer elemento con id en cero. Del tipo entero.
 */
int obtenerMovieLibre(EMovie []);

/** @brief Contar cantidad de peliculas.
 *
 *  Cuenta cuantas peliculas hay cargadas dentro del listado de peliculas.
 *  @param lista Es el listado de peliculas. Del tipo arreglo de EMovie.
 *  @return Devuelve el numero de peliculas cargadas en el listado de peliculas. Del tipo entero.
 */
int contarElementos(EMovie []);

#endif // MOVIE_H_INCLUDED
