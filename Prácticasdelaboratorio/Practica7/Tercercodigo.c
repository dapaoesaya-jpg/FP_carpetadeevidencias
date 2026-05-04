#include <stdio.h>

/*
INSTRUCCIONES:
Usa el operador % para verificar si el número es par.
*/

int main() {
    int num;
    printf("Ingresa un número: ");
    scanf("%d", &num);

    if (num%2 == 0) {
        printf("Es par\n");
    }

    return 0;
}