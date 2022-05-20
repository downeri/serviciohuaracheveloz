#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista_carrito.h"
#include "nodo_carrito.h"

listaCarrito *nuevaListaCarrito(void) {
    listaCarrito *p;
    p = malloc(sizeof(listaCarrito));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}

int carritoVacio(listaCarrito *carrito) {
    return carrito->inicio==NULL;
}

nodoCarrito *siguienteElementoCarrito(nodoCarrito *nodo) {
    return nodo->sig;
}

nodoCarrito *anteriorElementoCarrito(nodoCarrito *nodo) {
    return nodo->ant;
}

nodoCarrito *inspeccionarCarrito(listaCarrito *carrito, nodoAlmacen *producto)
{
    nodoCarrito *pointer = carrito->inicio;
    while(pointer != NULL)
    {
        if (pointer->productoAsociado == producto)
            return pointer;
        pointer = pointer->sig;
    }
    return NULL;
}

void liberarCarrito (listaCarrito *carrito)
{
    nodoCarrito *p = carrito->inicio;
    nodoCarrito *aux;
    while(p != NULL)
    {
        aux = p;
        free(p);
        p = aux->sig;
    }
    aux = NULL;
    free(carrito);
    return;
}
