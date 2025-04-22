#include"lib.h"

void lerLista(Lista *lista, const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "r");
    if (!f) { printf("Erro leitura.\n"); return; }

    // conta linhas
    int linhas = 0;
    char buf[256];
    while (fgets(buf, sizeof buf, f)) linhas++;
    rewind(f);

    free(lista->itens);
    lista->itens = malloc(linhas * sizeof(Item));
    lista->capacidade = linhas;
    lista->tamanho = 0;

    while (fgets(buf, sizeof buf, f)) {
        char nome[50];
        int rg;
        if (sscanf(buf, "%49[^,],%d", nome, &rg) >= 1) {
            copiarString(lista->itens[lista->tamanho].nome, nome);
            lista->itens[lista->tamanho].rg = rg;
            lista->tamanho++;
        }
    }
    fclose(f);
    printf("Carregado %s (%d itens)\n", nomeArquivo, lista->tamanho);
}
