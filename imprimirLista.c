#include"lib.h"

void imprimirLista(Lista *lista) {
    if (lista->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i < lista->tamanho; ++i)
        printf("%d: %s, %d\n", i + 1,
               lista->itens[i].nome, lista->itens[i].rg);
}