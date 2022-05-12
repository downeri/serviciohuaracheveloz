#include <stdlib.h>
#include "nodo.h"

nodo *crear(int x) {
    nodo *p;
    p = malloc(sizeof(nodo));
    p->ant = NULL;
    p->sig = NULL;
    p->info = x;
    return p;
}
