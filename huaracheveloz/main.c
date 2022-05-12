#include <stdio.h>
#include "menus.h"
#include "funciones_almacenista.h"
#include "funciones_comprador.h"
#include "funciones_gerente.h"
#include "funciones_repartidor.h"

int main (){
    int seleccion=menu_de_menus();
    switch(seleccion){
        case 0:
            return 1;
        break;
        case 1:
            seleccion=menu_almacenista();
            switch(seleccion){
                case 0:
                    main();
                break;
                case 1:
                    mostrarProductos();
                break;
                case 2:
                    registrarProductos();
                break;
            }
        break;
        case 2:
            seleccion=menu_comprador();
            switch(seleccion){
                case 0:
                    main();
                break;
                case 1:
                    seleccionarProductos();
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
                case 0:
                    main();
                break;
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
                case 0:
                    main();
                break;
                case 1:
                    pedidoAsignado();
                break;
                case 2:
                    notificarEntrega();
                break;
            }
        break;
    }
    return 0;
}
