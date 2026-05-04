#include <stdio.h>
int main(){
    int i,j,n,k,x;
    printf("Digite un numero\n");
    scanf ("%d", &n);
     for(i=n;i>=1;i--){
        for(j=1;j<=i;j++){
            for(k=j;k<=n;k++){
                printf ("%d", k);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}