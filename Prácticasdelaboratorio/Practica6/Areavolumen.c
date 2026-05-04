#include<stdio.h>
int main(){
    int r,h,p,op;
    printf ("Ingresa el radio y la altura del cilindro: \n");
    scanf ("%d %d", &r, &h);
    printf ("¿Que operacion del cilindro queires clacular?\n");
    printf("1. Perimetro\n");
    printf ("2. Area\n");
    printf ("3. Volumen\n");
    scanf ("%d", &op);
    switch(op){ 
        case 1:
        p=2*3.1416*r;
        break;
        case 2:
        p=2*3.1416*r*r+2*3.1416*r*h;
        break;
        case 3:
        p=3.1416*r*h*r;
    }
    printf ("El resultado es %d\n",p);
    return 0;
}