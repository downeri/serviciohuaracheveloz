#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct lista {
    nodo *inicio, *fin;
    int n;
};

typedef struct lista lista;

lista *nuevalista(void);
void imprimelista(lista *lista);
void imprimeListaReversa(lista *lista);
int vacia(lista *lista);

void agregaDatoFinal(lista *lista, int dato);
nodo *borrar2(lista *lista, int dato);

#endif // LISTA_H_INCLUDED
