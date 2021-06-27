#ifndef EJERCICIO_4
#define EJERCICIO_4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _nodo nodo;
typedef int INFO;

struct _nodo{
    INFO info;
    nodo *sig;
};

typedef struct _lista lista;

struct _lista{
    nodo *head;
    nodo *tail;
    int num;
};

nodo* crear_nodo(INFO info);
lista *crear_lista();
bool insertar_fin(lista *l, INFO info);
void imprimir_lista(lista *l);

#endif