#ifndef SEQ_H
#define SEQ_H

#include <time.h>

#define MAX 100

typedef struct {
    char nome[50];   // até 49 caracteres + '\0'
    int rg;          // RG de 9 dígitos
} Item;

typedef struct {
    Item itens[MAX];
    int tamanho;
} Lista;
void copiarString(char *dest, const char *src);
// inicializa a lista (tamanho = 0)
void inicializarLista(Lista *L);
void inserirInicio(Lista *L, const char *nome, int rg);
void inserirFim(Lista *L, const char *nome, int rg);
void inserirPosicao(Lista *L, const char *nome, int rg, int posDesejada);
void removerInicio(Lista *L);
void removerFim(Lista *L);
void removerPosicao(Lista *L, int posDesejada);

// busca sequencial por RG com métricas integradas
void buscarPorRG(Lista *L, int rg);

// operações auxiliares
void imprimirLista(Lista *L);
void salvarLista(Lista *L, const char *nomeArquivo);
void lerLista(Lista *L, const char *nomeArquivo);
void sairDoSistema();

// menu principal
void menuSequencial(Lista *L);

#endif
