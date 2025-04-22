// lib.h
#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Estrutura de um cliente */
typedef struct {
    char nome[50];   // até 49 caracteres + '\0'
    int  rg;         // RG de 9 dígitos
} Item;

/* Lista sequencial dinâmica */
typedef struct {
    Item *itens;     // vetor alocado dinamicamente
    int   tamanho;   // quantidade de elementos atuais
    int   capacidade;// quantidade de slots alocados
} Lista;

/* Funções de manipulação da lista */
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
