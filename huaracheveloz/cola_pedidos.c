#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola_pedidos.h"
#include "lista_carrito.h"
#include "nodo_carrito.h"
#include "funciones_generales.h"

colaPedidos *crearColaPedidos()
{
    colaPedidos *p = malloc(sizeof(colaPedidos));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}

void imprimeColaPedidos(colaPedidos *cola){
    int o=1;
    nodoColaPedidos *p;
    nodoCarrito *c;
    if (cola->inicio==NULL) {
        printf("cola vacia\n");
        return;
    }
    p = cola->inicio;
    while (p!=NULL) {
        c=cola->inicio->carrito->inicio;
        printf("[%d] %s\n",o,p->nombre_usuario);
        printf("\tPedido: \n");
        while(c!=NULL){
            printf("\t\t%s: ",c->nombreProducto);
            printf("%d\n",c->cantidad);
            c=c->sig;
        }
        printf("\n\tTotal: %.2f\n",p->carrito->total);
        printf("\t\tRepartidor asignado: %s\n",p->repartidorAsignado);
        o++;
        p=p->sig;
    }
}


int pedidosVacio(colaPedidos *pedidos)
{
    return pedidos->inicio == NULL;
}

void push_pedido(nodoColaPedidos *pedido, colaPedidos* cola)
{
    if (pedidosVacio(cola) == 1)
    {
        cola->inicio = cola->fin = pedido;
        (cola->n)++;
        return;
    }
    pedido->ant = cola->fin;
    cola->fin->sig = pedido;
    cola->fin = pedido;
    cola->n++;
    return;
}

void escribirPedidoAlTxt(colaPedidos *cola){
    char temp[30];
    FILE *archivo=fopen("colaDePedidos.txt","w");
    nodoColaPedidos *p;
    nodoCarrito *c;
    p = cola->inicio;
    while (p!=NULL) {
        fprintf(archivo,"%d",p->carrito->n);
        c=cola->inicio->carrito->inicio;
        strcpy(temp,p->nombre_usuario);
        unirNombre(temp);
        fprintf(archivo,"%s ",temp);
        while(c!=NULL){
            strcpy(temp,c->nombreProducto);
            unirNombre(temp);
            fprintf(archivo,"%s ",c->nombreProducto);
            fprintf(archivo,"%d ",c->cantidad);
            c=c->sig;
        }
        strcpy(temp,p->repartidorAsignado);
        unirNombre(temp);
        fprintf(archivo,"%.2f ",p->carrito->total);
        fprintf(archivo,"%s\n",p->repartidorAsignado);
        p=p->sig;
    }
}

void pop(colaPedidos *cola)
{
    if(pedidosVacio(cola) == 1)
    {
        printf("No hay pedidos en espera\n");
        return;
    }
    if(cola->inicio == cola->fin)
    {
        free(cola->inicio);
        cola->inicio = cola->fin = NULL;
        return;
    }
    cola->inicio = cola->inicio->sig;
    free(cola->inicio->ant);
    cola->inicio->ant = NULL;
}
