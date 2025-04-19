#include"lib.h"
void inserirInicio(Lista *L, const char *nome, int rg) {
    int comp = 0, mov = 0;
    clock_t t0 = clock();
    if (L->tamanho >= MAX) {
        printf("Lista cheia.\n");
        return;
    }
    // desloca elementos para a direita
    for (int i = L->tamanho; i > 0; i--) {
        L->itens[i] = L->itens[i-1];
        mov++;
    }
    copiarString(L->itens[0].nome, nome); mov += (int)strlen(nome) + 1;
    L->itens[0].rg = rg; mov++;
    L->tamanho++;
    clock_t t1 = clock();
    double tempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("\nInsercao no inicio:\n");
    printf("Nome: %s, RG: %d\n", nome, rg);
    printf("C(n): %d, M(n): %d\n", comp, mov);
    printf("Tempo: %.6f s, Posicao: 1\n", tempo);
}