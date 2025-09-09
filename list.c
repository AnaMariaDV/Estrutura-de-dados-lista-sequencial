// list.c
#include "lib.h"

void ensureCapacity(Lista *L) {
    if (L->tamanho >= L->capacidade) {
        int nova = (L->capacidade == 0 ? 4 : L->capacidade * 2);
        Item *tmp = realloc(L->itens, nova * sizeof(Item));
        if (!tmp) { perror("realloc"); exit(EXIT_FAILURE); }
        L->itens = tmp;
        L->capacidade = nova;
    }
}


void copiarString(char *dest, const char *src) {
    int i = 0;
    while (i < 49 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void inicializarLista(Lista *L) {
    L->itens = NULL;
    L->tamanho = L->capacidade = 0;
}

void liberarLista(Lista *L) {
    free(L->itens);
    L->itens = NULL;
    L->tamanho = L->capacidade = 0;
}

void inserirInicio(Lista *L, const char *nome, int rg) {
    ensureCapacity(L);
    for (int i = L->tamanho; i > 0; --i)
        L->itens[i] = L->itens[i - 1];
    copiarString(L->itens[0].nome, nome);
    L->itens[0].rg = rg;
    L->tamanho++;
}

void inserirFim(Lista *L, const char *nome, int rg) {
    ensureCapacity(L);
    copiarString(L->itens[L->tamanho].nome, nome);
    L->itens[L->tamanho].rg = rg;
    L->tamanho++;
}

void inserirPosicao(Lista *L, const char *nome, int rg, int pos) {
    if (pos <= 1) { inserirInicio(L, nome, rg); return; }
    if (pos > L->tamanho + 1) { inserirFim(L, nome, rg); return; }
    ensureCapacity(L);
    for (int i = L->tamanho; i >= pos; --i)
        L->itens[i] = L->itens[i - 1];
    copiarString(L->itens[pos - 1].nome, nome);
    L->itens[pos - 1].rg = rg;
    L->tamanho++;
}

void removerInicio(Lista *L) {
    if (L->tamanho == 0) return;
    for (int i = 0; i < L->tamanho - 1; ++i)
        L->itens[i] = L->itens[i + 1];
    L->tamanho--;
}

void removerFim(Lista *L) {
    if (L->tamanho == 0) return;
    L->tamanho--;
}

void removerPosicao(Lista *L, int pos) {
    if (pos < 1 || pos > L->tamanho) return;
    if (pos == 1) { removerInicio(L); return; }
    if (pos == L->tamanho) { removerFim(L); return; }
    for (int i = pos - 1; i < L->tamanho - 1; ++i)
        L->itens[i] = L->itens[i + 1];
    L->tamanho--;
}

void buscarPorRG(Lista *L, int rg) {
    for (int i = 0; i < L->tamanho; ++i)
        if (L->itens[i].rg == rg) {
            printf("Encontrado: %s, %d (pos %d)\n",
                   L->itens[i].nome, rg, i+1);
            return;
        }
    printf("RG %d nao encontrado\n", rg);
}


void imprimirLista(Lista *L) {
    for (int i = 0; i < L->tamanho; ++i)
        printf("%d: %s, %d\n",
               i+1,
               L->itens[i].nome,
               L->itens[i].rg);
}
