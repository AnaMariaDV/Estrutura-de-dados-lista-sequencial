#include"lib.h"

void inserirInicio(Lista *lista, const char *nome, int rg) {
    clock_t t0 = clock();
    ensureCapacity(lista);
    for (int i = lista->tamanho; i > 0; --i)
        lista->itens[i] = lista->itens[i - 1];
    copiarString(lista->itens[0].nome, nome);
    lista->itens[0].rg = rg;
    lista->tamanho++;
    double dur = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("Insercao inicio: %s, %d  Tempo=%.6f s  Pos=1\n", nome, rg, dur);
}