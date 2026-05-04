#include <stdio.h>
int main (){
    int x;
    float v;
    //Suma
    x=4.5+3;
    printf ("x=%d \n",x);
    v=4.5+3;
    printf ("v=%.2f \n",v);
    //RESTA
    x=4.5-3;
    printf("x=%d \n",x);
    v=4.5-3;
    printf ("v=%.2f \n",v);
    //MULTIPLICACION
    x=4.5*3;
    printf ("x=%d \n",x);
    v=4.5*3;
    printf ("v=%.2f \n",v);
    v=4*3;
    printf ("v=%.2f \n",v);
    //DIVISION
    x=4/3;
    printf ("x=%d \n",x);
    x=4.0*3.0;
    printf ("v=%d \n",x);
    v=4/3;
    printf ("v=%.2f \n",v);
    v=4.0/3;
    printf ("x=%.2f \n",v);
    v=4.0*3.0;
    printf ("v=%.2f \n",v);
    v=(float)4/3;
    printf ("v=%.2f \n",v);
    v=((float)5+3)/6;
    printf("v=%.2f \n",v);
    //MODULO
    x=15%2;
    printf ("x=%d \n",x);
    v=(15%2)/2;
    printf ("v=%.2f \n",v);
    v=(15%2)/(float)2;
    printf ("v=%.2f \n,v");
    return 0;
}