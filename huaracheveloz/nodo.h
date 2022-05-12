#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct nodo {
    struct nodo *sig, *ant;
    int info;
};

typedef struct nodo nodo;
nodo *crear(int x);
#endif // NODO_H_INCLUDED
