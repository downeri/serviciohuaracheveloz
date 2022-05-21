#include "funciones_almacenista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista_almacen.h"
#include "nodo_almacen.h"
#include "funciones_generales.h"
void mostrarProductos(listaAlmacen *lista){
    navegarLista(lista);
}

void registrarProductos(listaAlmacen *lista){
    system("cls");
    int n,o;
    nodoAlmacen *producto;
    char opcion[2];
    char nuevoNombre[30];
    float nuevoPrecio;
    int nuevoExistencia;
    do{
        printf("\t\tRegistrar productos\n");
        printf("[N] Nuevo producto\n");
        printf("[A] Seleccionar del almacen\n");
        printf("[H] Salir\n");
        fflush(stdin);
        fgets(opcion,2,stdin);
        strlwr(opcion);
        switch(opcion[0]){
            case 'n':
                system("cls");
                printf("Nombre producto:\n");
                do{
                    fflush(stdin);
                    o=scanf("%f",&nuevoPrecio);
                    if(o!=1)
                        printf("Ingrese un numero\n");
                }while(o!=1);
                printf("Existencias:\n");
                fflush(stdin);
                do{
                    o=scanf("%d",&nuevoExistencia);
                    if(o!=1)
                        printf("Ingrese un numero\n");
                }while(o!=1);
                quitarSalto(nuevoNombre);
                agregaDatoFinal(lista,nuevoNombre,nuevoPrecio,nuevoExistencia);
                agregarAlTxt(nuevoNombre,nuevoPrecio,nuevoExistencia);
            break;
            case 'a':
                system("cls");
                producto=seleccionarProductos(lista);
                if(producto==NULL){
                    break;
                }
                system("cls");
                printf("Cantidad a agregar:\n");
                do{
                    fflush(stdin);
                    o=scanf("%d",&n);
                    if(o!=1)
                        printf("Ingrese un numero entero\n");
                }while(o!=1);
                producto->existencias+=n;
                reescribirTxt(lista);
            break;
        }
    }while(opcion[0]!='h');
}

void imprimirProducto(nodoAlmacen *nodo){
    system("cls");
    printf("\t\t\t%s\n",nodo->nombreProducto);
    printf("\t\tPrecio: %.2f\tUnidades en existencia: %d",nodo->precioUnitario,nodo->existencias);
}


void reescribirTxt(listaAlmacen *lista){
    FILE *archivo;
    char nombreTemp[30];
    archivo=fopen("./productos.txt","w");
    nodoAlmacen *p;
    p=lista->inicio;
    while (p!=NULL) {
        strcpy(nombreTemp,p->nombreProducto);
        unirNombre(nombreTemp);
        fprintf(archivo,"%s %.2f %d",nombreTemp,p->precioUnitario,p->existencias);
        if(p->sig!=NULL)
            fprintf(archivo,"\n");
        p=p->sig;
    }
    fclose(archivo);
}

void agregarAlTxt(char nombre[30],float precio, int existencias){
    FILE *archivo;
    unirNombre(nombre);
    archivo=fopen("./productos.txt","a");
    fprintf(archivo,"\n%s %.2f %d",nombre,precio,existencias);
    fclose(archivo);
}

