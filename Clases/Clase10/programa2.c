#include <stdio.h>
#define TAM 100
void matriza(float array[][TAM],int nr, int nc){
    float *prt=&array[0][0];
    for(int i=0; i<nr*nc;i++){
        printf ("%p\n", (prt+i));
    }
}
int print_dir_array(float a[][TAM], float b[][TAM], float c[][TAM], int nr, int nc, int nc2){
    float *ptrA=&a[0][0], *ptrB=&b[0][0], *ptrC=&c[0][0];
    for(int i=0; i<nr;i++){
        for (int j=0;j<nc2;j++){
            for (int k=0; k<nc; k++){
                *(ptrC+i+j)=*(ptrC+i+j)+*(ptrA+i+k)* *(ptrB+k+j);
            }
        }
    }
    return 0;
     
}
void print_array(float array[][TAM], int nr, int nc){
    float *prt;
    prt=&array[0][0];
    printf ("[\n ");
    for (int i=0; i<nr*nc; i++){
        printf ("%f", *(prt+i));
        if((i+1)%nc==0) 
        printf("\n");
    }
    printf("]");
}
int main(){
    float matriz[TAM][TAM], matrizb[TAM][TAM];
    float *prt;
    int ca, fa,cb, fb;
    prt=&matriz[0][0];
    prt=&matrizb[0][0];
    printf ("Ingrese el numero de columnas de la matriz 1 y el numero de filas: \n");
    scanf ("%d %d", &ca,&fa);
    matriza(matriz,ca,fa);
    printf ("Ingrese el numero de la matriz 2 columnas y el numero de filas: \n");
    scanf ("%d %d", &cb,&fb);
    matriza(matriz,cb,fb);
    print_dir_array(matriz, matrizb,ca,fa,cb,fb);
    print_array(matriz,ca, fa);
return 0;

}