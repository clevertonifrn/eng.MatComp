/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Conversao decimal <-> binario e erro de ponto flutuante
 * Disciplina: Matematica Computacional
 * 
 * Demonstra:
 *   1. Conversao de numero decimal fracionario para binario
 *   2. Erro de representacao em ponto flutuante (float vs double)
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Converte a parte fracionaria de um numero decimal para binario.
 * Recebe a parte fracionaria (0 <= frac < 1) e o numero de bits.
 * Imprime os bits da representacao binaria.
 */
void frac_decimal_para_binario(double frac, int bits)
{
    int i;

    printf("0.");
    for (i = 0; i < bits; i++)
    {
        frac = frac * 2.0;
        if (frac >= 1.0)
        {
            printf("1");
            frac = frac - 1.0;
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

int main(void)
{
    double num;
    int parte_int;
    double parte_frac;

    printf("=== Conversao Decimal -> Binario (fracionario) ===\n");
    printf("Digite um numero fracionario (ex: 0.1): ");
    scanf("%lf", &num);

    parte_int = (int)num;
    parte_frac = num - parte_int;

    printf("Parte inteira %d em binario: %X (hexadecimal)\n",
           parte_int, parte_int);
    printf("Parte fracionaria %.10f em binario (32 bits): ", parte_frac);
    frac_decimal_para_binario(parte_frac, 32);

    printf("\n=== Erro de representacao (float vs double) ===\n");
    {
        float  f = 0.1f;
        double d = 0.1;

        printf("float  0.1 = %.20f\n", f);
        printf("double 0.1 = %.20f\n", d);
        printf("Diferenca:   %.20f\n", f - d);
    }

    return 0;
}
