#include"lib.h"
void inserirFim(Lista *L, const char *nome, int rg) {
    int comp = 0, mov = 0;
    clock_t t0 = clock();
    if (L->tamanho >= MAX) {
        printf("Lista cheia.\n");
        return;
    }
    int pos = L->tamanho + 1;
    copiarString(L->itens[L->tamanho].nome, nome); mov += (int)strlen(nome) + 1;
    L->itens[L->tamanho].rg = rg; mov++;
    L->tamanho++;
    clock_t t1 = clock();
    double tempo = (double)(t1 - t0) / CLOCKS_PER_SEC;
    printf("\nInsercao no fim:\n");
    printf("Nome: %s, RG: %d\n", nome, rg);
    printf("C(n): %d, M(n): %d\n", comp, mov);
    printf("Tempo: %.6f s, Posicao: %d\n", tempo, pos);
}