#include"lib.h"
void inserirPosicao(Lista *L, const char *nome, int rg, int posDesejada) {
    int comp = 0, mov = 0;
    clock_t t0 = clock();
    if (L->tamanho >= MAX) {
        printf("Lista cheia.\n");
        return;
    }
    if (posDesejada <= 1) {
        inserirInicio(L, nome, rg);
        return;
    }
    if (posDesejada > L->tamanho + 1) {
        posDesejada = L->tamanho + 1;
    }
    for (int i = L->tamanho; i >= posDesejada; i--) {
        L->itens[i] = L->itens[i-1];
        mov++;
    }
    copiarString(L->itens[posDesejada-1].nome, nome); mov += (int)strlen(nome) + 1;
    L->itens[posDesejada-1].rg = rg; mov++;
    L->tamanho++;
    clock_t t1 = clock();
    double tempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("\nInsercao na posicao %d:\n", posDesejada);
    printf("Nome: %s, RG: %d\n", nome, rg);
    printf("C(n): %d, M(n): %d\n", comp, mov);
    printf("Tempo: %.6f s, Posicao: %d\n", tempo, posDesejada);
}