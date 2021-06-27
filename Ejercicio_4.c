#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Ejercicio_4.h"

int main(){
    lista *l1;
    l1 = crear_lista();
    
    insertar_fin(l1, 10);
    printf("\nCreando el nodo #1: ");
    imprimir_lista(l1);
    insertar_fin(l1, 20);
    printf("\nCreando el nodo #2: ");
    imprimir_lista(l1);
    insertar_fin(l1, 30);
    printf("\nCreando el nodo #3: ");
    imprimir_lista(l1);
    insertar_fin(l1, 40);
    printf("\nCreando el nodo #4: ");
    imprimir_lista(l1);
    insertar_fin(l1, 50);
    printf("\nCreando el nodo #5: ");
    imprimir_lista(l1);

    return 0;
}


nodo* crear_nodo(INFO info){
    nodo *t = (nodo*)malloc(sizeof(nodo));
    t->sig = NULL;
    t->info = info;
    return t;
}

lista *crear_lista(){
    lista *l = (lista*)malloc(sizeof(lista));
    l->head = l->tail = NULL;
    l->num = 0;
    return l;
}

bool insertar_fin(lista *l, INFO info){
    nodo *nuevo = crear_nodo(info);
    if(l->head == NULL && l->tail == NULL){
        l->head = l->tail = nuevo;              
        l->num++;
        return true;
    }
    else{
       l->tail->sig = nuevo;
       l->tail = nuevo;                         
       l->num++;
       return true;
    }
    return false;
}

void imprimir_lista(lista *l){
    for(nodo *t = l->head; t !=NULL; t = t->sig){
        printf("[ Info: %d, Direccion: %p ] ->", t->info, t);
        printf(" ");
    }
    printf("\n");
}