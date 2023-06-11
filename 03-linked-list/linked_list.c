#include<stdio.h>
#include<malloc.h>

void showMenu() {
  printf("/////////////////////////////\n\n");
  printf("Selecione uma opção\n");
  printf("1. Inserir Valor na Lista\n");
  printf("2. Inserir Valor na Posição da Lista\n");
  printf("3. Remover Último Valor da Lista\n");
  printf("4. Remover Valor da Lista\n");
  printf("5. Remover Posição da Lista\n");
  printf("6. Pesquisar Valor na Lista\n");
  printf("7. Mostrar Lista\n");
  printf("0. Finalizar Programa\n\n");
  printf("/////////////////////////////\n\n");
}

typedef struct no {
int valor;
struct no* prox;
} NO;

int listSize(NO* inicio) {
  NO* aux = inicio;
  int size = 0;

  while(aux != NULL) {
    size++;
    aux = aux->prox;
  }

  return size;
}

void insertValue(NO** inicio, NO** fim, int valor) {
  NO* novo = (NO*) malloc(sizeof(NO));
  novo->valor = valor;
  novo->prox = NULL;

  if(*inicio == NULL) {
    *inicio = novo;
    *fim = novo;
  } else {
    (*fim)->prox = novo;
    *fim = novo;
  }
}

void insertValueInPosition(NO** inicio, int valor, int posicao) {
  NO* novo = (NO*) malloc(sizeof(NO));
  novo->valor = valor;
  novo->prox = NULL;

  if (posicao <= 0 || posicao > listSize(*inicio)) {
    printf("Posição Inválida!\n");
    return;
  }

  if(*inicio == NULL) {
    *inicio = novo;
  } else {
    NO* aux = *inicio;
    int i = 0;
    while(i < posicao-1) {
      aux = aux->prox;
      i++;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
  }
}

void removeLastValueInList(NO** inicio, NO** fim) {
  if(*inicio == NULL) {
    printf("Lista Vazia!\n");
    return;
  }

  if(*inicio == *fim) {
    *inicio = NULL;
    *fim = NULL;
  } else {
    NO* aux = *inicio;
    while(aux->prox != *fim) {
      aux = aux->prox;
    }
    printf("%d\n", aux->prox->valor);
    aux->prox = NULL;
    *fim = aux;
  }
}

void removeValueInList(NO ** inicio, int valor) {
  if (*inicio == NULL) {
    printf("Lista Vazia!\n");
    return;
  }

  if ((*inicio)->valor == valor) {
    *inicio = (*inicio)->prox;
  } else {
    NO* aux = *inicio;
    while(aux->prox != NULL && aux->prox->valor != valor) {
      aux = aux->prox;
    }
    if (aux->prox == NULL) {
      printf("VALOR NÃO ENCONTRADO NA LISTA!\n");
    } else {
      NO* aux2 = aux->prox;
      aux->prox = aux2->prox;
      printf("VALOR REMOVIDO\n");
    }
  }
}

void removePositionInList(NO** inicio, int posicao) {
  if (posicao <= 0 || posicao > listSize(*inicio)) {
    printf("POSIÇÃO ESCOLHIDA NÃO EXISTE!\n");
    return;
  }

  if (*inicio == NULL) {
    printf("Lista Vazia!\n");
    return;
  }

  if (posicao == 1) {
    *inicio = (*inicio)->prox;
  } else {
    NO* aux = *inicio;
    int i = 0;
    while(i < posicao-2) {
      aux = aux->prox;
      i++;
    }
    NO* aux2 = aux->prox;
    aux->prox = aux2->prox;
  }
}

void searchValueInList(NO** inicio, int valor) {
  if (*inicio == NULL) {
    printf("Lista Vazia!\n");
    return;
  }

  NO* aux = *inicio;
  int i = 0;
  while(aux != NULL && aux->valor != valor) {
    aux = aux->prox;
    i++;
  }

  if (aux == NULL) {
    printf("VALOR NÃO ENCONTRADO NA LISTA!\n");
  } else {
    printf("VALOR EXISTE NA LISTA NA POSIÇÃO %d\n", i+1);
  }
}

void showList(NO* inicio) {
  NO* aux = inicio;

  while(aux != NULL) {
    printf("%d ", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
}


int main() {
  NO* inicio = NULL;
  NO* fim = NULL;

  int option = 1;

  while(option != 0) {
    showMenu();
    scanf("%d", &option);
    switch(option) {
      case 1:
        // Inserir Valor na Lista
        int valor;
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &valor);

        insertValue(&inicio, &fim, valor);

        printf("EXISTEM %d NUMERO(S) NA LISTA\n", listSize(inicio));

        break;
      case 2:
        // Inserir Valor na Posição da Lista
        int posicao;
        printf("Digite o valor a ser inserido: \n");
        scanf("%d", &valor);

        printf("Digite a posição a ser inserido: \n");
        scanf("%d", &posicao);

        insertValueInPosition(&inicio, valor, posicao);

        printf("EXISTEM %d NUMERO(S) NA LISTA\n", listSize(inicio));

        break;
      case 3:
        // Remover Último Valor da Lista
        removeLastValueInList(&inicio, &fim);

        printf("EXISTEM %d NUMERO(S) NA LISTA\n", listSize(inicio));

        break;
      case 4:
        // Remover Valor da Lista
        printf("Digite valor a ser removido: \n");
        scanf("%d", &valor);
        removeValueInList(&inicio, valor);

        printf("EXISTEM %d NUMERO(S) NA LISTA\n", listSize(inicio));
        break;
      case 5:
        // Remover Posição da Lista
        printf("Digite a posição a ser removida: \n");
        scanf("%d", &posicao);
        removePositionInList(&inicio, posicao);

        printf("EXISTEM %d NUMERO(S) NA LISTA\n", listSize(inicio));
        break;
      case 6:
        // Pesquisar Valor na Lista
        printf("Digite o valor a ser pesquisado: \n");
        scanf("%d", &valor);
        searchValueInList(&inicio, valor);

        break;
      case 7:
        // Mostrar Lista
        showList(inicio);
        break;
      default:
        printf("Opção Inválida!\n");
        break;
    }
  }
}
