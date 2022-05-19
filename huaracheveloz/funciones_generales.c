#include "funciones_generales.h"
#include <string.h>

void separarNombre(char *nombre){
    for(int i=0;i<strlen(nombre);i++){
        if(nombre[i]=='.')
            nombre[i]=' ';
    }
}

void unirNombre(char *nombre){
    for(int i=0;i<strlen(nombre);i++){
        if(nombre[i]==' ')
            nombre[i]='.';
    }
}

void quitarSalto(char *nombre){
    for(int i=0;i<strlen(nombre);i++){
        if(nombre[i]=='\n')
            nombre[i]='\0';
    }
}
