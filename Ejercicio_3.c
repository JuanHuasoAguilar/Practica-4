#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo nodo;
typedef int INFO;

struct _nodo{
    INFO info;
    nodo *sig;
};

nodo* crear_nodo_con_malloc1();
nodo* crear_nodo_con_malloc2(INFO info);
nodo* crear_nodo_con_calloc1();
nodo* crear_nodo_con_calloc2(INFO info);

int main(){
    nodo *n1, *n2, *n3, *n4;
    n1 = crear_nodo_con_malloc1();                          // La diferencia que calloc en automatico hace que al tipo de dato que
    n2 = crear_nodo_con_malloc2(1);                         // crea las hace igual a cero y los apuntadores a NULL. Por el contrario
    n3 = crear_nodo_con_calloc1();                          // malloc no hace ninguna de las dos cosas antes mencionadas.
    n4 = crear_nodo_con_calloc2(1);
    printf("\nCREAR NODO CON MALLOC");
    printf("\nSin valor de info como parametro al crear el nodo: ");
    imprimir_nodo(n1);
    printf("\nCon valor de info como parametro al crear el nodo: ");
    imprimir_nodo(n2);
    printf("\n\n\nCREAR NODO CON CALLOC");
    printf("\nSin valor de info como parametro al crear el nodo: ");
    imprimir_nodo(n3);
    printf("\nCon valor de info como parametro al crear el nodo: ");
    imprimir_nodo(n4);
    return 0;
}



nodo* crear_nodo_con_malloc1(){
    nodo *t = (nodo*)malloc(sizeof(nodo));              // Sin asignación de valor a info.
    return t;
}

nodo* crear_nodo_con_malloc2(INFO info){
    nodo *t = (nodo*)malloc(sizeof(nodo));              // Con asignación de valor a info.
    t->info = info;
    return t;
}

nodo* crear_nodo_con_calloc1(){
    nodo *t = (nodo*)calloc(1, sizeof(nodo));           // Sin asignación de valor a info.
    return t;
}

nodo* crear_nodo_con_calloc2(INFO info){
    nodo *t = (nodo*)calloc(1, sizeof(nodo));           // Con asignación de valor a info.
    t->info = info;
    return t;
}

void imprimir_nodo(nodo *n){
    nodo *impr = n;
    printf("\n[ Valor: %d , direccion: %p ]", impr->info, n);
    printf("\n");
    if(impr->sig == NULL)
        printf("[nodo->sig] El nodo siguiente apunta a nulo");
    else{
        printf("[nodo->sig] El nodo siguiente apunta a otro valor diferente de nulo");
    }
    printf("\n");
}