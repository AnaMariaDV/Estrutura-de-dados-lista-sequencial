#include"lib.h"

void buscarPorRG(Lista *lista, int rg) {
    clock_t t0 = clock();
    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->itens[i].rg == rg) {
            double dur = (double)(clock() - t0) / CLOCKS_PER_SEC;
            printf("Encontrado RG %d em pos %d  Tempo=%.6f s\n",
                   rg, i + 1, dur);
            return;
        }
    }
    double dur = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("RG %d nao encontrado  Tempo=%.6f s\n", rg, dur);
}