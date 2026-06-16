/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Metodo de Euler para EDOs de primeira ordem
 * Disciplina: Matematica Computacional
 *
 * Resolve o PVI: y' = y, y(0) = 1 (solucao exata: y = e^x)
 * no intervalo [0, 1] com passo h = 0.1.
 */

#include <stdio.h>
#include <math.h>

/*
 * Funcao f(x, y) = y' da EDO.
 * x: ponto atual
 * y: valor de y no ponto x
 */
double f(double x, double y)
{
    /* Evita warning de parametro nao utilizado */
    (void)x;
    return y;
}

/*
 * Solucao exata da EDO: y(x) = e^x
 */
double solucao_exata(double x)
{
    return exp(x);
}

/*
 * Metodo de Euler.
 * x0, y0 : condicao inicial y(x0) = y0
 * h      : tamanho do passo
 * n      : numero de passos
 * x_sol, y_sol: vetores para armazenar os pontos (saida)
 */
void euler(double x0, double y0, double h, int n,
           double x_sol[], double y_sol[])
{
    int i;

    x_sol[0] = x0;
    y_sol[0] = y0;

    for (i = 0; i < n; i++)
    {
        y_sol[i + 1] = y_sol[i] + h * f(x_sol[i], y_sol[i]);
        x_sol[i + 1] = x_sol[i] + h;
    }
}

int main(void)
{
    double x0 = 0.0, y0 = 1.0;
    double h = 0.1;
    int n = 10;
    double x_sol[11], y_sol[11];
    int i;

    printf("=== Metodo de Euler ===\n");
    printf("PVI: y' = y,  y(0) = 1\n");
    printf("Solucao exata: y = e^x\n");
    printf("Passo h = %.1f\n\n", h);

    euler(x0, y0, h, n, x_sol, y_sol);

    printf("   x        y_euler    y_exata     erro\n");
    printf("-------------------------------------------\n");
    for (i = 0; i <= n; i++)
    {
        double exata = solucao_exata(x_sol[i]);
        printf("%7.4f  %10.6f  %10.6f  %10.6f\n",
               x_sol[i], y_sol[i], exata, fabs(y_sol[i] - exata));
    }

    return 0;
}
