#include<stdio.h>
#include<malloc.h>

typedef struct no {
int valor;
struct no* prox;
} NO;

void showMenu() {
    printf("Digite uma opção: \n");
    printf("1. Inserir Valor na Fila\n");
    printf("2. Remover Primeiro Valor da Fila\n");
    printf("3. Remover Todos os Valores da Fila\n");
    printf("4. Imprimir Fila\n");
    printf("0. Finalizar Programa\n");
    printf("\n");
    printf("\n");
}

void insertValueInQueue(NO** inicio, NO** fim, int valor) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        (*fim)->prox = novo;
    }
    *fim = novo;
}

void removeFirstValueInQueue(NO** inicio, NO** fim) {
    if (*inicio == NULL) {
        printf("A FILA ESTÁ VAZIA\n");
        printf("\n");
        return;
    }
    NO* aux = *inicio;
    *inicio = (*inicio)->prox;
    free(aux);
    if (*inicio == NULL) {
        *fim = NULL;
    }
}

void removeAllValuesInQueue(NO** inicio, NO** fim) {
    NO* aux = *inicio;
    while (aux != NULL) {
        *inicio = (*inicio)->prox;
        free(aux);
        aux = *inicio;
    }
    *fim = NULL;
}

void printQueue(NO* inicio) {
  if(inicio == NULL) {
    printf("A FILA ESTÁ VAZIA\n");
    printf("\n");
    return;
  }
  NO* aux = inicio;
  while(aux != NULL) {
    printf("%d\n", aux->valor);
    aux = aux->prox;
  }
  printf("\n");
  printf("\n");
}dasdaksdjn
sadfasdfj
void sizeQueue(NO* inicio) {
  if(inicio == NULL) {
    printf("A FILA ESTÁ VAZIA\n");
    printf("\n");
    return;
  }
  NO* aux = inicio;
  int size = 0;
  while(aux != NULL) {
    size++;
    aux = aux->prox;
  }
  printf("EXISTEM %d NUMERO(S) NA FILA\n", size);
  printf("\n");
}

int main() {
  // Sugestão para iniciar a Estrutura
  NO* inicio = NULL;asdasdasdlk
  NO* fim = NULL;

  int option = 1;

    while (option != 0) {
        showMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
              int valor;
              printf("Inserindo Valor na Fila\n");
              scanf("%d", &valor);
              insertValueInQueue(&inicio, &fim, valor);
              sizeQueue(inicio);
              break;
            case 2:
                printf("Remover Primeiro Valor da Fila\n");asdasdçlasmdçklaMDKÇL
                removeFirstValueInQueue(&inicio, &fim);
                sizeQueue(inicio);
                break;
            case 3:
                printf("Remover Todos os Valores da Fila\n");
                removeAllValuesInQueue(&inicio, &fim);
                printf("A FILA ESTÁ VAZIA\n");
                printf("\n");
                break;
            case 4:
                printf("Imprimir Fila\n");
                printQueue(inicio);
                break;
            case 0:
                printf("Finalizar Programa\n");
                printf("\n");
                break;
            default:
                printf("Opção Inválida\n");
                printf("\n");
                break;
        }
    }
    return 0;
}
