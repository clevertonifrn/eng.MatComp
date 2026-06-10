/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Metodo da Bissecao para zeros de funcoes
 * Disciplina: Matematica Computacional
 *
 * Encontra a raiz de f(x) = x^3 - 9x + 3 no intervalo [0, 1].
 * A funcao deve trocar de sinal nos extremos do intervalo.
 */

#include <stdio.h>
#include <math.h>

/*
 * Funcao alvo: f(x) = x^3 - 9x + 3
 * Retorna o valor de f no ponto x.
 */
double f(double x)
{
    return x * x * x - 9.0 * x + 3.0;
}

/*
 * Metodo da bissecao.
 * a, b   : intervalo que contem a raiz
 * tol    : tolerancia (criterio de parada)
 * max_iter: numero maximo de iteracoes
 * Retorna a aproximacao da raiz.
 */
double bissecao(double a, double b, double tol, int max_iter)
{
    double c;
    int iter = 0;

    if (f(a) * f(b) >= 0.0)
    {
        printf("ERRO: f(a) e f(b) devem ter sinais opostos.\n");
        return 0.0 / 0.0; /* NaN */
    }

    while ((b - a) / 2.0 > tol && iter < max_iter)
    {
        c = (a + b) / 2.0;
        printf("Iter %2d: a = %.6f  b = %.6f  c = %.6f  f(c) = %.6f\n",
               iter + 1, a, b, c, f(c));

        if (f(c) == 0.0)
            return c;
        if (f(a) * f(c) < 0.0)
            b = c;
        else
            a = c;

        iter++;
    }

    return (a + b) / 2.0;
}

int main(void)
{
    double a = 0.0, b = 1.0;
    double tol = 1e-6;
    int max_iter = 50;
    double raiz;

    printf("=== Metodo da Bissecao ===\n");
    printf("f(x) = x^3 - 9x + 3\n");
    printf("Intervalo inicial: [%.2f, %.2f]\n", a, b);
    printf("Tolerancia: %g\n\n", tol);

    raiz = bissecao(a, b, tol, max_iter);

    printf("\nRaiz aproximada: %.10f\n", raiz);
    printf("f(raiz) = %.10f\n", f(raiz));

    return 0;
}
