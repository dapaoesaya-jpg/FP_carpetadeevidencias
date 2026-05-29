#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

// Colores para la terminal
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

// Variables globales de juego
int naveX, naveY;
int balaX, balaY;
bool balaActiva = false;
int enemigoX, enemigoY, dirEnemigoX = 1;

// Variables para el Bonus
int bonusX, bonusY;
bool bonusActivo = false;

int score = 0;
bool game_over = false;
bool pausado = false;
int contadorCiclos = 0;

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
    srand(time(NULL));
    naveX = WIDTH / 2;
    naveY = HEIGHT - 4;
    enemigoX = (rand() % (WIDTH - 4)) + 2;
    enemigoY = 1;
    bonusActivo = false;
}

void draw() {
    clearScreen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // 1. Bordes
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                printf(YELLOW "▒");
            } 
            // 2. Pantalla de Pausa
            else if (pausado && i == HEIGHT / 2 && j == (WIDTH / 2) - 4) {
                printf(CYAN " PAUSA ");
                j += 6;
            }
            // 3. La Nave (Estructura de 3 piezas: principal y alas)
            else if (i == naveY && j == naveX) {
                printf(GREEN "#"); // Cabina
            }
            else if (i == naveY + 1 && (j == naveX - 1 || j == naveX + 1)) {
                printf(GREEN "#"); // Alas
            }
            // 4. Proyectil
            else if (balaActiva && i == balaY && j == balaX) {
                printf(RED "^");
            }
            // 5. Asteroide
            else if (i == enemigoY && j == enemigoX) {
                printf(BLUE "O");
            }
            // 6. El BONUS ($)
            else if (bonusActivo && i == bonusY && j == bonusX) {
                printf(YELLOW "$");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf(RESET "Puntos: %d | [P] Pausa | [W] Disparar | [A-D] Mover\n", score);
}

void logic() {
    if (pausado) return;

    // Movimiento de la bala
    if (balaActiva) {
        balaY--;
        if (balaY <= 0) balaActiva = false;
    }

    // Rebote lateral del asteroide
    enemigoX += dirEnemigoX;
    if (enemigoX >= WIDTH - 2 || enemigoX <= 1) {
        dirEnemigoX *= -1; 
    }

    // Caída del asteroide cada 2 segundos (40 ciclos de 50ms)
    contadorCiclos++;
    if (contadorCiclos >= 40) {
        enemigoY++;
        contadorCiclos = 0;
    }

    // Movimiento del Bonus (cae verticalmente si está activo)
    if (bonusActivo) {
        static int velBonus = 0;
        if (velBonus++ % 2 == 0) bonusY++; // Cae un poco más lento
        if (bonusY >= HEIGHT - 1) bonusActivo = false;
    }

    // --- DETECCIÓN DE COLISIONES ---

    // 1. Bala destruye Asteroide
    if (balaActiva && (balaY == enemigoY) && (balaX == enemigoX)) {
        score += 10;
        balaActiva = false;
        
        // Al destruir, 40% de probabilidad de soltar BONUS
        if (rand() % 10 < 4) {
            bonusActivo = true;
            bonusX = enemigoX;
            bonusY = enemigoY;
        }
        
        enemigoY = 1; // Reaparece arriba
        enemigoX = (rand() % (WIDTH - 4)) + 2;
    }

    // 2. Nave recolecta BONUS (Puntos extras)
    if (bonusActivo) {
        bool tocaCabina = (bonusY == naveY && bonusX == naveX);
        bool tocaAlas = (bonusY == naveY + 1 && (bonusX == naveX - 1 || bonusX == naveX + 1));
        
        if (tocaCabina || tocaAlas) {
            score += 50; // ¡BONUS EXTRA!
            bonusActivo = false;
        }
    }

    // 3. Condiciones de derrota (Game Over)
    if (enemigoY >= HEIGHT - 1) game_over = true; // El asteroide llegó a la base
    if (enemigoY == naveY && enemigoX == naveX) game_over = true; // Chocó con cabina
    if (enemigoY == naveY + 1 && (enemigoX == naveX - 1 || enemigoX == naveX + 1)) game_over = true; // Chocó con alas
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

        if (input == 'p' || input == 'P') pausado = !pausado;
        if (input == 'q' || input == 'Q') break;

        if (!pausado) {
            if ((input == 'a' || input == 'A') && naveX > 2) naveX--;
            if ((input == 'd' || input == 'D') && naveX < WIDTH - 3) naveX++;
            if ((input == 'w' || input == 'W') && !balaActiva) {
                balaActiva = true;
                balaX = naveX;
                balaY = naveY - 1;
            }
        }

        logic();

#ifdef _WIN32
        Sleep(50);
#else
        usleep(50000); 
#endif
    }

    clearScreen();
    printf(YELLOW "\n   ==============================\n");
    printf(RED    "      FIN DEL JUEGO (GAME OVER)\n");
    printf(RESET  "      Puntuacion Alcanzada: %d\n", score);
    printf(YELLOW "   ==============================\n\n" RESET);

#ifndef _WIN32
    disableRawMode();
#endif
    return 0;
}