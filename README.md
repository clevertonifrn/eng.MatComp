# Matemática Computacional — Engenharia Elétrica

* **Carga horária:** 20ha (5 semanas, 2 encontros/semana de 2ha cada)
* **Linguagem:** C99
* **Compilador:** GCC 12.1.0 (Ubuntu 12.1.0-2ubuntu1~22.04)
* **Pré-requisito:** Algoritmos e programação (geralmente C)

## Conteúdo Programático

| Semana | Aulas | Tópico |
|--------|-------|--------|
| 1 | 1–2 | Introdução aos Erros (conversão decimal↔binário, ponto flutuante) + Teorema de Taylor |
| 2 | 3–4 | Zeros de Funções (bisseção, Newton–Raphson, secante) |
| 3 | 5–6 | Interpolação (Lagrange, Newton, spline linear) + Integração Numérica (trapézios, Simpson) |
| 4 | 7–8 | EDOs (Euler, Euler modificado, Runge–Kutta 4ª ordem) + Avaliação

## Avaliação

- Trabalhos práticos de implementação em C sobre EDO

---
## Semana 1 — Introdução aos Erros e Teorema de Taylor

**Código:** `01_erros_conversao.c`

**Resumo:** Conversão entre sistemas decimal e binário para números inteiros e fracionários. Padrão IEEE 754 de ponto flutuante (float e double). Erros de arredondamento, truncamento e cancelamento catastrófico. O Teorema de Taylor como ferramenta para aproximar funções por polinômios e estimar erros.

**Exercícios:**
1. Implemente um programa que compute `(1 - cos(x)) / sin(x)` para x pequeno (ex: 10⁻⁷). Compare o resultado com a forma algebricamente equivalente `sin(x) / (1 + cos(x))`. Explique a diferença observada.
2. Aproxime `e^x` pela série de Taylor com n termos para x = 0.5. Compare o resultado com `exp()` da biblioteca `math.h` e mostre como o erro diminui conforme n aumenta.

**Referências:**
- RUGGIERO, M. A. G.; LOPES, V. L. R. *Cálculo Numérico: Aspectos Teóricos e Computacionais*. 2. ed. Pearson, 1997. Cap. 1.
- FRANCO, N. B. *Cálculo Numérico*. 2. ed. Pearson, 2007. Cap. 1.

---
## Semana 2 — Zeros de Funções

**Códigos:** `02_bissecao.c`, `03_newton_raphson.c`

**Resumo:** Métodos numéricos para encontrar raízes de equações da forma f(x) = 0. Bisseção: robusto, baseado no teorema do valor intermediário, convergência lenta. Newton-Raphson: convergência quadrática, requer derivada de f. Secante: aproximação da derivada por diferenças finitas, sem necessidade de f'(x). Critérios de parada.

**Exercícios:**
1. Implemente o método da secante e compare o número de iterações necessárias com o método da bisseção e Newton-Raphson para a mesma função e tolerância.
2. Encontre todas as raízes reais de `f(x) = x³ - 9x + 3` testando diferentes chutes iniciais. Use o polinômio quadrático obtido por Briot-Ruffini para refinar as aproximações.

**Referências:**
- RUGGIERO, M. A. G.; LOPES, V. L. R. *Cálculo Numérico: Aspectos Teóricos e Computacionais*. 2. ed. Pearson, 1997. Cap. 2.
- FRANCO, N. B. *Cálculo Numérico*. 2. ed. Pearson, 2007. Cap. 3.

---
## Semana 3 — Interpolação e Integração Numérica

**Códigos:** `04_interpolacao_lagrange.c`, `05_simpson.c`

**Resumo:** Interpolação polinomial: formas de Lagrange e de Newton (diferenças divididas), Fenômeno de Runge e alternância com splines lineares. Integração numérica: fórmulas de Newton-Cotes — regra dos trapézios (1ª ordem) e regra de Simpson (2ª ordem). Estimativa de erro de truncamento em cada método.

**Exercícios:**
1. Implemente a interpolação de Newton por diferenças divididas para os mesmos pontos do código da aula e verifique que o polinômio é o mesmo, apenas escrito em outra base.
2. Implemente a regra dos trapézios composta para integrar sen(x) em [0, π/2] com n = 10, 20, 40 e compare o erro com a regra de Simpson para os mesmos n.

**Referências:**
- RUGGIERO, M. A. G.; LOPES, V. L. R. *Cálculo Numérico: Aspectos Teóricos e Computacionais*. 2. ed. Pearson, 1997. Cap. 4 (interpolação) e Cap. 5 (integração).
- FRANCO, N. B. *Cálculo Numérico*. 2. ed. Pearson, 2007. Cap. 5 (interpolação) e Cap. 6 (integração).

---
## Semana 4 — EDOs e Avaliação Final

**Códigos:** `06_euler.c`, `07_runge_kutta.c`

**Resumo:** Solução numérica de problemas de valor inicial (PVI) para equações diferenciais ordinárias de 1ª ordem. Método de Euler (1ª ordem, erro O(h)), Euler modificado (método de Heun), Runge-Kutta de 4ª ordem (erro O(h⁴)). Métodos de passo múltiplo: previsão-correção. Comparação entre métodos e análise de erro.

**Exercícios:**
1. Implemente o método de Euler modificado (predictor-corrector) para o PVI `y' = y, y(0) = 1` e compare o erro com o Euler padrão do código da aula para h = 0.1.
2. Resolva `y' = -2xy, y(0) = 1` no intervalo [0, 2] com RK4 usando h = 0.2, 0.1 e 0.05. Calcule o erro em x = 2 para cada passo e verifique a ordem de convergência.

**Referências:**
- RUGGIERO, M. A. G.; LOPES, V. L. R. *Cálculo Numérico: Aspectos Teóricos e Computacionais*. 2. ed. Pearson, 1997. Cap. 6.
- FRANCO, N. B. *Cálculo Numérico*. 2. ed. Pearson, 2007. Cap. 7.

---
## Códigos

Os exemplos implementados em aula estão em `codigos/`.

### Bibliotecas utilizadas

| Biblioteca | Cabeçalho | Linkagem |
|------------|-----------|----------|
| Matemática padrão | `math.h` | `-lm` |

### Compilação

Compilar **todos** os exemplos de uma vez:

    make -C codigos

Compilar cada exemplo **individualmente**:

| Arquivo | Comando |
|---------|---------|
| `01_erros_conversao.c` | `gcc -std=c99 -Wall -pedantic -o 01_erros_conversao codigos/01_erros_conversao.c -lm` |
| `02_bissecao.c` | `gcc -std=c99 -Wall -pedantic -o 02_bissecao codigos/02_bissecao.c -lm` |
| `03_newton_raphson.c` | `gcc -std=c99 -Wall -pedantic -o 03_newton_raphson codigos/03_newton_raphson.c -lm` |
| `04_interpolacao_lagrange.c` | `gcc -std=c99 -Wall -pedantic -o 04_interpolacao_lagrange codigos/04_interpolacao_lagrange.c -lm` |
| `05_simpson.c` | `gcc -std=c99 -Wall -pedantic -o 05_simpson codigos/05_simpson.c -lm` |
| `06_euler.c` | `gcc -std=c99 -Wall -pedantic -o 06_euler codigos/06_euler.c -lm` |
| `07_runge_kutta.c` | `gcc -std=c99 -Wall -pedantic -o 07_runge_kutta codigos/07_runge_kutta.c -lm` |

Onde:
- `-std=c99` força o padrão C99 (permite VLAs, declarações misturadas, etc.)
- `-Wall -pedantic` ativa todos os avisos de conformidade
- `-lm` linka a biblioteca matemática (`math.h`)

Os binários compilados serão gerados no diretório `codigos/`. Execute-os a partir da raiz da disciplina com, por exemplo:

    ./codigos/02_bissecao

---
*Este material foi produzido com auxílio de [opencode](https://opencode.ai).*
