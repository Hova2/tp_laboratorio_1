#ifndef EEMPLEADO_H_INCLUDED
#define EEMPLEADO_H_INCLUDED

#define TDATO 50

typedef struct{
    int id;
    char nombre[TDATO];
    char direccion[TDATO];
    int horas;
    int sueldo;

}eEmpleado;

eEmpleado* eEmpleado_nuevo(void);

int eEmpleado_compararEmpleado(void* ,void* );
int eEmpleado_calcularSueldo(void*);

void eEmpleado_Imprimir(eEmpleado*);

int eEmpleado_setId(eEmpleado*, int);
int eEmpleado_getId(eEmpleado*);

int eEmpleado_setHoras(eEmpleado*, int);
int eEmpleado_getHoras(eEmpleado*);

int eEmpleado_setSueldo(eEmpleado*, int);
int eEmpleado_getSueldo(eEmpleado*);

char *eEmpleado_setNombre(eEmpleado*, char*);
char *eEmpleado_getNombre(eEmpleado*);

char *eEmpleado_setDireccion(eEmpleado*, char*);
char *eEmpleado_getDireccion(eEmpleado*);

#endif // EEMPLEADO_H_INCLUDED
