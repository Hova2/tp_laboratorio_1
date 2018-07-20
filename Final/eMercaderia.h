#ifndef EMERCADERIA_H_INCLUDED
#define EMERCADERIA_H_INCLUDED
#define TDATO 51

typedef struct{
    int producto;
    char descripcion[TDATO];
    int cantidad;
}eMercaderia;

eMercaderia* eMercaderia_nuevo(void);

int eMercaderia_setProducto(eMercaderia*, int);
int eMercaderia_getProducto(eMercaderia*);

char *eMercaderia_setDescripcion(eMercaderia*, char*);
char *eMercaderia_getDescripcion(eMercaderia*);

int eMercaderia_setCantidad(eMercaderia*, int);
int eMercaderia_getCantidad(eMercaderia*);

#endif // EMERCADERIA_H_INCLUDED
