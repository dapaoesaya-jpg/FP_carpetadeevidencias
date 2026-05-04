#include<stdio.h>
#definir MAX 1000
int main(){
    int n;
    int array[MAX]
    int max=0;
    printf("Ingresar el número de datos:\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Ingresar los datos[]:\n");
        scanf("%d",&array[i]);
    }
    for(int i=0;i<n;i++){
        if(max<array[i])
        max=array[i];
    }
    printf("El valor maximo es %d\n",max);
    return 0;
}