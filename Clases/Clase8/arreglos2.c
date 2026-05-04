#include<stdio.h>
int main(){
    int array[5];
    int *ptr;
    ptr=array;
    printf("%p\n", &array[0]);
    printf ("%p\n", ptr);
    for (int i=0; i<5;i++){
        *(ptr+i)=i+1;
    }
    for (int i=0; i<5;i++){
        printf("%d\n",*(ptr+i));
    }
    return 0;
}// 0 1 2 3 4 5 6 7 8 9 A B C D E F
//una funcion un fragmento de codigo que realiza una terea en especifico