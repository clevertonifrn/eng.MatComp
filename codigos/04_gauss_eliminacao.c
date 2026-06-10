/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Eliminacao de Gauss para resolucao de sistemas lineares
 * Disciplina: Matematica Computacional
 *
 * Resolve o sistema 3x3:
 *   2x +  y -  z =  8
 *  -3x -  y + 2z = -11
 *  -2x +  y + 2z = -3
 *
 * Metodo: eliminacao direta ( triangularizacao ) + retrossubstituicao.
 */

#include <stdio.h>
#include <math.h>

#define N 3

/*
 * Imprime a matriz aumentada do sistema.
 * n: ordem do sistema
 * a: matriz aumentada n x (n+1)
 */
void imprimir_sistema(int n, double a[N][N + 1])
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%10.4f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Eliminacao de Gauss com pivoteamento parcial.
 * a: matriz aumentada n x (n+1) - sera modificada
 * n: ordem do sistema
 */
void eliminacao_gauss(int n, double a[N][N + 1])
{
    int i, j, k, linha_pivo;
    double fator, pivo, temp;

    for (k = 0; k < n - 1; k++)
    {
        /* Pivoteamento parcial */
        pivo = fabs(a[k][k]);
        linha_pivo = k;
        for (i = k + 1; i < n; i++)
        {
            if (fabs(a[i][k]) > pivo)
            {
                pivo = fabs(a[i][k]);
                linha_pivo = i;
            }
        }
        if (linha_pivo != k)
        {
            for (j = k; j <= n; j++)
            {
                temp = a[k][j];
                a[k][j] = a[linha_pivo][j];
                a[linha_pivo][j] = temp;
            }
        }

        /* Eliminacao */
        for (i = k + 1; i < n; i++)
        {
            fator = a[i][k] / a[k][k];
            for (j = k; j <= n; j++)
            {
                a[i][j] = a[i][j] - fator * a[k][j];
            }
        }
    }
}

/*
 * Retrossubstituicao para encontrar a solucao.
 * a: matriz triangular superior n x (n+1)
 * x: vetor com a solucao (saida)
 * n: ordem do sistema
 */
void retrossubstituicao(int n, double a[N][N + 1], double x[N])
{
    int i, j;
    double soma;

    for (i = n - 1; i >= 0; i--)
    {
        soma = a[i][n];
        for (j = i + 1; j < n; j++)
        {
            soma = soma - a[i][j] * x[j];
        }
        x[i] = soma / a[i][i];
    }
}

int main(void)
{
    /* Matriz aumentada: coluna n contem os termos independentes */
    double a[N][N + 1] = {
        { 2.0,  1.0, -1.0,  8.0},
        {-3.0, -1.0,  2.0, -11.0},
        {-2.0,  1.0,  2.0, -3.0}
    };
    double x[N];
    int i;

    printf("=== Eliminacao de Gauss ===\n");
    printf("Sistema original:\n");
    imprimir_sistema(N, a);

    eliminacao_gauss(N, a);

    printf("Matriz triangularizada:\n");
    imprimir_sistema(N, a);

    retrossubstituicao(N, a, x);

    printf("Solucao:\n");
    for (i = 0; i < N; i++)
    {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    return 0;
}
