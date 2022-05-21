#ifndef LISTA_CARRITO_H_INCLUDED
#define LISTA_CARRITO_H_INCLUDED

#include "nodo_carrito.h"
#include "nodo_almacen.h"

typedef struct listaCarrito {
    nodoCarrito *inicio, *fin;
    int n;
    float total;
} listaCarrito;

listaCarrito *nuevaListaCarrito(void);
int carritoVacio(listaCarrito *carrito);

nodoCarrito *siguienteElementoCarrito(nodoCarrito *nodo);
nodoCarrito *anteriorElementoCarrito(nodoCarrito *nodo);
nodoCarrito *inspeccionarCarrito(listaCarrito *carrito, nodoAlmacen *producto);
void liberarCarrito (listaCarrito *carrito);

#endif // LISTA_CARRITO_H_INCLUDED
