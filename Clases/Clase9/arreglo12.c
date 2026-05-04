#include<stdio.h>
#define TAM 10
/*
*@param mat,
*/
void leer(int mat[TAM][TAM],int m, int n){
    printf("[\n");
    for (int i=0;i<m; i++){
        printf("[");
        for(int j=0;j<n;++j){
            printf("%d ", mat[i][j]);
        }
        printf("]\n");
    }
}
void escribir(int mat[TAM][TAM],int m, int n){
    for(int i=0;i<m;i++){
        printf("[ ");
        for(int j=0;j<n;j++){
            printf("%d ",mat[i] [j]);
        }
        printf("]\n");
    }
}
int main(int mat[TAM][TAM],int a, int b){
    printf("Ingrese el número de renglores y columnas (mxn): \n");
    scanf("%d %d", &a, &b);
    printf("La direccion de la matriz es: %p\n", mat);
    printf ("La dirección del primer elemento de la matriz es: %p\n",&mat[0][0]);
    leer(mat,a,b);
    escribir(mat,a,b);
    return 0;
}
