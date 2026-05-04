// El usuario ingresa números.
// El programa debe sumar todos los números hasta que se ingrese 0.
#include <stdio.h>
int main()
{
    float r = 0, m, z, x;
    printf("Ingresar un numero: \n");
    scanf("%f ", &x);
    while (x != 0)
    {
        r+=x;
        printf("\nIngrrese otro numero\n");
        scanf("%f", &x);
        
    }
    printf("El resultado de la suma es: %f\n", r);
    return 0;
}