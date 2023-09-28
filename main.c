#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

Node* topo = NULL;

void inserir(int valor) {
    Node* novoNode = malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("\nErro ao alocar memoria para o novo elemento.\n");
        return;
    }

    novoNode->valor = valor;
    novoNode->proximo = topo;
    topo = novoNode;

    printf("\nElemento %d inserido na pilha.\n", valor);
}

void remover() {
    if (topo == NULL) {
        printf("\nA pilha esta vazia. Nao ha elementos para remover.\n");
        return;
    }

    Node* nodeRemovido = topo;
    topo = topo->proximo;

    int valorRemovido = nodeRemovido->valor;
    free(nodeRemovido);

    printf("\nElemento %d removido da pilha.\n", valorRemovido);
}

int buscar(int valor) {
    Node* atual = topo;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("\nValor %d encontrado na posição %d da pilha.\n", valor, posicao);
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }

    printf("\nValor %d nao encontrado na pilha.\n", valor);
    return -1;
}

void imprimir() {
    if (topo == NULL) {
        printf("\nA pilha esta vazia.\n");
        return;
    }

    printf("\nPilha: ");
    Node* atual = topo;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    int opcao, valor;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Buscar elemento\n");
        printf("4. Imprimir pilha\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(valor);
                break;
            case 2:
                remover();
                break;
            case 3:
                printf("\nDigite o valor a ser buscado: ");
                scanf("%d", &valor);
                buscar(valor);
                break;
            case 4:
                imprimir();
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // Liberar a memória alocada antes de sair do programa
    Node* atual = topo;
    while (atual != NULL) {
        Node* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}
