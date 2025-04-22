// io.c
#include "lib.h"

/* Salvar em CSV */
void salvarLista(Lista *L, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) { perror("fopen"); return; }
    for (int i = 0; i < L->tamanho; ++i)
        fprintf(f, "%s,%d\n",
                L->itens[i].nome,
                L->itens[i].rg);
    fclose(f);
}

/* Ler de CSV */
void lerLista(Lista *L, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) { perror("fopen"); return; }
    int count = 0;
    char buf[256];
    while (fgets(buf, sizeof buf, f)) ++count;
    rewind(f);
    free(L->itens);
    L->itens = malloc(count * sizeof(Item));
    L->capacidade = count;
    L->tamanho = 0;
    while (fgets(buf, sizeof buf, f)) {
        char nome[50];
        int rg;
        if (sscanf(buf, "%49[^,],%d", nome, &rg) == 2) {
            copiarString(L->itens[L->tamanho].nome, nome);
            L->itens[L->tamanho].rg = rg;
            L->tamanho++;
        }
    }
    fclose(f);
}
