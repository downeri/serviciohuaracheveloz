#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista_almacen.h"
#include "nodo_almacen.h"
#include "funciones_generales.h"


listaAlmacen *nuevalistaAlmacen(void) {
    listaAlmacen *p;
    p = malloc(sizeof(listaAlmacen));
    p->inicio = p->fin = NULL;
    p->n = 0;
    return p;
}

void imprimeListaAlmacen(listaAlmacen *lista) {
    nodoAlmacen *p;
    if (vacia(lista)) {
        printf("Lista vacia\n");
        return;
    }
    p = lista->inicio;
    while (p!=NULL) {
        printf("[%s]\n",p->nombreProducto);
        printf("[%f]\n",p->precioUnitario);
        printf("[%d]\n",p->existencias);
        p=p->sig;
    }
    printf("\n");
    return;
}

nodoAlmacen *siguienteElementoAlmacen(nodoAlmacen *nodo) {
    return nodo->sig;
}

nodoAlmacen *anteriorElementoAlmacen(nodoAlmacen *nodo) {
    return nodo->ant;
}

void imprimeListaAlmacenReversa(listaAlmacen *lista) {
    nodoAlmacen *p;
    if (vacia(lista)) {
        printf("Lista vacia\n");
        return;
    }
    p = lista->fin;
    while (p!=NULL) {
        printf("[%s]\n",p->nombreProducto);
        printf("[%f]\n",p->precioUnitario);
        printf("[%d]\n",p->existencias);
        p = p->ant;
    }
    printf("\n");
    return;
}

int vacia(listaAlmacen *lista) {
    return lista->inicio==NULL;
}

void agregaDatoFinal(listaAlmacen *lista, char *producto, float precio, int existencias) {
    nodoAlmacen *p = crear(producto,precio,existencias);
    if (vacia(lista)) {
        lista->inicio=lista->fin=p;
        lista->n++;
        //printf("Añadido %s %d\n",producto,lista->n);
        return;
    }
    p->ant=lista->fin;
    lista->fin->sig=p;
    lista->fin=p;
    lista->n++;
    //printf("Añadido %s %d\n",producto,lista->n);
    return;
}

void inicializarListaAlmacen(listaAlmacen *lista){
    char nombre[30];
    float precio;
    int inventario;
    FILE *productos=fopen("./productos.txt","r");
    char string[50];
    while(fgets(string,50,productos)!=NULL){
        sscanf(string,"%s %f %d",nombre,&precio,&inventario);
        separarNombre(nombre);
        //printf("%s %f %d\n",nombre,precio,inventario);
        agregaDatoFinal(lista,nombre,precio,inventario);
    }
    fclose(productos);
}

nodoAlmacen *seleccionarProductos(listaAlmacen *lista){
    char opcion[2];
    nodoAlmacen *productoActual=lista->inicio;
    imprimirProducto(productoActual);
    do{
        printf("\n\n\n[S] Siguiente producto\n");
        printf("[P] Producto anterior\n");
        printf("[I] Primer producto\n");
        printf("[F] Ultimo producto\n\n");
        printf("[O] Seleccionar producto\n");
        printf("[H] Menú anterior\n");
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
                return productoActual;
            break;
            default:
                system("cls");
                printf("Ingrese una opcion correcta\n");
            break;
        }
        imprimirProducto(productoActual);
    }while(opcion[0]!='h');
    return NULL;
}

void navegarLista(listaAlmacen *lista){
    char opcion[2];
    int c;
    nodoAlmacen *productoActual=lista->inicio;
    imprimirProducto(productoActual);
    do{
        printf("\n\n\n[S] Siguiente producto\n");
        printf("[P] Producto anterior\n");
        printf("[I] Primer producto\n");
        printf("[F] Ultimo producto\n");
        printf("[H] Menú anterior\n");
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
                c=1;
            break;
            case 'p':
                if(lista->inicio==productoActual){
                    productoActual=lista->fin;
                }else{
                    productoActual=anteriorElementoAlmacen(productoActual);
                }
                c=1;
            break;
            case 'i':
                productoActual=lista->inicio;
                c=1;
            break;
            case 'f':
                productoActual=lista->fin;
                c=1;
            break;
            case 'h':
            break;
            default:
                c=0;
                system("cls");
                printf("Ingrese una opcion correcta\n");
            break;
        }
        if(c==1)
            imprimirProducto(productoActual);
    }while(opcion[0]!='h');
}
