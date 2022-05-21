#ifndef NODO_CARRITO_H_INCLUDED
#define NODO_CARRITO_H_INCLUDED

#include "nodo_almacen.h"

typedef struct nodoCarrito{
    struct nodoCarrito *sig, *ant;
    char *nombreProducto;
    float precioUnitario;
    int cantidad;
    nodoAlmacen *productoAsociado;
} nodoCarrito;

nodoCarrito *crearNodoCarrito(char *nombreArticulo, float precioUnitario, int cantidad);

#endif // NODO_CARRITO_H_INCLUDED
