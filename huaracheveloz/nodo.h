#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct nodo {
    struct nodo *sig, *ant;
    int info;
};

typedef struct nodo nodo;

#endif // NODO_H_INCLUDED
