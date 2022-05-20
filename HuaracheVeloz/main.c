#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "menus.h"
#include "lista_almacen.h"
#include "nodo_almacen.h"
#include "lista_carrito.h"
#include "nodo_carrito.h"
#include "funciones_almacenista.h"
#include "funciones_comprador.h"
#include "funciones_gerente.h"
#include "funciones_repartidor.h"

void principal(listaAlmacen *almacen, listaCarrito *carrito, colaPedidos *pedidos);

int main (){
    setlocale(LC_ALL, "spanish");

    listaAlmacen *almacen = nuevaLista();
    listaCarrito *carrito;
    carrito = nuevaListaCarrito();
    colaPedidos *cola_pedidos = crearColaPedidos();

    inicializarListaAlmacen(almacen);
    principal(almacen, carrito, cola_pedidos);
    return 0;
}

void principal(listaAlmacen *almacen, listaCarrito *carrito, colaPedidos *pedidos){
    int ans;
    while(1){
        system("cls");
        int seleccion=menu_de_menus();
        switch(seleccion){
            case 0:
                return;
            break;
            case 1:
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
            case 2:
                do{
                    seleccion=menu_comprador();
                    switch(seleccion){
                        case 1:
                            seleccionarProductosCompra(almacen, carrito, pedidos);
                        break;
                        case 2:
                            revisarCarrito(carrito, pedidos);
                        break;
                        case 3:
                             realizarPedido(pedidos, carrito);
                        break;
                        case 0:
                            printf("¿Seguro que quieres salir? ¡perderas tu carrito de compras! [1=SI 0=NO]\n");
                            scanf("%d", &ans);
                            while(ans != 1 && ans != 0)
                            {
                                printf("Ingresa una opcion valida:\n");
                                scanf("%d", &ans);
                            }
                            if(ans == 1)
                            {
                                liberarCarrito(carrito);
                                listaCarrito *carrito = nuevaListaCarrito();
                            }
                        break;
                    }
                    system("cls");
                }while(seleccion != 0);
            break;
            case 3:
                seleccion=menu_gerente();
                switch(seleccion){
                    case 1:
                        //colaPedidos();
                    break;
                    case 2:
                        repartidoresDisponibles();
                    break;
                    case 3:
                        repartidoresTransito();
                    break;
                    case 4:
                        asignarPedido();
                    break;
                }
            break;
            case 4:
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
