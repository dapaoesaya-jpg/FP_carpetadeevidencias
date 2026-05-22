#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MITAD_PANTALLA 10

// Colores
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

typedef struct {
    int x, y;
    int dirX;
    bool activo;
} Entidad;

Entidad asteroide, naveEnemiga, estrella, balaEnemiga;
int naveX, naveY, balaX, balaY;
bool balaJugadorActiva = false;
int score = 0, nivel = 1;
bool game_over = false, pausado = false;
int velocidad = 100000; 

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

void clearScreen() { printf("\033[H\033[J"); }

void setup() {
    srand(time(NULL));
    naveX = WIDTH / 2;
    naveY = HEIGHT - 4;
    asteroide.activo = true; 
    asteroide.x = rand() % (WIDTH - 4) + 2;
    asteroide.y = 1;
    asteroide.dirX = (rand() % 2 == 0 ? 1 : -1);
    
    naveEnemiga.activo = false; 
    estrella.activo = false;
}

void draw() {
    clearScreen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) printf(YELLOW "▒");
            else if (pausado && i == HEIGHT / 2 && j == WIDTH / 2 - 3) { printf(CYAN "PAUSA"); j += 4; }
            else if (i == naveY && j == naveX) printf(GREEN "#"); 
            else if (i == naveY + 1 && (j == naveX - 1 || j == naveX + 1)) printf(GREEN "#"); 
            else if (balaJugadorActiva && i == balaY && j == balaX) printf(CYAN "^");
            else if (balaEnemiga.activo && i == balaEnemiga.y && j == balaEnemiga.x) printf(RED "v");
            else if (asteroide.activo && i == asteroide.y && j == asteroide.x) printf(BLUE "O");
            else if (naveEnemiga.activo && i == naveEnemiga.y && j == naveEnemiga.x) printf(RED "W");
            else if (estrella.activo && i == estrella.y && j == estrella.x) printf(YELLOW "*");
            else printf(" ");
        }
        printf("\n");
    }
    printf(RESET "Score: %d | Nivel: %d | [P] Pausa | [W] Disparar\n", score, nivel);
}

void logic() {
    if (pausado) return;
    static int frame = 0; frame++;

    // 1. Spawn de Estrellas (Aparecen con baja probabilidad)
    if (!estrella.activo && rand() % 150 == 0) {
        estrella = (Entidad){rand() % (WIDTH - 4) + 2, 1, 0, true};
    }

    // 2. Spawn de Naves Enemigas (Cada 80 frames si no hay una)
    if (!naveEnemiga.activo && frame % 80 == 0) {
        naveEnemiga = (Entidad){rand() % (WIDTH - 4) + 2, 1, (rand() % 2 == 0 ? 1 : -1), true};
    }

    // 3. Movimiento Bala Jugador
    if (balaJugadorActiva) {
        balaY--;
        if (balaY <= 0) balaJugadorActiva = false;
    }

    // 4. Movimiento Asteroide (REGLA: Si toca suelo, GAME OVER)
    if (asteroide.activo) {
        asteroide.x += asteroide.dirX;
        if (asteroide.x >= WIDTH - 2 || asteroide.x <= 1) asteroide.dirX *= -1;
        if (frame % 3 == 0) asteroide.y++;
        
        if (asteroide.y >= HEIGHT - 1) game_over = true; // Perder por no destruir el asteroide
    } else {
        // Regenerar asteroide si fue destruido
        asteroide = (Entidad){rand() % (WIDTH - 4) + 2, 1, (rand() % 2 == 0 ? 1 : -1), true};
    }

    // 5. Nave Enemiga (Se queda a mitad de pantalla)
    if (naveEnemiga.activo) {
        naveEnemiga.x += naveEnemiga.dirX;
        if (naveEnemiga.x >= WIDTH - 2 || naveEnemiga.x <= 1) naveEnemiga.dirX *= -1;
        if (frame % 5 == 0 && naveEnemiga.y < MITAD_PANTALLA) naveEnemiga.y++;
        
        if (!balaEnemiga.activo && rand() % 20 == 0) {
            balaEnemiga = (Entidad){naveEnemiga.x, naveEnemiga.y + 1, (rand() % 2 == 0 ? 1 : -1), true};
        }
    }

    // 6. Bala Enemiga (Rebota y baja)
    if (balaEnemiga.activo) {
        balaEnemiga.x += balaEnemiga.dirX;
        if (balaEnemiga.x >= WIDTH - 2 || balaEnemiga.x <= 1) balaEnemiga.dirX *= -1;
        if (frame % 2 == 0) balaEnemiga.y++;
        if (balaEnemiga.y >= HEIGHT - 1) balaEnemiga.activo = false;
    }

    // 7. Movimiento Estrella
    if (estrella.activo) {
        if (frame % 2 == 0) estrella.y++;
        if (estrella.y >= HEIGHT - 1) estrella.activo = false;
    }

    // --- COLISIONES ---
    
    // Disparos del jugador
    if (balaJugadorActiva) {
        if (naveEnemiga.activo && balaX == naveEnemiga.x && balaY == naveEnemiga.y) {
            score += 50; naveEnemiga.activo = false; balaJugadorActiva = false;
            nivel++;
            if (velocidad > 30000) velocidad -= 4000;
        }
        if (asteroide.activo && balaX == asteroide.x && balaY == asteroide.y) {
            score += 10; asteroide.activo = false; balaJugadorActiva = false;
        }
    }

    // Colisiones del jugador con objetos
    int hitboxNave = ((asteroide.y == naveY && asteroide.x == naveX) || (asteroide.y == naveY + 1 && abs(asteroide.x - naveX) <= 1));
    if (hitboxNave) game_over = true; // REGLA: Tocar asteroide = Perder

    if (naveEnemiga.activo && ((naveEnemiga.y == naveY && naveEnemiga.x == naveX) || (naveEnemiga.y == naveY + 1 && abs(naveEnemiga.x - naveX) <= 1))) game_over = true;
    if (balaEnemiga.activo && ((balaEnemiga.y == naveY && balaEnemiga.x == naveX) || (balaEnemiga.y == naveY + 1 && abs(balaEnemiga.x - naveX) <= 1))) game_over = true;

    // Bonus de Estrella
    if (estrella.activo && ((estrella.y == naveY && estrella.x == naveX) || (estrella.y == naveY + 1 && abs(estrella.x - naveX) <= 1))) {
        score += 150; estrella.activo = false;
    }
}

int main() {
#ifndef _WIN32
    enableRawMode();
#endif
    setup();
    while (!game_over) {
        draw();
        char input = 0;
#ifdef _WIN32
        if (_kbhit()) input = _getch();
#else
        read(STDIN_FILENO, &input, 1);
#endif
        if (input == 'p' || input == 'P') pausado = !pausado;
        if (!pausado) {
            if ((input == 'a' || input == 'A') && naveX > 2) naveX--;
            if ((input == 'd' || input == 'D') && naveX < WIDTH - 3) naveX++;
            if ((input == 'w' || input == 'W') && !balaJugadorActiva) {
                balaJugadorActiva = true; balaX = naveX; balaY = naveY - 1;
            }
        }
        logic();
#ifdef _WIN32
        Sleep(velocidad / 1000);
#else
        usleep(velocidad);
#endif
    }
    draw();
    printf(RED "\n¡GAME OVER!\n" RESET);
    printf("Motivo: Impacto o el asteroide superó tu defensa.\n");
    printf("Puntaje Final: %d\n", score);
#ifndef _WIN32
    disableRawMode();
#endif
    return 0;
}