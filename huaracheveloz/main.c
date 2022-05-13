#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "lista_almacen.h"
#include "nodo_almacen.h"
#include "funciones_almacenista.h"
#include "funciones_comprador.h"
#include "funciones_gerente.h"
#include "funciones_repartidor.h"

void principal(listaAlmacen *almacen);

int main (){
    listaAlmacen *almacen=nuevaLista();
    inicializarListaAlmacen(almacen);
    imprimeListaAlmacen(almacen);
    principal(almacen);
    return 1;
}

void principal(listaAlmacen *almacen){
    while(1){
        system("cls");
        int seleccion=menu_de_menus();
        switch(seleccion){
            case 0:
                return;
            break;
            case 1:
                seleccion=menu_almacenista();
                switch(seleccion){
                    case 1:
                        mostrarProductos(almacen);
                    break;
                    case 2:
                        registrarProductos(almacen);
                    break;
                }
            break;
            case 2:
                seleccion=menu_comprador();
                switch(seleccion){
                    case 1:
                        seleccionarProductosCompra();
                    break;
                    case 2:
                        revisarCarrito();
                    break;
                    case 3:
                        realizarPedido();
                    break;
                }
            break;
            case 3:
                seleccion=menu_gerente();
                switch(seleccion){
                    case 1:
                        colaPedidos();
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
