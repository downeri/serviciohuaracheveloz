#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct nodo {
    struct nodo *sig, *ant;
    char nombreProducto[30];
    float precioUnitario;
    int existencias;
};

typedef struct nodo nodo;
nodo *crear(char *nombre, float precio, int existencias);
#endif // NODO_H_INCLUDED
