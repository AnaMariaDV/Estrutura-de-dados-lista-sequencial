#include"lib.h"
void removerInicio(Lista *L) {
    int comp = 0, mov = 0;
    clock_t t0 = clock();
    if (L->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    Item rem = L->itens[0]; mov++;
    for (int i = 0; i < L->tamanho-1; i++) {
        L->itens[i] = L->itens[i+1];
        mov++;
    }
    L->tamanho--;
    clock_t t1 = clock();
    double tempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("\nRemocao no inicio:\n");
    printf("Nome: %s, RG: %d\n", rem.nome, rem.rg);
    printf("C(n): %d, M(n): %d\n", comp, mov);
    printf("Tempo: %.6f s, Posicao: 1\n", tempo);
}