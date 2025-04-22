#include"lib.h"

void liberarLista(Lista *lista) {
    free(lista->itens);
    lista->itens      = NULL;
    lista->tamanho    = lista->capacidade = 0;
}