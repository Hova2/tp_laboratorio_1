#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#define TDATO 100

typedef struct{
    unsigned int id;
    char titulo[TDATO];
    char genero[TDATO];
    unsigned int duracion;
    char descripcion[TDATO];
    unsigned int puntaje;
    char linkImagen[TDATO];
}EMovie;

void inisializarListaMovie(EMovie []);

void setEmovieId(EMovie,unsigned int);
void setEmovieTitulo(EMovie,char *);
void setEmovieGenero(EMovie,char *);
void setEmovieDuracion(EMovie,unsigned int);
void setEmovieDescripcion(EMovie,char *);
void setEmoviePuntaje(EMovie,unsigned int);
void setEmovieLinkImagen(EMovie,char *);

unsigned int getEmovieId(EMovie);
char *getEmovieTitulo(EMovie);
char *getEmovieGenero(EMovie);
unsigned int getEmovieDuracion(EMovie);
char *getEmovieDescripcion(EMovie);
unsigned int getEmoviePuntaje(EMovie);
char *getEmovieLinkImagen(EMovie);



#endif // MOVIE_H_INCLUDED
