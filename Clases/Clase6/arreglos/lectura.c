/*Este programa muestra como 
leer datos del teclado para llenar 
informacion un arreglo
*/
#include<stdio.h>
int main(){
    float cal[5];
    for(int i=0;i<5;++i){
        printf("Ingresa una calificacion\n");
        scanf("%f",&cal[i]);
    }
    printf("[\n");
    for(int i=0;i<5;++i){
        printf("%.2f, ", cal[i]);
    }
    printf("]\n");
    return 0;
}