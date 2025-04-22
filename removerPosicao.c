#include"lib.h"

void removerPosicao(Lista *lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posicao invalida.\n");
        return;
    }
    if (posicao == 1) {
        removerInicio(lista);
        return;
    }
    if (posicao == lista->tamanho) {
        removerFim(lista);
        return;
    }
    clock_t t0 = clock();
    for (int i = posicao - 1; i < lista->tamanho - 1; ++i)
        lista->itens[i] = lista->itens[i + 1];
    lista->tamanho--;
    double dur = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("Remocao pos %d: Tempo=%.6f s\n", posicao, dur);
}