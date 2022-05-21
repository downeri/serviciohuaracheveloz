#ifndef FUNCIONES_COMPRADOR_H_INCLUDED
#define FUNCIONES_COMPRADOR_H_INCLUDED

#include "lista_almacen.h"
#include "lista_carrito.h"
#include "cola_pedidos.h"
void seleccionarProductosCompra(listaAlmacen *lista, listaCarrito *carrito, colaPedidos *pedidos, int *hayCarrito);
void revisarCarrito(listaCarrito *carrito, colaPedidos *pedidos,int *hayCarrito);
void realizarPedido(colaPedidos *cola_pedidos, listaCarrito *carrito, int *hayCarrito);


#endif // FUNCIONES_COMPRADOR_H_INCLUDED
