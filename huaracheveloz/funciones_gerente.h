#ifndef FUNCIONES_GERENTE_H_INCLUDED
#define FUNCIONES_GERENTE_H_INCLUDED

#include "cola_pedidos.h"
#include "cola_repartidor.h"

void verColaPedidos(colaPedidos *pedidos);
void consultarRepartidoresDisponibles(colaRepartidores *repartidoresDisponibles);
void repartidoresTransito(colaRepartidores *repartidoresEnTransito);
void asignarPedido(colaPedidos *pedidos, colaRepartidores *repartidoresDisponibles, colaRepartidores *repartidoresTransito);

#endif // FUNCIONES_GERENTE_H_INCLUDED
