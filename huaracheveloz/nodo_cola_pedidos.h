#ifndef NODO_COLA_PEDIDOS_H_INCLUDED
#define NODO_COLA_PEDIDOS_H_INCLUDED

#include "lista_carrito.h"
#include "nodo_carrito.h"
#include "cola_pedidos.h"

struct nodoColaPedidos{
    listaCarrito *carrito;
    struct nodoColaPedidos *sig, *ant;
    int total;
    char nombre_usuario[50];
    char direccion [100];
    char telefono[10];
    char repartidorAsignado[30];
};

typedef struct nodoColaPedidos nodoColaPedidos;

nodoColaPedidos *crearNodoColaPedidos(listaCarrito *carrito, char *nombre, char *direccion, char *tel);
#endif // NODO_COLA_PEDIDOS_H_INCLUDED
