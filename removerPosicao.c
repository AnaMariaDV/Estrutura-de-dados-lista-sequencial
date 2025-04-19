#include"lib.h"
void removerPosicao(Lista *L, int posDesejada) {
    int comp = 0, mov = 0;
    clock_t t0 = clock();
    if (L->tamanho == 0 || posDesejada < 1 || posDesejada > L->tamanho) {
        printf("Posicao invalida.\n");
        return;
    }
    if (posDesejada == 1) {
        removerInicio(L);
        return;
    }
    Item rem = L->itens[posDesejada-1]; mov++;
    for (int i = posDesejada-1; i < L->tamanho-1; i++) {
        L->itens[i] = L->itens[i+1];
        mov++;
    }
    L->tamanho--;
    clock_t t1 = clock();
    double tempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("\nRemocao na posicao %d:\n", posDesejada);
    printf("Nome: %s, RG: %d\n", rem.nome, rem.rg);
    printf("C(n): %d, M(n): %d\n", comp, mov);
    printf("Tempo: %.6f s, Posicao: %d\n", tempo, posDesejada);
}