#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo_almacen.h"

struct listaAlmacen {
    nodoAlmacen *inicio, *fin;
    int n;
};
typedef struct listaAlmacen listaAlmacen;
listaAlmacen *nuevaLista(void);
void imprimeListaAlmacen(listaAlmacen *lista);
void imprimeListaAlmacenReversa(listaAlmacen *lista);
int vacia(listaAlmacen *lista);
nodoAlmacen *siguienteElementoAlmacen(nodoAlmacen *nodo);
nodoAlmacen *anteriorElementoAlmacen(nodoAlmacen *nodo);
void agregaDatoFinal(listaAlmacen *lista, char *producto, float precio, int existencias);
nodoAlmacen *borrar2(listaAlmacen *lista, int dato);
void inicializarListaAlmacen(listaAlmacen *lista);
void separarNombre(char *nombre);
void unirNombre(char *nombre);
void navegarLista(listaAlmacen *lista);
nodoAlmacen *seleccionarProductos(listaAlmacen *lista);

#endif // LISTA_H_INCLUDED
