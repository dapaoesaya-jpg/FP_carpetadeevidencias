#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 40
#define HEIGHT 20

// Colores para la terminal
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

int naveX, naveY;
int balaX, balaY;
bool balaActiva = false;
int enemigoX, enemigoY;
int score = 0;
bool game_over = false;

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
    naveY = HEIGHT - 4; // Un poco más arriba para que quepan las alas abajo
    enemigoX = (rand() % (WIDTH - 2)) + 1;
    enemigoY = 1;
}

void draw() {
    clearScreen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // 1. Bordes
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf(YELLOW "▒");
            } 
            // 2. PARTE PRINCIPAL (Un renglón antes)
            else if (i == naveY && j == naveX) {
                printf(GREEN "#");
            }
            // 3. LAS ALAS (Un renglón después, a los lados)
            else if (i == naveY + 1 && (j == naveX - 1 || j == naveX + 1)) {
                printf(GREEN "#");
            }
            // 4. Bala
            else if (balaActiva && i == balaY && j == balaX) {
                printf(RED "^");
            }
            // 5. Enemigo
            else if (i == enemigoY && j == enemigoX) {
                printf(RED "V");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf(RESET "Score: %d | A-D: Mover | W: Disparar\n", score);
}

void logic() {
    if (balaActiva) {
        balaY--;
        if (balaY <= 0) balaActiva = false;
    }

    // Colisión con enemigo
    if (balaActiva && (balaY == enemigoY || balaY == enemigoY - 1) && balaX == enemigoX) {
        score += 10;
        balaActiva = false;
        enemigoY = 1;
        enemigoX = (rand() % (WIDTH - 2)) + 1;
    }

    // Movimiento enemigo
    static int frame = 0;
    if (frame++ % 3 == 0) enemigoY++;

    if (enemigoY >= HEIGHT - 1) game_over = true;

    // Colisión enemigo con cualquier parte de la nave
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

        if ((input == 'a' || input == 'A') && naveX > 2) naveX--;
        if ((input == 'd' || input == 'D') && naveX < WIDTH - 3) naveX++;
        if ((input == 'w' || input == 'W') && !balaActiva) {
            balaActiva = true;
            balaX = naveX;
            balaY = naveY - 1;
        }

        logic();
#ifdef _WIN32
        Sleep(50);
#else
        usleep(60000);
#endif
    }

    printf(RESET "\n--- GAME OVER --- Puntos: %d\n", score);
#ifndef _WIN32
    disableRawMode();
#endif
    return 0;
}