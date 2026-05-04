#include<stdio.h>
#include<string.h>
void main(){
    char s1[]="Hola";
    char s2[]="hola";
    do{
        printf("Ingresa la contraseña correcta\n");
        scanf("%s",s2);
    }while(strcmp(s1,s2)!=0);
    printf("La contraseña es correcta\n");
}