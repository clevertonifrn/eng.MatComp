/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Metodo de Newton-Raphson para zeros de funcoes
 * Disciplina: Matematica Computacional
 *
 * Encontra a raiz de f(x) = x^3 - 9x + 3 a partir de um chute inicial.
 * O metodo utiliza a derivada da funcao para convergir mais rapidamente.
 */

#include <stdio.h>
#include <math.h>

/*
 * Funcao alvo: f(x) = x^3 - 9x + 3
 */
double f(double x)
{
    return x * x * x - 9.0 * x + 3.0;
}

/*
 * Derivada da funcao: f'(x) = 3x^2 - 9
 */
double flinha(double x)
{
    return 3.0 * x * x - 9.0;
}

/*
 * Metodo de Newton-Raphson.
 * x0      : chute inicial
 * tol     : tolerancia
 * max_iter: numero maximo de iteracoes
 * Retorna a aproximacao da raiz.
 */
double newton_raphson(double x0, double tol, int max_iter)
{
    double x = x0;
    int iter = 0;

    printf("Iter %2d: x = %.10f  f(x) = %.10f\n", iter, x, f(x));

    for (iter = 1; iter <= max_iter; iter++)
    {
        if (flinha(x) == 0.0)
        {
            printf("ERRO: derivada zero em x = %.6f\n", x);
            return x;
        }

        x = x - f(x) / flinha(x);
        printf("Iter %2d: x = %.10f  f(x) = %.10f\n", iter, x, f(x));

        if (fabs(f(x)) < tol)
            break;
    }

    return x;
}

int main(void)
{
    double x0 = 0.5;
    double tol = 1e-8;
    int max_iter = 30;
    double raiz;

    printf("=== Metodo de Newton-Raphson ===\n");
    printf("f(x) = x^3 - 9x + 3\n");
    printf("Chute inicial: x0 = %.2f\n", x0);
    printf("Tolerancia: %g\n\n", tol);

    raiz = newton_raphson(x0, tol, max_iter);

    printf("\nRaiz aproximada: %.15f\n", raiz);
    printf("f(raiz) = %.15f\n", f(raiz));

    return 0;
}
