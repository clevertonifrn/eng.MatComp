/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Metodo iterativo de Gauss-Jacobi
 * Disciplina: Matematica Computacional
 *
 * Resolve o sistema:
 *   10x +   y +   z = 12
 *     x + 10y +   z = 12
 *     x +   y + 10z = 12
 *
 * O metodo iterativo parte de uma aproximacao inicial e atualiza
 * cada variavel usando os valores da iteracao anterior.
 */

#include <stdio.h>
#include <math.h>

#define N 3
#define MAX_ITER 100
#define TOL 1e-6

/*
 * Metodo de Gauss-Jacobi.
 * a    : matriz dos coeficientes n x n
 * b    : vetor de termos independentes
 * x    : vetor com o chute inicial e que contera a solucao
 * n    : ordem do sistema
 * Retorna o numero de iteracoes executadas.
 */
int gauss_jacobi(double a[N][N], double b[N], double x[N], int n)
{
    double x_antigo[N];
    int iter, i, j;
    double soma, erro, max_erro;

    for (iter = 0; iter < MAX_ITER; iter++)
    {
        /* Salva valores da iteracao anterior */
        for (i = 0; i < n; i++)
            x_antigo[i] = x[i];

        /* Atualiza cada variavel */
        for (i = 0; i < n; i++)
        {
            soma = b[i];
            for (j = 0; j < n; j++)
            {
                if (j != i)
                    soma = soma - a[i][j] * x_antigo[j];
            }
            x[i] = soma / a[i][i];
        }

        /* Calcula o erro maximo */
        max_erro = 0.0;
        for (i = 0; i < n; i++)
        {
            erro = fabs(x[i] - x_antigo[i]);
            if (erro > max_erro)
                max_erro = erro;
        }

        printf("Iter %2d: x1 = %.6f  x2 = %.6f  x3 = %.6f  erro = %g\n",
               iter + 1, x[0], x[1], x[2], max_erro);

        if (max_erro < TOL)
            return iter + 1;
    }

    return MAX_ITER;
}

int main(void)
{
    double a[N][N] = {
        {10.0,  1.0,  1.0},
        { 1.0, 10.0,  1.0},
        { 1.0,  1.0, 10.0}
    };
    double b[N] = {12.0, 12.0, 12.0};
    double x[N] = {0.0, 0.0, 0.0}; /* chute inicial */
    int iter;

    printf("=== Metodo de Gauss-Jacobi ===\n");
    printf("Sistema:\n");
    printf(" 10x +  y +  z = 12\n");
    printf("   x + 10y +  z = 12\n");
    printf("   x +   y + 10z = 12\n\n");

    printf("Chute inicial: x = (0, 0, 0)\n\n");

    iter = gauss_jacobi(a, b, x, N);

    printf("\nSolucao apos %d iteracoes:\n", iter);
    printf("x = %.10f\n", x[0]);
    printf("y = %.10f\n", x[1]);
    printf("z = %.10f\n", x[2]);

    return 0;
}
