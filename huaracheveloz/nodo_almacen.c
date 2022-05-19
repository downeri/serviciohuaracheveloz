#include <stdlib.h>
#include "nodo_almacen.h"
#include <string.h>

nodoAlmacen *crear(char *nombreProducto,float precioUnitario,int existencias) {
    nodoAlmacen *p;
    p = malloc(sizeof(nodoAlmacen));
    p->ant=NULL;
    p->sig=NULL;
    strcpy(p->nombreProducto,nombreProducto);
    p->precioUnitario=precioUnitario;
    p->existencias=existencias;
    return p;
}
