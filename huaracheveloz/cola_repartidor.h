#ifndef COLA_REPARTIDOR_H_INCLUDED
#define COLA_REPARTIDOR_H_INCLUDED
#include "nodo_repartidor.h"

struct colaRepartidores{
    nodoRepartidor *inicio;
    nodoRepartidor *fin;
    int n;
};
typedef struct colaRepartidores colaRepartidores;
void agregarRepartidor(colaRepartidores *cola,char *nombre, int unidadReparticion);
int colaRepartidoresVacia(colaRepartidores *cola);
colaRepartidores *crearColaRepartidores();
void inicializarRepartidores(colaRepartidores *colaRepartidor);
void imprimeColaRepartidores(colaRepartidores *lista);

#endif // COLA_REPARTIDOR_H_INCLUDED
