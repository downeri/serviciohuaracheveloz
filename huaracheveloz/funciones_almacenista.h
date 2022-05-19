#ifndef FUNCIONES_ALMACENISTA_H_INCLUDED
#define FUNCIONES_ALMACENISTA_H_INCLUDED

#include "lista_almacen.h"

void mostrarProductos(listaAlmacen *lista);
void registrarProductos(listaAlmacen *lista);
void imprimirProducto(nodoAlmacen *nodo);
void reescribirTxtAlmacen(listaAlmacen *lista, char nombre[30], int nuevaCantidad);
void agregarAlTxtAlmacen(char nombre[30],float precio, int existencias);

#endif // FUNCIONES_ALMACENISTA_H_INCLUDED
