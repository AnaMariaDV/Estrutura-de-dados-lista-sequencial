#include"lib.h"
void salvarLista(Lista *L, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "w");
    if (!arq) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }
    for (int i = 0; i < L->tamanho; i++) {
        fprintf(arq, "%s,%d\n", L->itens[i].nome, L->itens[i].rg);
    }
    fclose(arq);
    printf("Lista salva em %s\n", nomeArquivo);
}