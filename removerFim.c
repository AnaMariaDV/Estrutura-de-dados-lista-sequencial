#include"lib.h"
void removerFim(Lista *L) {
    int comp = 0, mov = 0;
    clock_t t0 = clock();
    if (L->tamanho == 0) {
        printf("Lista vazia.\n");
        return;
    }
    Item rem = L->itens[L->tamanho-1]; mov++;
    L->tamanho--;
    clock_t t1 = clock();
    double tempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("\nRemocao no fim:\n");
    printf("Nome: %s, RG: %d\n", rem.nome, rem.rg);
    printf("C(n): %d, M(n): %d\n", comp, mov);
    printf("Tempo: %.6f s, Posicao: %d\n", tempo, L->tamanho+1);
}