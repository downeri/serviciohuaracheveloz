#include <stdlib.h>
#include <string.h>

#include "nodo_carrito.h"

nodoCarrito *crearNodoCarrito(char *nombreArticulo,float precioUnitario,int cantidad) {
    nodoCarrito *p;
    p = malloc(sizeof(nodoCarrito));
    p->ant=NULL;
    p->sig=NULL;
    p->nombreProducto = nombreArticulo;
    p->precioUnitario=precioUnitario;
    p->cantidad=cantidad;
    return p;
}
