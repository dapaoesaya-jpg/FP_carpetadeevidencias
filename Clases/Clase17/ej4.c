#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL
#define WIDTH 800
#define HEIGHT 600
int posX, posY;
int speed=10;

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        // crea init y quit lo borra
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window *ventana = SDL_CreateWindow(
        "HOLA MUNDO",           // Titulo de la ventana
        SDL_WINDOWPOS_CENTERED, // X
        SDL_WINDOWPOS_CENTERED, // Y
        800,                    // ANCHO
        600,                    // ALTO
        0);
    bool running = true;
    SDL_Event event;
    SDL_RaiseWindow(ventana);
    SDL_Renderer *renderer=SDL_CreateRenederer(
        ventana,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    
    if (ventana == NULL)
    {
        printf("Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(ventana);
        SDL_Quit();
        return 1;
    }
    posX=(WIDTH/2)-25;
    posY=(HEIGHT/2)-25;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
                // event almace mas variables que estan dentro de de tyuoe
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_x:
                    /* code */
                    running =false;
                    break;
                case SDLK_UP:
                posY -=speed;
                break;
                case SDLK_DOWN:
                posY+=speed;
                break;
                case SDLK_LEFT:
                posX-=speed;
                break;
                case SDLK_RIGHT:
                posX+=speed;
                break;
                
                default:
                    break;
                }
                // tecla hacia abajo
                if (event.key.keysym.sym == SDLK_x)
                    running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
        SDL_Rect square={ posX, posY,50, 50};
        SDL_RenderFillRect(renderer, &square);
        SDL_RednderPresent(renderer);
        SDL_Delay(16);  
    }
    //SDL_RaiseWindow(ventana); // enviaventa al frente      // si ciclo te da el tiempo
    SDL_DestroyWindow(ventana);
    SDL_Quit();
}