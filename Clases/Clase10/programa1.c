#include <stdio.h>
#define TAM 100
void print_dir_array(float array[][TAM],int nr, int nc){
    float *prt=&array[0][0];
    for(int i=0; i<nr*nc;i++){
        printf ("%p\n", (prt+i));
    }
}
void print_array(float array[][TAM], int nr, int nc){
    float *prt=&array[0][0];
    printf  ("[ \n");
    for (int i=0; i<nr*nc; i++){
        printf ("%.2f  ", *(prt+i));
        if((i+1)%nc==0) 
        printf("   \n");
    }
    printf(" ]");
}
int main(){
    float matriz[][TAM]={1.0f, 0.0f , 0.0f , 0.0f , 1.0f , 0.0f , 0.0f , 0.0f , 1.0f };
    float *prt;
    prt=&matriz[0][0];
print_array(matriz,3,3);
return 0;

}