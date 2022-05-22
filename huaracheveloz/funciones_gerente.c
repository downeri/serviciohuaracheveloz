#include "funciones_gerente.h"
#include "cola_pedidos.h"
#include "cola_repartidor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verColaPedidos(colaPedidos *pedidos){
    system("cls");
    imprimeColaPedidos(pedidos);
    system("pause");
}

void consultarRepartidoresDisponibles(colaRepartidores *repartidoresDisponibles){
    system("cls");
    imprimeColaRepartidores(repartidoresDisponibles);
    system("pause");
}

void repartidoresTransito(colaRepartidores *repartidoresEnTransito){
    system("cls");
    imprimeColaRepartidores(repartidoresEnTransito);
    system("pause");
}

void asignarPedido(colaPedidos *pedidos, colaRepartidores *repartidoresDisponibles, colaRepartidores *repartidoresTransito){
    nodoColaPedidos *pedido=pedidos->inicio;
    nodoRepartidor *repartidor;
    while(pedido!=NULL){
        if(pedido->repartidorAsignado==NULL){
            repartidor=popRepartidor(repartidoresDisponibles);
            if(repartidor==NULL){
                printf("No hay repartidores disponibles, no se asigno ningun pedido\n");
                system("pause");
                return;
            }
            pedido->repartidorAsignado=repartidor;
            agregarRepartidorExistente(repartidoresTransito,repartidor);
            printf("Pedido de %s asignado a %s\n",pedido->nombre_usuario,repartidor->nombreRepartidor);
        }
        pedido=pedido->sig;
    }
    system("pause");

}
