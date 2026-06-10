/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Interpolacao polinomial de Lagrange
 * Disciplina: Matematica Computacional
 *
 * Dados os pontos (0, 1), (1, 3), (2, 0), (3, 4), calcula o valor
 * do polinomio interpolador em um ponto x qualquer.
 */

#include <stdio.h>

#define N 4

/*
 * Calcula o polinomio interpolador de Lagrange no ponto x.
 * x_vals: vetor com as coordenadas x dos pontos conhecidos
 * y_vals: vetor com as coordenadas y dos pontos conhecidos
 * n     : numero de pontos
 * x     : ponto onde avaliar o polinomio
 * Retorna P(x).
 */
double lagrange(double x_vals[], double y_vals[], int n, double x)
{
    int i, j;
    double resultado = 0.0;
    double L, num, den;

    for (i = 0; i < n; i++)
    {
        L = 1.0;
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                num = x - x_vals[j];
                den = x_vals[i] - x_vals[j];
                L = L * (num / den);
            }
        }
        resultado = resultado + y_vals[i] * L;
    }

    return resultado;
}

int main(void)
{
    double x_vals[N] = {0.0, 1.0, 2.0, 3.0};
    double y_vals[N] = {1.0, 3.0, 0.0, 4.0};
    double x, y;
    int i;

    printf("=== Interpolacao de Lagrange ===\n");
    printf("Pontos conhecidos:\n");
    for (i = 0; i < N; i++)
    {
        printf("  (%.1f, %.1f)\n", x_vals[i], y_vals[i]);
    }

    printf("\nDigite o valor de x para interpolar: ");
    scanf("%lf", &x);

    y = lagrange(x_vals, y_vals, N, x);

    printf("P(%.4f) = %.10f\n", x, y);

    return 0;
}
