#include"lib.h"

void salvarLista(Lista *lista, const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "w");
    if (!f) { printf("Erro escrita.\n"); return; }
    for (int i = 0; i < lista->tamanho; ++i)
        fprintf(f, "%s,%d\n",
                lista->itens[i].nome, lista->itens[i].rg);
    fclose(f);
    printf("Salvo em %s\n", nomeArquivo);
}