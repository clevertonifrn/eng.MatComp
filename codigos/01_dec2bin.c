/* SPDX-License-Identifier: GPL-3.0-or-later */
/*
 * Exemplo: Conversao de decimal para binario
 * Disciplina: Matematica Computacional
 *
 * Converte um numero inteiro decimal para sua representacao binaria.
 */

#include <stdio.h>

/*
 * Divide o numero sucessivamente por 2, armazenando os restos
 * (0 ou 1) no array bits[]. Apos o ultimo quociente zero, os
 * restos formam o binario quando lidos em ordem inversa.
 */
void decimal_para_binario(int n, int max_bits)
{
    int bits[max_bits];
    int i = 0, j;

    if (n == 0)
    {
        printf("0");
        return;
    }

    while (n > 0 && i < max_bits)
    {
        bits[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (j = i - 1; j >= 0; j--)
        printf("%d", bits[j]);
}

/*
 * Le um inteiro decimal do usuario e chama a funcao de
 * conversao, exibindo o resultado em binario.
 */
int main(void)
{
    int num;

    printf("=== Conversao Decimal -> Binario ===\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    printf("Decimal: %d\n", num);
    printf("Binario: ");
    decimal_para_binario(num, 32);
    printf("\n");

    return 0;
}
