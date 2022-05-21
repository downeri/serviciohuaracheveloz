#ifndef COLA_PEDIDOS_H_INCLUDED
#define COLA_PEDIDOS_H_INCLUDED
#include "lista_carrito.h"
#include "nodo_carrito.h"
#include "lista_almacen.h"
#include "nodo_almacen.h"
#include "nodo_cola_pedidos.h"

typedef struct colaPedidos{
    struct nodoColaPedidos *inicio, *fin;
    int n;
}colaPedidos;

colaPedidos *crearColaPedidos();
int pedidosVacio(colaPedidos *pedidos);
void push_pedido(struct nodoColaPedidos *pedido, colaPedidos* cola);
void pop(colaPedidos *cola);
void imprimeColaPedidos(colaPedidos *cola);
void escribirPedidoAlTxt(colaPedidos *cola);
void inicializarColaPedidos();

#endif // COLA_PEDIDOS_H_INCLUDED
