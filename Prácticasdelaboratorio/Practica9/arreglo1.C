#include <stdio.h>
/*
Este programa ilustra que todos las variables tieneen una direecciòn
*/
int main(){
    int x,y;
    float f,g;
    int array[5];
    float array2[3];
    printf ("La direccion de x es: %p\n",&x);
    printf ("La direccion de y es: %p\n",&y);
    printf ("La direccion de f es: %p\n",&f);
    printf ("La direccion de g es: %p\n",&g);
    printf ("La direccion de array es: %p\n",&array);
    printf ("La direccion de array2 es: %p\n",&array2);
    printf ("La direccion de array es: %p\n",&array[0]);
    printf ("La direccion de array2 es: %p\n",&array2[0]);
    return 0;
}