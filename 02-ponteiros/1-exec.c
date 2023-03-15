/*
O escritório de contabilidade da empresa XPTO salva o valor dos salários de cada
um dos funcionários em uma lista estática, mais conhecida como vetor. A equipe de
contabilidade, todo dia 10, precisa calcular o valor líquido de cada um dos salários
para assim fazer o depósito deles. Como é muito custoso ficar fazendo a conta para
cada valor dentro do vetor, eles pediram para a equipe de desenvolvimento criar uma
função em C que receba uma lista de salários brutos e transforme esta lista em
salários líquidos seguindo a seguinte fórmula:

Salário Líquido = Salário Bruto – 8%

Crie esta função pedida pela equipe de contabilidade. Utilize ponteiros para que a
lista retornada seja a mesma da lista enviada.
*/

#include <stdio.h>

int calcularLiquido(float* salarios, int tamanho) {
  for (int i=0; i < tamanho; i++) {
   *salarios = *salarios * 0.92;
    salarios ++;
  }
}

int main() {
  float salarios[] = {2000.0, 3000.0, 4000.0, 5000.0, 6000.0};
  int tamanho = 5;

  calcularLiquido(salarios, 10);

  int i;

  for (i = 0; i < 5; i++) {
    printf("%.2f\n", salarios[i]);
  }

  return 0;
}
