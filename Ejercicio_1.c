#include <stdio.h>
#include <stdlib.h>

int main(int argc, int argv){
    int *array = NULL, *array2 = NULL, num, cont;

    printf("¿Cuantos elementos tiene el arreglo\n");
    scanf("%d", &num);
    
    array = (int*)realloc(array, num*sizeof(int));     
  /*
    printf("Uso de realloc: \n");                               // <-- Si ponemos este linea de codigo comprobamos el valor del lugar que reservo realloc 
    printf("Vector reservado:\n\t[");                           //     es decir, diferente de cero.                                                        
        for(cont = 0; cont < num; cont++){
            printf("\tValor: %d dir:%p", *(array+cont), array+cont);
        }
        printf("\t]\n\n");
  */
    if(array !=NULL){                                       
        for(cont = 0; cont < num; cont++){
            printf("Ingresa el elemento %d\n", cont+1);
            scanf("%d", (array+cont));
        }
        printf("Vector reservado:\n\t[");
        for(cont = 0; cont < num; cont++){
            printf("\tValor: %d dir:%p", *(array+cont), array+cont);
        }
        printf("\t]\n");

        num *= 2;                                               // Además la llamada de realloc a diferencia de malloc o calloc es que puede reasignar 
        array2 = (int*)realloc(array, num*sizeof(int));         // el tamaño de la memoria reservada de una variable de algun tipo de dato, en este    
                                                                // caso se duplica el tamaño a reservar (num *= 2).                                     
        if(array!=NULL){
            for(; cont < num; cont++){
                printf("Ingresa el elemento %d\n", cont+1);
                scanf("%d", (array+cont));
            }

            printf("Vector reservado:\n\t[");
            for(cont = 0; cont < num; cont++){
                printf("\tValor: %d dir:%p", *(array+cont), array+cont);
            }
        }
        printf("\t]\n");
        printf("La memoria sera liberada\n");
        free(array);
    }
    return 0;
}