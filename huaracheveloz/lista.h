#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct lista {
    nodo *inicio, *fin;
    int n;
};

typedef struct lista lista;

lista *nuevaLista(void);
void imprimeLista(lista *lista);
void imprimeListaReversa(lista *lista);
int vacia(lista *lista);
nodo *siguienteElemento(lista *lista);
void agregaDatoFinal(lista *lista, char *producto, float precio, int existencias);
nodo *borrar2(lista *lista, int dato);

#endif // LISTA_H_INCLUDED
