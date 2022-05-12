#include "menus.h"
#include <stdio.h>
#include <stdlib.h>

int menu_de_menus(){
    int seleccion;
    int n;
    printf("Bienvenido al huarache veloz!\nPor favor, seleccione un usuario:\n");
    printf("1. Almacenista\n");
    printf("2. Comprador\n");
    printf("3. Gerente\n");
    printf("4. Repartidor\n");
    printf("0. Salir del programa\n");
    do{
        n=scanf("%d",&seleccion);
        if (seleccion<0||seleccion>4)
            printf("Seleccione una opción válida\n");
    }while(seleccion<0||seleccion>4);
    system("cls");
    return seleccion;
}

int menu_almacenista(){
    int seleccion;
    int n;
    printf("Bienvenido Almacenista\nPor favor, seleccione una acción:\n");
    printf("1. Navejar la lista\n");
    printf("2. Registrar nuevo inventario\n");
    printf("0. Menu anterior\n");
    do{
        fflush(stdin);
        n=scanf("%d",&seleccion);
        if (seleccion<0||seleccion>2||n!=1)
            printf("Seleccione una opción válida\n");
    }while(seleccion<0||seleccion>2||n!=1);
    system("cls");
    return seleccion;
}
int menu_comprador(){
    int seleccion;
    int n;
    printf("Bienvenido al huarache veloz, amado cliente!\nPor favor, seleccione una acción:\n");
    printf("1. Seleccionar producto\n");
    printf("2. Revizar carrito de compras\n");
    printf("3. Realizar pedido\n");
    printf("0. Menú anterior\n");
    do{
        fflush(stdin);
        n=scanf("%d",&seleccion);
        if (seleccion<0||seleccion>3||n!=1)
            printf("Seleccione una opción válida\n");
    }while(seleccion<0||seleccion>3||n!=1);
    system("cls");
    return seleccion;
}
int menu_gerente(){
    int seleccion;
    int n;
    printf("Bienvenido Gerente\nPor favor, seleccione una acción:\n");
    printf("1. Revisar cola de pedidos\n");
    printf("2. Cola de repartidores en espera\n");
    printf("3. Lista de pedidos en tránsito\n");
    printf("4. Asignar pedido\n");
    printf("0. Menú anterior\n");
    do{
        fflush(stdin);
        n=scanf("%d",&seleccion);
        if (seleccion<0||seleccion>4||n!=1)
            printf("Seleccione una opción válida\n");
    }while(seleccion<0||seleccion>4||n!=1);
    system("cls");
    return seleccion;
}
int menu_repartidor(){
    int seleccion;
    int n;
    printf("Bienvenido Almacenista\nPor favor, seleccione una acción:\n");
    printf("1. Pedido asignado\n");
    printf("2. Notificar entrega\n");
    printf("0. Menu anterior\n");
    do{
        fflush(stdin);
        n=scanf("%d",&seleccion);
        if (seleccion<0||seleccion>2||n!=1)
            printf("Seleccione una opción válida\n");
    }while(seleccion<0||seleccion>2||n!=1);
    system("cls");
    return seleccion;
}
