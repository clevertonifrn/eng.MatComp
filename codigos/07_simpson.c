/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Regra de Simpson para integracao numerica
 * Disciplina: Matematica Computacional
 *
 * Calcula a integral de f(x) = sen(x) no intervalo [0, pi/2]
 * usando a regra de Simpson (1/3).
 */

#include <stdio.h>
#include <math.h>

/*
 * Funcao a ser integrada: f(x) = sen(x)
 */
double f(double x)
{
    return sin(x);
}

/*
 * Regra de Simpson 1/3 composta.
 * a, b    : limites de integracao
 * n       : numero de subintervalos (deve ser par)
 * Retorna a aproximacao da integral.
 */
double simpson(double a, double b, int n)
{
    double h, soma, x;
    int i;

    h = (b - a) / (double)n;
    soma = f(a) + f(b);

    for (i = 1; i < n; i++)
    {
        x = a + i * h;
        if (i % 2 == 0)
            soma = soma + 2.0 * f(x);
        else
            soma = soma + 4.0 * f(x);
    }

    return (h / 3.0) * soma;
}

int main(void)
{
    double a = 0.0;
    double b = acos(-1.0) / 2.0;
    int n = 10;
    double resultado, valor_exato;

    printf("=== Regra de Simpson ===\n");
    printf("f(x) = sen(x)\n");
    printf("Intervalo: [0, pi/2]\n");
    printf("Subintervalos: %d (deve ser par)\n\n", n);

    resultado = simpson(a, b, n);
    valor_exato = 1.0; /* integral de sen(x) de 0 a pi/2 = -cos(pi/2) - (-cos(0)) = 1 */

    printf("Integral aproximada: %.10f\n", resultado);
    printf("Valor exato:         %.10f\n", valor_exato);
    printf("Erro absoluto:       %g\n", fabs(resultado - valor_exato));

    return 0;
}
