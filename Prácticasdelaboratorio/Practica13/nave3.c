#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 40
#define HEIGHT 20

// Colores
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

// Variables de estado
int naveX, naveY;
int balaX, balaY;
bool balaActiva = false;
int enemigoX, enemigoY;
int score = 0;
bool game_over = false;
bool pausado = false; // <-- Nueva variable para la pausa

#ifndef _WIN32
struct termios oldt;
void enableRawMode() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
}
void disableRawMode() { tcsetattr(STDIN_FILENO, TCSANOW, &oldt); }
#endif

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
#endif
}

void setup() {
    naveX = WIDTH / 2;
    naveY = HEIGHT - 4;
    enemigoX = (rand() % (WIDTH - 2)) + 1;
    enemigoY = 1;
}

void draw() {
    clearScreen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Bordes
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf(YELLOW "▒");
            } 
            // Si está pausado, podemos mostrar un mensaje en el centro
            else if (pausado && i == HEIGHT / 2 && j == (WIDTH / 2) - 4) {
                printf(BLUE " PAUSA ");
                j += 6;
            }
            // Nave (Solo si no estamos sobre el mensaje de pausa)
            else if (i == naveY && j == naveX) {
                printf(GREEN "#");
            }
            else if (i == naveY + 1 && (j == naveX - 1 || j == naveX + 1)) {
                printf(GREEN "#");
            }
            // Bala
            else if (balaActiva && i == balaY && j == balaX) {
                printf(RED "^");
            }
            // Enemigo
            else if (i == enemigoY && j == enemigoX) {
                printf(BLUE "V");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf(RESET "Score: %d | [P] Pausa | [W] Disparar | [A-D] Mover\n", score);
}

void logic() {
    // Si está pausado, salimos de la función sin mover nada
    if (pausado) return;

    if (balaActiva) {
        balaY--;
        if (balaY <= 0) balaActiva = false;
    }

    if (balaActiva && (balaY == enemigoY) && balaX == enemigoX) {
        score += 10;
        balaActiva = false;
        enemigoY = 1;
        enemigoX = (rand() % (WIDTH - 2)) + 1;
    }

    static int frame = 0;
    if (frame++ % 3 == 0) enemigoY++;

    if (enemigoY >= HEIGHT - 1) game_over = true;

    if (enemigoY == naveY && enemigoX == naveX) game_over = true;
    if (enemigoY == naveY + 1 && (enemigoX == naveX - 1 || enemigoX == naveX + 1)) game_over = true;
}

int main() {
    setup();
#ifndef _WIN32
    enableRawMode();
#endif

    while (!game_over) {
        draw();
        
        char input;
#ifdef _WIN32
        input = _kbhit() ? _getch() : 0;
#else
        if (read(STDIN_FILENO, &input, 1) <= 0) input = 0;
#endif

        // Tecla de Pausa
        if (input == 'p' || input == 'P') {
            pausado = !pausado; // Cambia entre verdadero y falso
        }

        // Solo permitir movimiento y disparo si NO está pausado
        if (!pausado) {
            if ((input == 'a' || input == 'A') && naveX > 2) naveX--;
            if ((input == 'd' || input == 'D') && naveX < WIDTH - 3) naveX++;
            if ((input == 'w' || input == 'W') && !balaActiva) {
                balaActiva = true;
                balaX = naveX;
                balaY = naveY - 1;
            }
        }

        if (input == 'q') game_over = true;

        logic();

#ifdef _WIN32
        Sleep(50);
#else
        usleep(50000);
#endif
    }

    printf(RESET "\n--- JUEGO TERMINADO --- Score: %d\n", score);
#ifndef _WIN32
    disableRawMode();
#endif
    return 0;
}