#ifndef FUNCIONES_REPARTIDOR_H_INCLUDED
#define FUNCIONES_REPARTIDOR_H_INCLUDED
#include "nodo_cola_pedidos.h"
nodoColaPedidos *pedidoAsignado(colaPedidos *pedido, colaRepartidores *repartidoresTransito);
void notificarEntrega(colaPedidos *pedido, colaRepartidores *repartidoresTransito, colaRepartidores *repartidoresDisponibles);
nodoColaPedidos *encontrarPedido(int unidad, nodoColaPedidos *p);
#endif // FUNCIONES_REPARTIDOR_H_INCLUDED
