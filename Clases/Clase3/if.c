#include<stdio.h>
#include<stdbool.h>
int main(){
    //verdadera
    if(true){
        printf("La condicion es verdadera \n");
    }else{
        printf("La condicion es falsa\n");
    }

    if(1){
        printf("La condicion es verdadera \n");
    }else{
        printf("La condicion es falsa \n");
    }

    if(!0){
        printf("La condicion es verdadera \n");
    }else{
        printf("La condicion es falsa \n");
    }

    if(-2){
        printf("La condicion es verdadera \n");
    }else{
        printf("La condicion es falsa \n");
    }
    
    //falsa
    if(false){
        printf("La condicion es falsa \n");
    }
    else{
        printf("La condicion es verdadera \n");
    }
    if(0){
        printf("La condicion es falsa \n");
    }
   
    if(!1){
        printf("La condicion es falsa \n");
    }

    return 0;
}