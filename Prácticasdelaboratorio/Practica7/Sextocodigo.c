#include <stdio.h>

/*
INSTRUCCIONES:
Determina si A es mayor que B
*/

int main() {
    int a, b;
    printf ("Ingresa dos numeros: \n");
    scanf("%d %d", &a, &b);

    if (a>b) {
        printf("El primer numero es mayor\n");
    } else {
        printf("El segundo numero es mayor o igual\n");
    }

    return 0;
}
