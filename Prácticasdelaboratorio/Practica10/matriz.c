#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
int leer(int A[][MAX], int fa, int ca)
{
    printf("Ingresar el número de rengloes y columnas:\n");
    scanf("%d %d", &fa, &ca);
    for (int i = 0; i < fa; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            printf("Ingresar el valor para matriz [%d,%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    return 0;
}

int suma(int A[][MAX], int B[][MAX], int C[][MAX], int fb, int cb)
{
    for (int i = 0; i < fb; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return 0;
}
int mul(int A[][MAX], int B[][MAX], int C[][MAX], int fb, int cb, int v)
{
    for (int i = 0; i < fb; i++)
    {
        for (int j = 0; j < cb; j++)
        {
            for (int k = 0; k < v; k++)
            {
                printf("Ingresar el valor para matriz: ");
                scanf("%d", &C[i][j]);
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return 0;
}
void trans(int A[][MAX], int fa, int ca)
{
    for (int i = 0; i < fa; i++)
    {
        for (int j = 0; j < ca; j++)
        {
            scanf("%d", &A[j][i]);
        }
    }
}
int deter(int A[][MAX], int fa, int ca)
{
    float v, n;
    int m = 1;
    float det = 1;
    for (int i = 0; i < fa; i++)
    {
        for (int j = i + 1; j < ca; j++)
        {
            v = A[j][i];
            n = v / v;
            for (int k = 0; k < fa; k++)
            {
                A[j][k] = A[j][k] - n * A[i][k];
            }
        }
    }
    for (int i = 0; i < fa; i++)
    {
        det *= A[i][i];
    }
    return det;
}
int mostrar(int A[][MAX], int fa, int ca)
{
    for (int i = 0; i < fa; i++)
    {
        printf("[ ");

        for (int j = 0; j < ca; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("]\n");
    }
    return 0;
}

void menu()
{
    printf("Seleccionar opcion:\n");
    printf("1. Suma\n");
    printf("2. Multiplicación:\n");
    printf("3. Transpuesta:\n");
    printf("4. Determinante:\n");
    printf("5. Salir:\n");
}
int main()
{
    int matriza[MAX][MAX], matrizb[MAX][MAX], matriz[MAX][MAX];
    int fb, cb, fa, ca, fc, cc,v;
    float a, b, c;
    int op;
    while (true)
    {
        menu();
        printf("Selecciona una opción \n");
        scanf("%d", &op);
        if (op == 5)
            return 0;
        switch (op)
        {
        case 1:
            leer(matriza, fa, ca);
            leer(matrizb, fb, cb);
            if (fa == fb && ca == cb)
            {
                suma(matriza, matriz, matriz, fa, ca);
            }
            else
            {
                printf("la matriz no se puede sumar\n");
            }
            mostrar(matriz, fc,cc);
            break;
        case 2:
            leer(matriza, fb, cb);
            leer(matrizb, fa, ca);
            if (fa == cb)
            {
                mul(matriza, matrizb, matriz, fa, ca, v);
            }
            else
            {
                printf("la matriz no se puede multiplicacar\n");
            }
            mostrar(matriz, fc,cc);
            break;
        case 3:
            leer(matriz, fa,ca);
            trans(matriz, fa, ca);
            mostrar(matriz, fc,cc);
            break;
        case 4:
            leer(matriza, fa, ca);
            if (fa == ca)
            {
                deter(matriza, fa, ca);
            }
            else
            {
                printf("No tiene determinate\n");
            }
            break;
        default:
        }
    }
}