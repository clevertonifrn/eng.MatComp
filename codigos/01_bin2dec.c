/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Conversao de binario para decimal
 * Disciplina: Matematica Computacional
 *
 * Converte um numero binario (representado como string) para decimal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * Percorre cada digito binario (char) da string; quando
 * encontra '1', soma 2^(posicao) ao acumulador. A posicao
 * e definida da direita para a esquerda (menos significativo).
 */
int binario_para_decimal(const char *bin)
{
    int dec = 0;
    int len = strlen(bin);
    int i;

    for (i = 0; i < len; i++)
    {
        if (bin[i] == '1')
            dec += pow(2, len - 1 - i);
    }

    return dec;
}

/*
 * Le uma string binaria do usuario e exibe seu valor
 * decimal equivalente.
 */
int main(void)
{
    char bin[64];

    printf("=== Conversao Binario -> Decimal ===\n");
    printf("Digite um numero binario: ");
    scanf("%s", bin);

    printf("Binario: %s\n", bin);
    printf("Decimal: %d\n", binario_para_decimal(bin));

    return 0;
}
