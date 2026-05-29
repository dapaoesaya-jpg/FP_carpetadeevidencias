#include <SDL2/SDL.h>
#include <stdio.h>

int main (int argc, char **argv){
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        printf ("Error %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window *window=SDL_CreaWindow(
        "Hola mundo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        0
    );
    if (window){
        printf("Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Delay(5000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}