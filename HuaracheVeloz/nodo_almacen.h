#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct nodoAlmacen {
    struct nodoAlmacen *sig, *ant;
    char nombreProducto[30];
    float precioUnitario;
    int existencias;
};

typedef struct nodoAlmacen nodoAlmacen;
nodoAlmacen *crear(char *nombre, float precio, int existencias);
#endif // NODO_H_INCLUDED
