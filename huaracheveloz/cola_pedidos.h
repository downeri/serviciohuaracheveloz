#ifndef COLA_PEDIDOS_H_INCLUDED
#define COLA_PEDIDOS_H_INCLUDED

#include "lista_carrito.h"
#include "nodo_carrito.h"

#include "lista_almacen.h"
#include "nodo_almacen.h"

#include "nodo_cola_pedidos.h"

typedef struct colaPedidos{
    nodoColaPedidos *inicio, *fin;
    int n;
}colaPedidos;

colaPedidos *crearColaPedidos();
int pedidosVacio(colaPedidos *pedidos);
void push_pedido(nodoColaPedidos *pedido, colaPedidos* cola);
void pop(colaPedidos *cola);
#endif // COLA_PEDIDOS_H_INCLUDED
