#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "funciones_comprador.h"
#include "funciones_almacenista.h"
#include "lista_almacen.h"
#include "lista_carrito.h"
#include "nodo_carrito.h"
#include "funciones_generales.h"

int verificarExistencia(nodoAlmacen *producto, int cantidad){
    if (producto->existencias >= cantidad)
    {
        producto->existencias -= cantidad;
        return 1;
    }
    else
        {
            printf("No hay suficiente existencia para la cantidad que solicita\n");
            return 0;
        }
}

void regresarExistencias(nodoCarrito *productoActual, int cantidad){
    productoActual->productoAsociado->existencias += productoActual->cantidad;
}

void agregarAlCarrito(listaCarrito *carrito, nodoAlmacen *producto, int cantidad){
    nodoCarrito *repetido = inspeccionarCarrito(carrito, producto);
    if (repetido != NULL && verificarExistencia(producto, cantidad != 0))
    {
        repetido->cantidad += cantidad;
        return;
    }
    nodoCarrito *p = crearNodoCarrito(producto->nombreProducto, producto->precioUnitario,cantidad);
    if(carritoVacio(carrito))
    {
        carrito->inicio = carrito->fin = p;
        p->productoAsociado = producto;
        carrito->n++;
        carrito->total+=(producto->precioUnitario*cantidad);
        return;
    }
    p->ant = carrito->fin;
    carrito->fin->sig = p;
    carrito->fin = p;
    p->productoAsociado = producto;
    carrito->n++;
    carrito->total+=(producto->precioUnitario*cantidad);
    return;
}

void seleccionarProductosCompra(listaAlmacen *lista, listaCarrito *carrito, colaPedidos *pedidos, int *hayCarrito){
    printf("\t\tSeleccionar Productos\n");
    char opcion[2];
    int cantidad;
    nodoAlmacen *productoActual=lista->inicio;
    imprimirProducto(productoActual);
    do{
        printf("\n\n\n[S] Siguiente producto\n");
        printf("[P] Producto anterior\n");
        printf("[I] Primer producto\n");
        printf("[F] Ultimo producto\n");
        printf("[O] Seleccionar producto\n");
        printf("[H] Regresar\n");
        fflush(stdin);
        fgets(opcion,2,stdin);
        strlwr(opcion);
        switch(opcion[0]){
            case 's':
                if(lista->fin==productoActual){
                    productoActual=lista->inicio;
                }else{
                    productoActual=siguienteElementoAlmacen(productoActual);
                }
            break;
            case 'p':
                if(lista->inicio==productoActual){
                    productoActual=lista->fin;
                }else{
                    productoActual=anteriorElementoAlmacen(productoActual);
                }
            break;
            case 'i':
                productoActual=lista->inicio;
            break;
            case 'f':
                productoActual=lista->fin;
            break;
            case 'o':
                do{
                    printf("La existencia actual de ese producto es: %d\n", productoActual->existencias);
                    printf("Indique la cantidad de producto(enteros):\n");
                    fflush(stdin);
                    scanf("%d", &cantidad);
                }while(cantidad <= 0 || verificarExistencia(productoActual, cantidad)!= 1);
                agregarAlCarrito(carrito, productoActual, cantidad);
                *hayCarrito=1;
            break;
            case 'h':

            break;
            default:
                system("cls");
                printf("Ingrese una opcion correcta\n");
                system("pause");
            break;
        }
        imprimirProducto(productoActual);
    }while(opcion[0]!='h');
}

void revisarCarrito(listaCarrito *carrito, colaPedidos *pedidos, int *hayCarrito){
    printf("\t\tRevisar Carrito\n");
    char opcion[2];
    int c, ans;
    nodoCarrito *aux;
    int cantidad, diferencia;
    if(carritoVacio(carrito))
    {
        printf("El carrito esta vacio\n");
        system("pause");
    }
    else
    {
        nodoCarrito *productoActual=carrito->inicio;
        imprimirProductoCarrito(productoActual);
        printf("\nTotal: %.2f",carrito->total);
        do{
            printf("\n\n\n[S] Siguiente producto\n");
            printf("[P] Producto anterior\n");
            printf("[I] Primer producto\n");
            printf("[F] Ultimo producto\n");
            printf("[O] Modificar cantidad del producto\n");
            printf("[Q] Eliminar producto del carrito\n");
            printf("[C] Confirmar pedido\n");
            printf("[H] Menu anterior\n");
            fflush(stdin);
            fgets(opcion,2,stdin);
            strlwr(opcion);
            switch(opcion[0]){
                case 's':
                    if(carrito->fin == productoActual){
                        productoActual = carrito->inicio;
                    }else{
                        productoActual = siguienteElementoCarrito(productoActual);
                    }
                    c = 1;
                break;
                case 'p':
                    if(carrito->inicio == productoActual){
                        productoActual=carrito->fin;
                    }else{
                        productoActual=anteriorElementoCarrito(productoActual);
                    }
                    c = 1;
                break;
                case 'i':
                    productoActual=carrito->inicio;
                    c = 1;
                break;
                case 'f':
                    productoActual=carrito->fin;
                    c = 1;
                break;
                case 'o':
                    do{
                        printf("¿Cuál es la nueva cantidad de producto que quiere?\n");
                        printf("La existencia actual de ese producto es %d unidades\n", productoActual->productoAsociado->existencias);
                        fflush(stdin);
                        scanf("%d", &cantidad);
                        if (cantidad <=0 || cantidad > productoActual->productoAsociado->existencias)
                            printf("Ingresa una cantidad válida\n");
                    }while(cantidad <=0 || cantidad > productoActual->productoAsociado->existencias);
                    if (cantidad > productoActual->cantidad)
                    {
                        diferencia = cantidad - productoActual->cantidad;
                        if (verificarExistencia(productoActual->productoAsociado, diferencia) != 0){
                            productoActual->cantidad += diferencia;
                            carrito->total+=productoActual->precioUnitario*diferencia;
                        }
                    }
                    else if (cantidad < productoActual->cantidad)
                    {
                        diferencia = productoActual->cantidad - cantidad;
                        productoActual->productoAsociado->existencias += diferencia;
                        productoActual->cantidad = cantidad;
                        carrito->total-=productoActual->precioUnitario*cantidad;
                    }
                    system("cls");
                break;
                case 'q':
                    c = 1;
                    printf("¿Seguro que quiere borrar este producto de su carrito? [1=SI 0=NO]\n");
                    fflush(stdin);
                    scanf("%d", &ans);
                    if (ans != 0)
                    {
                        if (productoActual->ant == NULL && productoActual->sig == NULL)
                        {
                            carrito->inicio = carrito->fin = NULL;
                            c = 0;
                            regresarExistencias(productoActual, cantidad);
                            printf("Tu carrito ahora esta vacio\n");
                            system("pause");
                        }
                        else if(productoActual->ant == NULL)
                        {
                            carrito->inicio = productoActual->sig;
                            productoActual->sig->ant = NULL;
                            aux = productoActual;
                            productoActual = productoActual->sig;
                            aux->sig = NULL;
                            regresarExistencias(aux, cantidad);
                        }
                        else if(productoActual->sig == NULL)
                        {
                            carrito->fin = productoActual->ant;
                            productoActual->ant->sig = NULL;
                            aux = productoActual;
                            productoActual = productoActual->ant;
                            aux->ant = NULL;
                            regresarExistencias(aux, cantidad);
                        }
                        else
                        {
                            productoActual->sig->ant = productoActual->ant;
                            productoActual->ant->sig = productoActual->sig;
                            aux = productoActual;
                            productoActual = productoActual->ant;
                            aux->sig = aux->ant = NULL;
                            regresarExistencias(aux, cantidad);
                        }
                        system("cls");
                    }
                    *hayCarrito=0;
                break;
                case 'c':
                    realizarPedido(pedidos, carrito,hayCarrito);
                    carrito=NULL;
                break;
                case 'h':
                    return;
                break;
                default:
                    c = 1;
                    system("cls");
                    printf("Ingrese una opcion correcta\n");
                    system("pause");
                break;
            }
            if(c == 1)
                imprimirProductoCarrito(productoActual);
        }while(opcion[0]!='h' && !carritoVacio(carrito));
    }
}

void realizarPedido(colaPedidos *cola_pedidos, listaCarrito *carrito, int *hayCarrito){
    nodoCarrito *producto;
    int ans;
    char nombre[50], direccion[100], telefono[10];

    system("cls");
    printf("\tRealizar pedido\n");
    if (carritoVacio(carrito))
    {
        printf("Tu carrito esta vacio, agrega lo que mas te guste a tu carrito para hacer un pedido\n");
        system("pause");
        return;
    }
    printf(">>>>>>>>>>>Resumen del pedido:<<<<<<<<<<\n");
    producto = carrito->inicio;
    while(producto != NULL)
    {
        printf("\t%s",producto->nombreProducto);
        printf("\t\tPrecio: %.2f\tCantidad: %d\n",producto->precioUnitario,producto->cantidad);
        producto = producto->sig;
    }
    printf("Total del pedido: %f\n", carrito->total);
    system("pause");
        printf("¿Desea confirmar su pedido? [1=SI 0=NO]\n");
        fflush(stdin);
        scanf("%d",&ans);
        if (ans != 0)
        {
            *hayCarrito=0;
            printf("Ingrese su nombre:\n");
            fflush(stdin);
            fgets(nombre, 50, stdin);
            quitarSalto(nombre);

            printf("Ingrese su direccion:\n");
            fflush(stdin);
            fgets(direccion, 100, stdin);
            quitarSalto(direccion);

            printf("Ingrese su numero de telefono (sin espacios)\n");
            fflush(stdin);
            fgets(telefono, 11, stdin);
                if (strlen(telefono) != 10)
                    {
                        do{
                            printf("Ingrese un numero valido\n");
                            fflush(stdin);
                            fgets(telefono, 11, stdin);
                        }while(strlen(telefono) != 10);
                    }
            nodoColaPedidos *pedido = crearNodoColaPedidos(carrito, nombre, direccion, telefono);
            push_pedido(pedido, cola_pedidos);
            system("pause");
            return;
        }
    return;
}

void imprimirProductoCarrito(nodoCarrito *nodo){
    system("cls");
    printf("\t\t\t%s\n",nodo->nombreProducto);
    printf("\t\tPrecio: %.2f\t Cantidad solicitada: %d\n",nodo->precioUnitario, nodo->cantidad);
}
