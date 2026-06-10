// Clase 27_04_26

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 30


/*
Variables globales: Existen para todas las funciones, se declaran fuera de la 
función, cualquier cambio en el código se refleja para todo el programa.
*/

int x, y; // Posición de la primera parte de la vibora 
int fruitX, fruitY; // Posición de la fruta
int score;
char input; // Tecla en el Teclado 

//Función que sirve para iniciar el juego

void setup(){
    //Fijando la posicion inicial en el "centro"
    x=WIDTH/2;
    y=HEIGHT/2;

    //"rand" genera un número pseudoaleatorio limitado al ancho y alto
    fruitX = rand()%WIDTH;
    fruitY = rand()%HEIGHT;

    score = 0;
}

void draw(){
    //"System" Sirve para ejecutar comandos de la terminal
    system("clear");
    for(int i=0; i<WIDTH; i++){
        for(int j=0; j<HEIGHT; j++){
            if(j==0 || i==0 || j==WIDTH-1 || i==HEIGHT-1){
                printf("#");
                continue;
            }
            if(x==j && y==i){
                printf("s");
                continue;
            }
            if(fruitX==j && fruitY==i){
                printf("f");
                continue;
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
    printf("Presiona W,S,D o A\n");
}

void inputFunc(){
    //Lee un caracter de la entrada
    input = getchar();
    getchar();
}

int main(){
    setup();
    while(true){
        draw();
        inputFunc();
    }
    return 0;
}