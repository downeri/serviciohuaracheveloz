#ifndef FUNCIONES_COMPRADOR_H_INCLUDED
#define FUNCIONES_COMPRADOR_H_INCLUDED

#include "lista_almacen.h"
#include "nodo_almacen.h"
#include "nodo_carrito.h"
#include "lista_carrito.h"

#include "cola_pedidos.h"

int verificarExistencia(nodoAlmacen *producto, int cantidad);
void agregarAlCarrito(listaCarrito *carrito, nodoAlmacen *producto, int cantidad);
void imprimirProductoCarrito(nodoCarrito *nodo);
void regresarExistencias(nodoCarrito *productoActual, int cantidad);

void seleccionarProductosCompra(listaAlmacen *lista, listaCarrito *carrito, colaPedidos *pedidos);
void revisarCarrito(listaCarrito *carrito, colaPedidos *pedidos);
int realizarPedido(colaPedidos *cola_pedidos, listaCarrito *carrito);

#endif // FUNCIONES_COMPRADOR_H_INCLUDED
