#ifndef NODO_COLA_PEDIDOS_H_INCLUDED
#define NODO_COLA_PEDIDOS_H_INCLUDED

#include "lista_carrito.h"
#include "nodo_carrito.h"
#include "cola_pedidos.h"
#include "nodo_cola_pedidos.h"

typedef struct nodoColaPedidos{
    listaCarrito *carrito;
    struct nodoColaPedidos *sig, *ant;
    char nombre_usuario[50];
    char direccion [100];
    char telefono[10];
} nodoColaPedidos ;

nodoColaPedidos *crearNodoColaPedidos(listaCarrito *carrito, char *nombre, char *direccion, char *tel);
#endif // NODO_COLA_PEDIDOS_H_INCLUDED
