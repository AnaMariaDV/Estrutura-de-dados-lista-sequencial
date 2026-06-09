#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[50];   // até 49 caracteres + '\0'
    int  rg;         // RG de 9 dígitos
} Item;


typedef struct {
    Item *itens;      
    int   tamanho;    
    int   capacidade; 
} Lista;

typedef struct {
    long comparacoes;   
    long movimentacoes; 
} Metricas;


void iniciarMetricas(void);
Metricas obterMetricas(void);


void iniciarTempo(void);
double obterTempoSegundos(void);

void imprimirMetricas(const char *operacao);

void copiarString(char *dest, const char *src);
void ensureCapacity(Lista *L);
void inicializarLista(Lista *L);
void liberarLista(Lista *L);

void inserirInicio(Lista *L, const char *nome, int rg);
void inserirFim(Lista *L, const char *nome, int rg);
void inserirPosicao(Lista *L, const char *nome, int rg, int pos);

void removerInicio(Lista *L);
void removerFim(Lista *L);
void removerPosicao(Lista *L, int pos);

void buscarPorRG(Lista *L, int rg);
void imprimirLista(Lista *L);

void salvarLista(Lista *L, const char *filename);
void lerLista(Lista *L, const char *filename);

void sairDoSistema(void);
void menuSequencial(Lista *L);

#endif // LIB_H