#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

void leer(int A[][MAX], int *fa, int *ca)
{
    printf("Ingresar el número de renglones y columnas:\n");
    scanf("%d %d", fa, ca);

    for (int i = 0; i < *fa; i++)
    {
        for (int j = 0; j < *ca; j++)
        {
            printf("Ingresar el valor para matriz [%d,%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void suma(int A[][MAX], int B[][MAX], int C[][MAX], int f, int c)
{
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void mul(int A[][MAX], int B[][MAX], int C[][MAX], int f, int c, int v)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            C[i][j] = 0; // 🔑 importante
            for (int k = 0; k < v; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void trans(int A[][MAX], int B[][MAX], int f, int c)
{
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            B[j][i] = A[i][j];
}

int deter(int A[][MAX], int n)
{
    int det = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][i] == 0) return 0;

            float factor = (float)A[j][i] / A[i][i];

            for (int k = 0; k < n; k++)
                A[j][k] -= factor * A[i][k];
        }
    }

    for (int i = 0; i < n; i++)
        det *= A[i][i];

    return det;
}

void mostrar(int A[][MAX], int f, int c)
{
    for (int i = 0; i < f; i++)
    {
        printf("[ ");
        for (int j = 0; j < c; j++)
            printf("%d ", A[i][j]);
        printf("]\n");
    }
}

void menu()
{
    printf("Seleccionar opcion:\n");
    printf("1. Suma\n");
    printf("2. Multiplicación\n");
    printf("3. Transpuesta\n");
    printf("4. Determinante\n");
    printf("5. Salir\n");
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int fa, ca, fb, cb;
    int op;

    while (true)
    {
        menu();
        scanf("%d", &op);

        if (op == 5) break;

        switch (op)
        {
        case 1:
            leer(A, &fa, &ca);
            leer(B, &fb, &cb);

            if (fa == fb && ca == cb)
            {
                suma(A, B, C, fa, ca);
                mostrar(C, fa, ca);
            }
            else
                printf("No se pueden sumar\n");
            break;

        case 2:
            leer(A, &fa, &ca);
            leer(B, &fb, &cb);

            if (ca == fb)
            {
                mul(A, B, C, fa, cb, ca);
                mostrar(C, fa, cb);
            }
            else
                printf("No se pueden multiplicar\n");
            break;

        case 3:
            leer(A, &fa, &ca);
            trans(A, C, fa, ca);
            mostrar(C, ca, fa);
            break;

        case 4:
            leer(A, &fa, &ca);
            if (fa == ca)
                printf("Determinante: %d\n", deter(A, fa));
            else
                printf("No tiene determinante\n");
            break;
        }
    }
}