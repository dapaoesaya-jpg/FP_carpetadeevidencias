#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

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
                // tecla hacia abajo
                if (event.key.keysym.sym == SDLK_x)
                    running = false;
            }
        }
    }
    if (ventana == NULL)
    {
        printf("Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_RaiseWindow(ventana); // enviaventa al frente
    SDL_Delay(300000);        // si ciclo te da el tiempo
    SDL_DestroyWindow(ventana);
    SDL_Quit();
}