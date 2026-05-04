#include<stdio.h>
#include<stdbool.h>
int main(){
    int res;
    char h,p,H;
    //IGUAL A
    res='h'=='p';
    printf ("%d",&res);
    res='h'=='H';
    printf ("%d",&res);
    res='h'=='h';
    printf ("%d",&res);
    //DIFERENTE A
    res='h'!='p';
    printf ("%d",&res);
    //MENOR QUE
    res=7<15;
    printf ("%d",&res);
    //MAYOR QUE
    res=22>11;
    printf ("%d",&res);
    //MENOR O IGUAL QUE
    res=15<=2;
    printf ("%d",&res);
    //MAYOR O IGUAL QUE
    res=30>=100;
    printf ("%d",&res);
    return 0;
}