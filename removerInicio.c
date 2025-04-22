#include"lib.h"

void removerInicio(Lista *lista) {
    clock_t t0 = clock();
    if (lista->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i < lista->tamanho - 1; ++i)
        lista->itens[i] = lista->itens[i + 1];
    lista->tamanho--;
    double dur = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("Remocao inicio: Tempo=%.6f s  Pos=1\n", dur);
}