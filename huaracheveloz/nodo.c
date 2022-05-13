#include <stdlib.h>
#include "nodo.h"
#include <string.h>
nodo *crear(char *nombreProducto,float precioUnitario,int existencias) {
    nodo *p;
    p = malloc(sizeof(nodo));
    p->ant=NULL;
    p->sig=NULL;
    strcpy(p->nombreProducto,nombreProducto);
    p->precioUnitario=precioUnitario;
    p->existencias=existencias;
    return p;
}
