#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "lista_almacen.h"
#include "nodo_almacen.h"
#include "funciones_almacenista.h"
#include "funciones_comprador.h"
#include "funciones_gerente.h"
#include "funciones_repartidor.h"
#include <locale.h>

void principal(listaAlmacen *almacen, listaCarrito *carrito, colaPedidos *pedidos,colaRepartidores *repartidoresDisponibles,colaRepartidores *repartidoresEnTransito);

int main (){
    setlocale(LC_ALL, "spanish");
    listaAlmacen *almacen = nuevalistaAlmacen();
    inicializarListaAlmacen(almacen);
    colaPedidos *cola_pedidos = crearColaPedidos();
    colaRepartidores *repartidoresDisponibles=crearColaRepartidores();
    inicializarRepartidoresDisponibles(repartidoresDisponibles);
    listaCarrito *carrito=NULL;
    colaRepartidores *repartidoresEnTransito=crearColaRepartidores();
    inicializarRepartidoresEnTransito(repartidoresEnTransito);
    principal(almacen, carrito, cola_pedidos, repartidoresDisponibles, repartidoresEnTransito);
    return 0;
}

void principal(listaAlmacen *almacen, listaCarrito *carrito, colaPedidos *pedidos,colaRepartidores *repartidoresDisponibles,colaRepartidores *repartidoresEnTransito){
    int hayCarrito=0;
    int a;
    int u;
    while(1){
        system("cls");
        int seleccion=menu_de_menus();
        switch(seleccion){
            case 0:
                return;
            break;
            case 1: //Almacenista
                do{
                    system("cls");
                    seleccion=menu_almacenista();
                    switch(seleccion){
                        case 1:
                            mostrarProductos(almacen);
                        break;
                        case 2:
                            registrarProductos(almacen);
                        break;
                    }
                }while(seleccion!=0);
            break;
            case 2: //Ventas
                do{
                    seleccion=menu_comprador();
                    switch(seleccion){
                        case 1:
                            carrito=nuevaListaCarrito();
                            seleccionarProductosCompra(almacen, carrito, pedidos,&hayCarrito);
                        break;
                        case 2:
                            revisarCarrito(carrito, pedidos,&hayCarrito);
                        break;
                        case 3:
                             realizarPedido(pedidos, carrito,&hayCarrito);
                             reescribirTxt(almacen);
                             escribirPedidoAlTxt(pedidos);
                             seleccion=0;
                        break;
                        case 0:
                            if(hayCarrito==1){
                                printf("Tienes un carrito de compras, ¿Seguro que quieres salir? [1=Si][0=No]\n");
                                do{
                                    fflush(stdin);
                                    u=scanf("%d",&a);
                                    if(u!=1||a>1||a<0)
                                        printf("Valor Incorrecto\n");
                                }while(u!=1||a>1||a<0);
                                if(a==1){
                                    liberarCarrito(carrito);
                                }else if(a==0){
                                    seleccion=4;
                                }
                            }
                        break;
                    }
                    system("cls");
                }while(seleccion != 0);
            break;
            case 3: //Gerente
                do{
                    system("cls");
                    seleccion=menu_gerente();
                    switch(seleccion){
                        case 1:
                            verColaPedidos(pedidos);
                        break;
                        case 2:
                            consultarRepartidoresDisponibles(repartidoresDisponibles);
                        break;
                        case 3:
                            repartidoresTransito(repartidoresEnTransito);
                        break;
                        case 4:
                            asignarPedido(pedidos,repartidoresDisponibles,repartidoresEnTransito);
                            escribirPedidoAlTxt(pedidos);
                        break;
                    }
                }while(seleccion!=0);
            break;
            case 4: //Repartidor
                seleccion=menu_repartidor();
                switch(seleccion){
                    case 1:
                        pedidoAsignado();
                    break;
                    case 2:
                        notificarEntrega();
                    break;
                }
            break;
        }
    }
}
