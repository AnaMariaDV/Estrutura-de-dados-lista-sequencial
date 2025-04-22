#include"lib.h"

void inserirPosicao(Lista *lista, const char *nome, int rg, int posicao) {
    if (posicao <= 1) {
        inserirInicio(lista, nome, rg);
        return;
    }
    if (posicao > lista->tamanho + 1) {
        inserirFim(lista, nome, rg);
        return;
    }
    clock_t t0 = clock();
    ensureCapacity(lista);
    for (int i = lista->tamanho; i >= posicao; --i)
        lista->itens[i] = lista->itens[i - 1];
    copiarString(lista->itens[posicao - 1].nome, nome);
    lista->itens[posicao - 1].rg = rg;
    lista->tamanho++;
    double dur = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("Insercao pos %d: %s, %d  Tempo=%.6f s\n",
           posicao, nome, rg, dur);
}
