#include "nodo_repartidor.h"
#include <stdlib.h>
#include <string.h>

nodoRepartidor *crearNodoRepartidor(char nombreRepartidor[30], int unidadDeReparticion){
    nodoRepartidor *repartidor;
    repartidor=malloc(sizeof(nodoRepartidor));
    strcpy(repartidor->nombreRepartidor,nombreRepartidor);
    repartidor->unidadDeReparticion=unidadDeReparticion;
    repartidor->sig=NULL;
    return repartidor;
}


