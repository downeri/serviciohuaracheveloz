#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_carrito.h"
#include "nodo_carrito.h"
#include "cola_pedidos.h"

nodoColaPedidos *crearNodoColaPedidos(listaCarrito *carrito, char *nombre, char *direccion, char *tel)
{
    nodoColaPedidos *p = malloc(sizeof(nodoColaPedidos));
    p->carrito = carrito;
    p->sig = p->ant = NULL;
    strcpy(p->nombre_usuario, nombre);
    strcpy(p->direccion, direccion);
    strcpy(p->telefono, tel);
    return p;
}
