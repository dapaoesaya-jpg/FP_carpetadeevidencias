/*El usuario ingresa números (termina con 0).
Mostrar cuántos números positivos fueron ingresados,
cuaátos negativos.*/
#include <stdio.h>
void main()
{
    int i = 0, j = 0;
    float x;
    while (x != 0)
    {
        printf("ingresa los numeros y cuando quieras teminar ingresa 0:\n");
        scanf("%f", &x);
        if (x >0)
        {
            do{
                i++;
            }
            while(i==x);
        }
        if (x<0)
        {
            do{
                j++;
            }
            while(j==x);
        }
    }
    printf("Los numero positivos son: %d\n", i);
    printf("Los numero negativos son: %d\n", j);
}
