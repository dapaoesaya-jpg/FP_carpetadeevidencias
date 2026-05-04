#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define WDTH 20
#define HEIGHT 10
int x,y;
int fruitX, fruitY;
int score;
char imput;
/*
*Funcion que sirve para iniciar el juego
*/
void setup(){
    x=WDTH/2;
    y=HEIGHT/2;// Fijando la posiocion incial del juagdor 
    fruitX=rand()%WDTH;
    // rand genera un seudo numero alateorio
    fruitY=rand()%HEIGHT;
    score 0;
}
void draw(){
    system ("clear");
    for(int i=0; i<WDTH; i++){
        for (int j=0; j<HEIGHT; j++){
            if(j==0|| i==0||j==WDTH-1||i==HEIGHT-1) {
                printf("#");
                continue;
            }
            if(x==j&& y==i){
                printf ("S");
                continue;
            }
            if(x==j && y==i){
                printf("S");
            }
            if(fruitX==j&&fruitY){
                printf("f");
            }
            printf(" ");
        }
        printf("\n");
    }
    printf ("Score: %d\n", score);
    printf ("Presiona W o S o D o A\n");
}// lafuncion system ejectuara comandos de la terminal 
void imputFunc(){

}
int main(){
    setup();
    while (true){
        draw();
        imputFunc();
    }
}