#include<stdio.h>
/*
Este programa sirve par aimpedir 
las direcciones de los elementos
*/
int main (){
    int array[7];
    float array2[10];
    printf ("El tamaño de un entero en bytes es : %ld\n", sizeof(int));
    printf ("\n");
    for (int i=0;i<7;i++){
        printf("La direccion del elemento  %d es: %p\n", i, &array[i]);
    }
    printf ("\n");

    for (int i=0;i<10;i++){
        printf("La direccion del elemento  %d es: %p\n", i, &array2[i]);
    } 
    return 0;
    
}