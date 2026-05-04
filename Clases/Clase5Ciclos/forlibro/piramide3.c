#include <stdio.h>

int main() {
    int i, j, k,pn;

    printf("Digite un numero: \n");
    scanf("%d", &n);
    for(int  i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf(" %d",j);
        }
        for(k= 0; k<= (n - i) * 2; k++) {
            printf(" ");
        }

        for(int j=i;j>=1;j--){
            printf(" %d",j);
        } printf("\n");

    }
    return 0;
}