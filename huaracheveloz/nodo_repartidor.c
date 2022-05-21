#include "nodo_repartidor.h"
#include <stdlib.h>
#include <string.h>

nodoRepartidor *crearNodoRepartidor(char nombreRepartidor[30], int unidadDeReparticon){
    nodoRepartidor *p=malloc(sizeof(nodoRepartidor));
    strcpy(p->nombreRepartidor,nombreRepartidor);
    p->unidadDeReparticion=unidadDeReparticon;
    p->sig=NULL;
    return p;
}
