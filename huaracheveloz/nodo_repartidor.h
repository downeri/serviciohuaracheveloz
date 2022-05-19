#ifndef NODO_REPARTIDOR_H_INCLUDED
#define NODO_REPARTIDOR_H_INCLUDED

struct nodoRepartidor{
    char nombreRepartidor[30];
    int unidadDeReparticion;
    struct nombreRepartidor *sig;
};
typedef struct nodoRepartidor nodoRepartidor;

nodoRepartidor *crearNodoRepartidor(char nombreRepartidor[30], int unidadDeReparticon);

#endif // NODO_REPARTIDOR_H_INCLUDED
