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
void agregarRepartidorExistente(colaRepartidores *cola,nodoRepartidor *repartidor);
int colaRepartidoresVacia(colaRepartidores *cola);
colaRepartidores *crearColaRepartidores();
void inicializarRepartidoresDisponibles(colaRepartidores *colaRepartidor);
void inicializarRepartidoresEnTransito(colaRepartidores *colaRepartidor);
void imprimeColaRepartidores(colaRepartidores *lista);
nodoRepartidor *popRepartidor(colaRepartidores *cola);

#endif // COLA_REPARTIDOR_H_INCLUDED
