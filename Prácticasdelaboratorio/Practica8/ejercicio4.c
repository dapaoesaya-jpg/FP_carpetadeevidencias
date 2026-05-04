/*Reescribe el ejercicio 2 utilizando do-while.
*/
#include<stdio.h>
void main(){
    int n=0,m;
    do{
        printf("Ingresa un numero\n");
        scanf("%d",&m); 
        n+=m;
        printf("EL resultado es %d\n",n);
        printf("Quieres realiza otra suma ingresar 1 sino ingresa 0\n");
        scanf("%d",&m);
    }
    while(m!=0);
}