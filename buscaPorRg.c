#include"lib.h"
void buscarPorRG(Lista *L, int rg) {
    int comp = 0, mov = 0;
    clock_t t0 = clock();
    for (int i = 0; i < L->tamanho; i++) {
        comp++;
        if (L->itens[i].rg == rg) {
            clock_t t1 = clock();
            double tempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
            printf("\nBusca por RG %d:\n", rg);
            printf("Nome: %s, RG: %d\n", L->itens[i].nome, rg);
            printf("C(n): %d, M(n): %d\n", comp, mov);
            printf("Tempo: %.6f s, Posicao: %d\n", tempo, i+1);
            return;
        }
        mov++;
    }
    clock_t t1 = clock();
    double tempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("\nBusca por RG %d:\nNenhum item encontrado.\n", rg);
    printf("C(n): %d, M(n): %d\n", comp, mov);
    printf("Tempo: %.6f s\n", tempo);
}