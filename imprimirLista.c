#include"lib.h"
void imprimirLista(Lista *L) {
    if (L->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    printf("\nLista atual:\n");
    for (int i = 0; i < L->tamanho; i++) {
        printf("%d: %s, %d\n", i + 1, L->itens[i].nome, L->itens[i].rg);
    }
}