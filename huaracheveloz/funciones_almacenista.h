#ifndef FUNCIONES_ALMACENISTA_H_INCLUDED
#define FUNCIONES_ALMACENISTA_H_INCLUDED

#include "lista_almacen.h"

void mostrarProductos(listaAlmacen *lista);
void registrarProductos(listaAlmacen *lista);
void imprimirProducto(nodoAlmacen *nodo);
void reescribirTxt(listaAlmacen *lista, char nombre[30], int nuevaCantidad);
void agregarAlTxt(char nombre[30],float precio, int existencias);
void quitarSalto(char *nombre);

#endif // FUNCIONES_ALMACENISTA_H_INCLUDED
