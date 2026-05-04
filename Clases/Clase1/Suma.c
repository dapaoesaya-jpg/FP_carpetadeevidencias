#include <stdio.h>
int main(){
    float var1,var2,r;
    printf ("Digite un numero:\n");
    scanf ("%g",&var1);
    printf ("Digite otro numero:\n");
    scanf ("%g",&var2);
    r=var1+var2;
    printf("El resultado de la suma de %g+%g=%g \n",var1,var2,r);
    return 0;
}