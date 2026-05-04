#include<stdio.h>
void main(){
    int num;
    scanf("%d",&num);
    for(;num>=0;){
        printf("%d\n", num);
        scanf("%d",&num);
    }
}