#include<stdio.h>
int main(){
    int x,y;
    //INCREMETOS
    //POST
    x=7;
    printf ("x=%d \n",x);
    y=x++;
    printf ("x=%d \n",x);
    printf ("y=%d \n",y);
    //PRE
    x=7;
    printf ("x=%d \n",x);
    y=++x;
    printf ("x=%d \n",x);
    printf ("y=%d \n",y);
    //DECREMENTOS
    //POST
    x=7;
    printf ("x=%d \n",x);
    y=x--;
    printf ("x=%d \n",x);
    printf ("y=%d \n",y);
    //PRE
    x=7;
    printf ("x=%d \n",x);
    y=--x;
    printf ("x=%d \n",x);
    printf ("y=%d \n",y);
    return 0;
}