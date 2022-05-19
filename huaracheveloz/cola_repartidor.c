#include "cola_repartidor.h"
#include "funciones_generales.h"
#include <stdio.h>
#include <stdlib.h>

colaRepartidores *crearColaRepartidores(){
    colaRepartidores *p=malloc(sizeof(colaRepartidores));
    p->fin=p->inicio=NULL;
    p->n=0;
    return p;
}
void imprimeColaRepartidores(colaRepartidores *lista) {
    nodoRepartidor *p;
    if (lista->inicio==NULL) {
        printf("Lista vacia\n");
        return;
    }
    p = lista->inicio;
    int i=1;
    while (p!=NULL) {
        printf("[%d] %s\tUnidad: %d\n",i,p->nombreRepartidor,p->unidadDeReparticion);
        p=p->sig;
        i++;
    }
    return;
}

void inicializarRepartidores(colaRepartidores *colaRepartidor){
    char nombre[30];
    int unidadReparticion;
    FILE *productos=fopen("./repartidores.txt","r");
    char string[50];
    while(fgets(string,50,productos)!=NULL){
        sscanf(string,"%s %d",nombre,&unidadReparticion);
        separarNombre(nombre);
        agregarRepartidor(colaRepartidor,nombre,unidadReparticion);
    }
    fclose(productos);
}


void agregarRepartidor(colaRepartidores *cola,char *nombre, int unidadReparticion){
    nodoRepartidor *p=crearNodoRepartidor(nombre, unidadReparticion);
    if(cola->inicio==NULL){
        cola->inicio=cola->fin=p;
        cola->n++;
        return;
    }
    cola->fin->sig=p;
    cola->fin=p;
    cola->n++;
}
