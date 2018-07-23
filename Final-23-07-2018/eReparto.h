#ifndef EMERCADERIA_H_INCLUDED
#define EMERCADERIA_H_INCLUDED
#define TDATO 51

typedef struct{
    int id;
    char producto[TDATO];
    char direccion[TDATO];
    char localidad[TDATO];
    char recibe[TDATO];
}eReparto;

eReparto* eReparto_nuevo(void);

int eReparto_setId(eReparto*, int);
int eReparto_getId(eReparto*);

char *eReparto_setProducto(eReparto*, char*);
char *eReparto_getProducto(eReparto*);

char *eReparto_setDireccion(eReparto*, char*);
char *eReparto_getDireccion(eReparto*);

char *eReparto_setLocalidad(eReparto*, char*);
char *eReparto_getLocalidad(eReparto*);

char *eReparto_setRecibe(eReparto*, char*);
char *eReparto_getRecibe(eReparto*);

int comparar(void*,char*);

#endif // EMERCADERIA_H_INCLUDED
