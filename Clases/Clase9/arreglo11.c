#include <stdio.h>
#define TAM 1000
int main (){
    int matriz[TAM][TAM];
    int m,n;
    printf("Ingresar el número de rengloes y columnas:\n");
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){//Sirve para cambiar de renglo
        for(int j=0;j<n;j++){//Sirve para cambiar de columnas de un reglon
            printf("Ingresar el valor para matriz [%d,%d]: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("La direccion de la matriz es : %p", matriz);
    printf("La direccióndel primer elemento de la matriz es %p\n", &matriz[0][0]);
    for(int i=0;i<m;i++){
        printf("[ ");
        for(int j=0;j<n;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("]\n");
    }
    return 0;
}