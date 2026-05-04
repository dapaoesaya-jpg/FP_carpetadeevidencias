#include<stdio.h>
int main (){
    int n,i,j;
    printf ("Digite un numero: \n");
    scanf("%d", &n);
     for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    for(int  i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}