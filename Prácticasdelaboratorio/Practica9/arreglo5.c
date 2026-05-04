#include<stdio.h>
/*
Este programa permite trabjar con 
un arreglo a tràves de un apuntador
*/
int main(){
    int array[10];
    int *apuntador;
    apuntador=&array[7]; /*asigninado la direccion del primer leemento del arrayal apuntador*/
    //apuntador =&array[0]
    for (int i=0;i<7;i++){
        printf("Ingresa el valor del elemento  %d\n", i);
        //scanf ("%d", &array[i]);
        scanf ("%d", (apuntador+i));
    }
    printf ("[ ");
      for (int i=0;i<7;i++){
        printf("%d ,", *(apuntador+i));
    }
    printf ("]\n");
    return 0;
}