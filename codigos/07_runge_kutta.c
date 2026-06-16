/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Metodo de Runge-Kutta de 4a ordem para EDOs
 * Disciplina: Matematica Computacional
 *
 * Resolve o PVI: y' = -2xy, y(0) = 1 (solucao exata: y = e^(-x^2))
 * no intervalo [0, 2] com passo h = 0.2.
 */

#include <stdio.h>
#include <math.h>

/*
 * Funcao f(x, y) = y' = -2xy
 */
double f(double x, double y)
{
    return -2.0 * x * y;
}

/*
 * Solucao exata: y(x) = exp(-x^2)
 */
double solucao_exata(double x)
{
    return exp(-x * x);
}

/*
 * Metodo de Runge-Kutta de 4a ordem.
 * x0, y0 : condicao inicial y(x0) = y0
 * h      : tamanho do passo
 * n      : numero de passos
 * x_sol, y_sol: vetores para armazenar os pontos (saida)
 */
void runge_kutta_4(double x0, double y0, double h, int n,
                   double x_sol[], double y_sol[])
{
    int i;
    double k1, k2, k3, k4;

    x_sol[0] = x0;
    y_sol[0] = y0;

    for (i = 0; i < n; i++)
    {
        k1 = h * f(x_sol[i], y_sol[i]);
        k2 = h * f(x_sol[i] + h / 2.0, y_sol[i] + k1 / 2.0);
        k3 = h * f(x_sol[i] + h / 2.0, y_sol[i] + k2 / 2.0);
        k4 = h * f(x_sol[i] + h, y_sol[i] + k3);

        y_sol[i + 1] = y_sol[i] + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        x_sol[i + 1] = x_sol[i] + h;
    }
}

int main(void)
{
    double x0 = 0.0, y0 = 1.0;
    double h = 0.2;
    int n = 10;
    double x_sol[11], y_sol[11];
    int i;

    printf("=== Runge-Kutta de 4a ordem ===\n");
    printf("PVI: y' = -2xy,  y(0) = 1\n");
    printf("Solucao exata: y = exp(-x^2)\n");
    printf("Passo h = %.1f\n\n", h);

    runge_kutta_4(x0, y0, h, n, x_sol, y_sol);

    printf("   x        y_rk4       y_exata     erro\n");
    printf("-------------------------------------------\n");
    for (i = 0; i <= n; i++)
    {
        double exata = solucao_exata(x_sol[i]);
        printf("%7.4f  %10.6f  %10.6f  %10.6f\n",
               x_sol[i], y_sol[i], exata, fabs(y_sol[i] - exata));
    }

    return 0;
}
