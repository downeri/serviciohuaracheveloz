#include "cola_repartidor.h"
#include "funciones_generales.h"
#include "nodo_cola_pedidos.h"
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
}

void inicializarRepartidoresDisponibles(colaRepartidores *colaRepartidor){
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

void inicializarRepartidoresEnTransito(colaRepartidores *colaRepartidor){
    char nombre[30];
    int unidadReparticion;
    FILE *productos=fopen("./repartidoresEnTransito.txt","r");
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

void agregarRepartidorExistente(colaRepartidores *cola,nodoRepartidor *repartidor){
    if(cola->inicio==NULL){
        cola->inicio=cola->fin=repartidor;
        cola->n++;
        return;
    }
    cola->fin->sig=repartidor;
    cola->fin=repartidor;
    cola->n++;
}

nodoRepartidor *popRepartidor(colaRepartidores *cola){
    if(cola->n==0)
        return NULL;
    nodoRepartidor *primerRepartidor=cola->inicio;
    nodoRepartidor *aux=cola->inicio->sig;
    cola->inicio=aux;
    primerRepartidor->sig=NULL;
    cola->n--;
    return primerRepartidor;
}
