/*
Um grupo de estudantes de Educação Física está fazendo um TCC com o tema:
“Qualidade de Vida dos profissionais de TI”. Eles estão passando de sala em sala
para pegar voluntários que estejam dispostos a contribuir com a pesquisa. De início
essa pesquisa envolve pegar o peso, a idade e a altura de cada um dos voluntários e
calcular o IMC de forma individual. No fim, eles precisam obter a média de IMC de
todos os voluntários que eles pegaram.

Com o intuito de ajudá-los no trabalho, crie uma função na linguagem C que receba
uma lista de voluntários [Struct] e calcule o IMC de cada um deles. Depois crie outra
função que recebe a mesma lista de voluntários e calcule a média do IMC daquela
amostra. (Não preciso dizer que precisam usar ponteiros para isso)
*/

#include <stdio.h>
#include <string.h>

struct Voluntario {
  float peso;
  int idade;
  float altura;
  float IMC;
};

float calcularImc(struct Voluntario* voluntario) {
  float imc = (voluntario->peso/(voluntario->altura * voluntario->altura));

  return imc;
}

void calculeImc(struct Voluntario voluntario[], int qtd_voluntarios) {
  int i;
  for(i=0; i < qtd_voluntarios; i++) {
    voluntario->IMC = calcularImc(voluntario);

    voluntario ++;
  }
}

int main() {
  struct Voluntario v1 = { 85.5, 25, 1.80, 0 };
  struct Voluntario v2 = { 82.1, 18, 1.74, 0 };
  struct Voluntario v3 = { 63.2, 45, 1.68, 0 };
  struct Voluntario v4 = { 110.8, 29, 1.95, 0 };
  struct Voluntario v5 = { 54.5, 15, 1.50, 0 };

  struct Voluntario voluntarios[5];

  voluntarios[0] = v1;
  voluntarios[1] = v2;
  voluntarios[2] = v3;
  voluntarios[3] = v4;
  voluntarios[4] = v5;

  calculeImc(voluntarios, 5);

  printf("IMC do voluntario 1 %.2f\n", voluntarios[0].IMC);
  printf("IMC do voluntario 2 %.2f\n", voluntarios[1].IMC);
  printf("IMC do voluntario 3 %.2f\n", voluntarios[2].IMC);
  printf("IMC do voluntario 4 %.2f\n", voluntarios[3].IMC);
  printf("IMC do voluntario 5 %.2f\n", voluntarios[4].IMC);

  int i;
  float media = 0;
  for (i = 0; i < 5; i ++){
    media += voluntarios[i].IMC;
  }

  printf("IMC medio de todos os voluntarios %.2f\n", media/5);


  return 0;
}
