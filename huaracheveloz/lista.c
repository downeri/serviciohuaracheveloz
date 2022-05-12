#include <stdlib.h>
#include <stdio.h>

#include "lista.h"


lista *nuevaLista(void) {
    lista *p;
    p = malloc(sizeof(lista));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}

void imprimelista(lista *lista) {
    nodo *p;
    if (vacia(lista)) {
        printf("Lista vacia\n");
        return;
    }
    p = lista->inicio;
    while (p!=NULL) {
        printf("[%d] ",p->info);
        p = p->sig;
    }
    printf("\n");
    return;
}

void imprimeListaReversa2(lista *lista) {
    nodo *p;
    if (vacia(lista)) {
        printf("Lista vacia\n");
        return;
    }
    p = lista->fin;
    while (p!=NULL) {
        printf("[%d] ",p->info);
        p = p->ant;
    }
    printf("\n");
    return;
}

int vacia(lista *lista) {
    return lista->inicio == NULL;
}

void agregaDatoFinal(lista *lista, int dato) {
    nodo *p = crear(dato);
    nodo *rueditas;
    if (vacia(lista)) {
        lista->inicio = lista->fin = p;
        return;
    }
    p->ant = lista->fin;
    lista->fin->sig = p;
    lista->fin = p;
    lista->n += 1;
    return;
}

nodo *borrar(lista *lista, int dato) {
    nodo *p,*a, *z;
    if (vacia(lista))
        return NULL;
    if (lista->inicio == lista->fin) {
        if (lista->inicio->info == dato) {
            p = lista->inicio;
            lista->inicio = lista->fin = NULL;
            lista->n = 0;
            return p;
        }
        return NULL;
    }
    p = lista->inicio;
    while (p!=NULL && p->info != dato) {
        p = p->sig;
    }
    if (p==NULL) {
        return NULL;
    }
    if (p == lista->inicio) {
        lista->inicio = lista->inicio->sig;
        lista->inicio->ant = NULL;
        p->sig = NULL;
        return p;

    }
    if (p==lista->fin) {
        lista->fin = lista->fin->ant;
        lista->fin->sig = NULL;
        p->ant = NULL;
        return p;
    }
a = p->ant;
z = p->sig;
a->sig = z;
z->ant = a;
p->ant = NULL;
p->sig = NULL;

return p;
}
