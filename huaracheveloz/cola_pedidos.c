#include <stdio.h>
#include <stdlib.h>

#include "cola_pedidos.h"
#include "lista_carrito.h"
#include "nodo_carrito.h"

colaPedidos *crearColaPedidos()
{
    colaPedidos *p = malloc(sizeof(colaPedidos));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
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
