#include"lib.h"

void inserirFim(Lista *lista, const char *nome, int rg) {
    clock_t t0 = clock();
    ensureCapacity(lista);
    copiarString(lista->itens[lista->tamanho].nome, nome);
    lista->itens[lista->tamanho].rg = rg;
    lista->tamanho++;
    double dur = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("Insercao fim: %s, %d  Tempo=%.6f s  Pos=%d\n",
           nome, rg, dur, lista->tamanho);
}