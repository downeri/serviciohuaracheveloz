#include "funciones_repartidor.h"
#include <stdio.h>
#include <stdlib.h>
#include "cola_pedidos.h"
#include "cola_repartidor.h"

nodoColaPedidos *pedidoAsignado(colaPedidos *pedido, colaRepartidores *repartidoresTransito){
    if(pedidosVacio(pedido)){
        printf("No hay pedidos\n");
        system("pause");
        return NULL;
    }
    int unidad;
    nodoColaPedidos *p=pedido->inicio;
    nodoCarrito *c=p->carrito->inicio;
    int n;
    system("cls");
    printf("Ingresa tu unidad de reparcición:\n(Ingresa 0 para salir)\n");
    do{
        fflush(stdin);
        n=scanf("%d",&unidad);
        if(n!=1)
            printf("Ingresa un número válido\n");
    }while(n!=1);
    if(unidad==0)
        return NULL;
    n=0;
    while(p!=NULL){
        if(p->repartidorAsignado!=NULL){
            if(unidad==p->repartidorAsignado->unidadDeReparticion){
                n++;
                printf("\tPedido para %s: \n",p->nombre_usuario);
                while(c!=NULL){
                    printf("\t\t%s: ",c->nombreProducto);
                    printf("%d\n",c->cantidad);
                    c=c->sig;
                }
                printf("\n\tTotal: %.2f\n",p->carrito->total);
                printf("\t\tDirección: %s\n",p->direccion);
                printf("\t\tTeléfono: %s\n\n",p->telefono);
                system("pause");
                break;
            }
        }
        p=p->sig;
    }
    if(n==0){
        printf("No cuentas con ningun pedido para entregar\n\n");
        system("pause");
        return NULL;
    }
    return p;
}

void notificarEntrega(colaPedidos *pedido, colaRepartidores *repartidoresTransito, colaRepartidores *repartidoresDisponibles){
    int n;
    int ans;
    nodoRepartidor *repartidor;
    nodoColaPedidos *p=pedidoAsignado(pedido, repartidoresTransito);
    if(p!=NULL){
        printf("¿Marcar pedido como entregado? [1=Si] [0=No]\n");
        do{
            fflush(stdin);
            n=scanf("%d",&ans);
            if(n!=1||ans>1||ans<0)
                printf("Ingrese un numero válido\n");
        }while(n!=1||ans>1||ans<0);
        if(ans==1){
            repartidor=popRepartidor(repartidoresTransito);
            agregarRepartidorExistente(repartidoresDisponibles,repartidor);
            eliminarPedido(pedido,p);
            system("cls");
            printf("¡Pedido entregado!\n\n");
            system("pause");
        }
    }
}
