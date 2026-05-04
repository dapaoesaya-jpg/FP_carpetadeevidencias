#include<stdio.h>
int main(){
    int array[5];
    int *ptr;
    for (int i=0; i<5;i++){
        array[i]=i+1;
    }
    for (int i=0; i<5;i++){
        printf("%d\n",array[i]);
    }
    return 0;
}