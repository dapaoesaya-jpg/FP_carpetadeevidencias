//Al recibir como datos un grupo de números naturales 
//positivos, cualcule el cuadrado de esotos numeros. 
//Imprima el cuadrado del número y al final la suma de los cuadrados*/
#include<stdio.h>
int main (){
    int num,cuad,suma=0;
    while(num!=0){
        cuad=num*num;
        suma+=cuad;
        printf("el cuadrado de %i es %i\n", num, cuad);
        printf("Ingresa un número: \n");
        scanf("%i",&num);
    }
    printf ("La suma total es : %d\n", suma);
    return 0;
}
