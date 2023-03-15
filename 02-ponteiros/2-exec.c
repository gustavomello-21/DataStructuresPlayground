/*
Devido à alta demanda de atendimento no período da pandemia, a triagem do
Hospital Adventista de São Paulo precisou passar por algumas alterações. Na
triagem, é obtido alguns dados do paciente, entre eles o nome, a idade e a profissão.
Com a nova regra, se o paciente tiver mais de 60 anos ou trabalhar em alguma
profissão com alto risco de contágio de Covid (enfermeiro, médico, motorista,
motoboy ou atendente), então ele deve ter a sua prioridade no atendimento alterada
para “alta”, se não a prioridade deve ser colocada como “desconhecida” para que os
enfermeiros possam depois classificá-lo baseado nos sintomas.
Para auxiliar os funcionários da triagem, crie uma função em C que altere o tipo de
prioridade do paciente baseado nas regras descritas acima. A função precisa receber
um Paciente [Struct] e não pode ter retorno.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Paciente {
  char nome[50];
  int idade;
  char profissao[50];
  char prioridade[50];
};

bool profissao_risco(char* profissao) {
  if (strcmp(profissao, "enfermeiro") == 0 || strcmp(profissao, "médico") == 0 || strcmp(profissao, "motorista") == 0 || strcmp(profissao, "motoboy") == 0 || strcmp(profissao, "atendente") == 0) {
    return true;
  }
  else {
    return false;
  }
}

void setarPrioridade(struct Paciente* paciente) {
  if (paciente->idade > 60 || profissao_risco(paciente->profissao)) {
    strcpy(paciente->prioridade, "alta");
  }
  else {
    strcpy(paciente->prioridade, "desconhecida");
  }
}
int main() {

  struct Paciente paciente_prioridade1 = { "Senor abravanel", 30, "enfermeiro", "" };
  struct Paciente paciente_prioridade2 = { "Romario", 70, "ator", "" };
  struct Paciente paciente_sem_prioridade1 = { "Neymar", 25, "jogador", "" };

  setarPrioridade(&paciente_prioridade1);
  setarPrioridade(&paciente_prioridade2);
  setarPrioridade(&paciente_sem_prioridade1);

  printf("Prioridade paciente 1 %s\n", paciente_prioridade1.prioridade);
  printf("Prioridade paciente 2 %s\n", paciente_prioridade2.prioridade);
  printf("Prioridade paciente 3 %s\n", paciente_sem_prioridade1.prioridade);
  return 0;
}
