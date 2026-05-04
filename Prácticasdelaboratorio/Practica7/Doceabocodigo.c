#include <stdio.h>

/*
INSTRUCCIONES:
Usa operador ternario para imprimir Par o Impar
*/

int main() {
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("%s\n", (num%2==0) ? "Par" : "Impar");

    return 0;
}