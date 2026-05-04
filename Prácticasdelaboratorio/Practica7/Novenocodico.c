#include <stdio.h>
/*
INSTRUCCIONES:
Determina cuál número es el mayor
*/
int main() {
    int a, b, c;
    printf("Ingresa tres numeros: \n");
    scanf("%d %d %d", &a, &b, &c);
    if (a>b && a>c) {
        printf("El primer numero es el mayor\n");
    } else if (b>a && b>c) {
        printf("El segundo numero es el mayor\n");
    } else {
        printf("El tercer numero es el mayor\n");
    }
    return 0;
}