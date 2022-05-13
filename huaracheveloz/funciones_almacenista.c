#include "funciones_almacenista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista_almacen.h"
#include "nodo_almacen.h"

void mostrarProductos(listaAlmacen *lista){
    char opcion[2];
    nodoAlmacen *productoActual=lista->inicio;
    imprimirProducto(productoActual);
    do{
        printf("\n\n\n[S] Siguiente producto\n");
        printf("[P] Producto anterior\n");
        printf("[I] Primer producto\n");
        printf("[F] Ultimo producto\n");
        printf("[H] Salir\n");
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
            case 'h':
            break;
            default:
                system("cls");
                printf("Ingrese una opcion correcta\n");
            break;
        }
        imprimirProducto(productoActual);
    }while(opcion[0]!='h');
}

void registrarProductos(listaAlmacen *lista){
    int n,o,total;
    nodoAlmacen *producto;
    char opcion[2];
    char nuevoNombre[30];
    float nuevoPrecio;
    int nuevoExistencia;
    printf("\t\tRegistrar productos\n");
    printf("[N] Nuevo producto\n");
    printf("[A] Seleccionar del almacen\n");
    printf("[H] Salir\n");
    fflush(stdin);
    fgets(opcion,2,stdin);
    strlwr(opcion);
    switch(opcion[0]){
        case 'n':
            printf("Nombre producto:\n");
            fflush(stdin);
            fgets(nuevoNombre,30,stdin);
            printf("Precio unitario:\n");
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
            system("cls");
            printf("Cantidad de nuevo inventario:\n");
            do{
                fflush(stdin);
                o=scanf("%d",&n);
                if(o!=1)
                    printf("Ingrese un numero entero\n");
            }while(o!=1);
            total=producto->existencias+n;
            producto->existencias+=n;
            reescribirTxt(lista,producto->nombreProducto,total);

        break;
        case 'h':
        break;
    }
}

void imprimirProducto(nodoAlmacen *nodo){
    system("cls");
    printf("\t\t\t%s\n",nodo->nombreProducto);
    printf("\t\tPrecio: %.2f\tUnidades en existencia: %d",nodo->precioUnitario,nodo->existencias);
}

void reescribirTxt(listaAlmacen *lista, char nombre[30],int nuevaCantidad){
    FILE *archivo;
    char nombreABuscar[30];
    char nombreTemp[30];
    archivo=fopen("./productos.txt","w");
    strcpy(nombreABuscar,nombre);
    unirNombre(nombreABuscar);
    nodoAlmacen *p;
    p=lista->inicio;
    while (p!=NULL) {
        strcpy(nombreTemp,p->nombreProducto);
        unirNombre(nombreTemp);
        if(nombreTemp!=nombreABuscar){
            fprintf(archivo,"%s %.2f %d",nombreTemp,p->precioUnitario,p->existencias);
        }else{
            fprintf(archivo,"%s %.2f %d",nombreTemp,p->precioUnitario,nuevaCantidad);
        }
        if(p->sig!=NULL)
            fprintf(archivo,"\n");
        p=p->sig;
    }
    fclose(archivo);
}

void agregarAlTxt(char nombre[30],float precio, int existencias){
    FILE *archivo;
    unirNombre(nombre);
    archivo=fopen("./productosT.txt","a");
    fprintf(archivo,"\n%s %.2f %d",nombre,precio,existencias);
    fclose(archivo);
}

void quitarSalto(char *nombre){
    for(int i=0;i<strlen(nombre);i++){
        if(nombre[i]=='\n')
            nombre[i]=NULL;
    }
}
