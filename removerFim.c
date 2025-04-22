#include"lib.h"

void removerFim(Lista *lista) {
    clock_t t0 = clock();
    if (lista->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    lista->tamanho--;
    double dur = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("Remocao fim: Tempo=%.6f s  Pos=%d\n", dur, lista->tamanho + 1);
}