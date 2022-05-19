#include "funciones_gerente.h"
#include <stdio.h>
#include <stdlib.h>
void colaPedidos(){
    printf("Cola de pedidos");
}

void consultarRepartidoresDisponibles(colaRepartidores *repartidoresDisponibles){
    system("cls");
    int a;
    imprimeColaRepartidores(repartidoresDisponibles);
    printf("Ingrese cualquier caracter para continuar");
    scanf("%d",&a);
    fflush(stdin);
}

void repartidoresTransito(){
    printf("Repartidores en transito");
}

void asignarPedido(){
    printf("Asignar pedido");
}
