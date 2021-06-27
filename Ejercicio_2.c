#include <stdio.h>
#include <stdlib.h>

int main(int argc, int argv){
    int *array = NULL, *array2 = NULL, num, cont;

    printf("¿Cuantos elementos tiene el arreglo\n");
    scanf("%d", &num);

    array = (int*)calloc(num, sizeof(int));                 // Se reserva la memoria de acuerdo al tamaño del tipo de dato ingresados. 
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

        num = num/2;                                        // La variable num establecera el incremento o disminución del espacio de     
        array2 = (int*)realloc(array, num*sizeof(int));     // memoria reservada para guardar más datos o menos datos, segun sea el caso. 
                                                            // En el código se reducirá el tamaño del arreglo a la mitad.                  
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