#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[50];   // até 49 caracteres + '\0'
    int  rg;         // RG de 9 dígitos
} Item;

typedef struct {
    Item *itens;     // vetor dinâmico
    int   tamanho;   // número atual de itens
    int   capacidade;// capacidade alocada
} Lista;

/* ——— Internas ——— */
// Versão simplificada de ensureCapacity, que aumenta a capacidade em exatamente 1 slot:

void ensureCapacity(Lista *L) {
    if (L->tamanho >= L->capacidade) {
        int novaCap = L->capacidade + 1;
        Item *tmp = realloc(L->itens, novaCap * sizeof(Item));
        if (!tmp) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        L->itens      = tmp;
        L->capacidade = novaCap;
    }
}


void copiarString(char *dest, const char *src) {
    int i = 0;
    while (src[i] && i < 49) { dest[i] = src[i]; i++; }
    dest[i] = '\0';
}

/* ——— Operações ——— */
void inicializarLista(Lista *L) {
    L->itens      = NULL;
    L->tamanho    = 0;
    L->capacidade = 0;
}

void liberarLista(Lista *L) {
    free(L->itens);
    L->itens = NULL;
    L->tamanho = L->capacidade = 0;
}

void inserirInicio(Lista *L, const char *nome, int rg) {
    int C = 0, M = 0;
    clock_t t0 = clock();

    ensureCapacity(L);
    for (int i = L->tamanho; i > 0; --i) {
        L->itens[i] = L->itens[i - 1];
        M++;
    }
    copiarString(L->itens[0].nome, nome);
    for (int j = 0; nome[j]; j++) M++;
    L->itens[0].rg = rg; M++;
    L->tamanho++;

    double tempo = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("\nInsercao Inicio:\n"
           " Nome: %s, RG: %d\n"
           " C(n): %d, M(n): %d\n"
           " Tempo: %.6f s\n"
           " Posicao: 1\n",
           nome, rg, C, M, tempo);
}

void inserirFim(Lista *L, const char *nome, int rg) {
    int C = 0, M = 0;
    clock_t t0 = clock();

    ensureCapacity(L);
    copiarString(L->itens[L->tamanho].nome, nome);
    for (int j = 0; nome[j]; j++) M++;
    L->itens[L->tamanho].rg = rg; M++;
    L->tamanho++;

    double tempo = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("\nInsercao Fim:\n"
           " Nome: %s, RG: %d\n"
           " C(n): %d, M(n): %d\n"
           " Tempo: %.6f s\n"
           " Posicao: %d\n",
           nome, rg, C, M, tempo, L->tamanho);
}

void inserirPosicao(Lista *L, const char *nome, int rg, int pos) {
    if (pos <= 1) {
        inserirInicio(L, nome, rg);
        return;
    }
    if (pos > L->tamanho + 1) {
        inserirFim(L, nome, rg);
        return;
    }

    int C = 0, M = 0;
    clock_t t0 = clock();

    ensureCapacity(L);
    for (int i = L->tamanho; i >= pos; --i) {
        L->itens[i] = L->itens[i - 1];
        M++;
    }
    copiarString(L->itens[pos - 1].nome, nome);
    for (int j = 0; nome[j]; j++) M++;
    L->itens[pos - 1].rg = rg; M++;
    L->tamanho++;

    double tempo = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("\nInsercao Posicao %d:\n"
           " Nome: %s, RG: %d\n"
           " C(n): %d, M(n): %d\n"
           " Tempo: %.6f s\n"
           " Posicao: %d\n",
           pos, nome, rg, C, M, tempo, pos);
}

void removerInicio(Lista *L) {
    int C = 0, M = 0;
    clock_t t0 = clock();

    if (L->tamanho == 0) {
        printf("\nLista vazia.\n");
        return;
    }
    Item rem = L->itens[0];
    for (int i = 0; i < L->tamanho - 1; ++i) {
        L->itens[i] = L->itens[i + 1];
        M++;
    }
    L->tamanho--;

    double tempo = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("\nRemocao Inicio:\n"
           " Nome: %s, RG: %d\n"
           " C(n): %d, M(n): %d\n"
           " Tempo: %.6f s\n"
           " Posicao: 1\n",
           rem.nome, rem.rg, C, M, tempo);
}

void removerFim(Lista *L) {
    int C = 0, M = 0;
    clock_t t0 = clock();

    if (L->tamanho == 0) {
        printf("\nLista vazia.\n");
        return;
    }
    int pos = L->tamanho;
    Item rem = L->itens[pos - 1];
    M++;
    L->tamanho--;

    double tempo = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("\nRemocao Fim:\n"
           " Nome: %s, RG: %d\n"
           " C(n): %d, M(n): %d\n"
           " Tempo: %.6f s\n"
           " Posicao: %d\n",
           rem.nome, rem.rg, C, M, tempo, pos);
}

void removerPosicao(Lista *L, int pos) {
    if (L->tamanho == 0 || pos < 1 || pos > L->tamanho) {
        printf("\nPosicao invalida.\n");
        return;
    }
    if (pos == 1) {
        removerInicio(L);
        return;
    }
    if (pos == L->tamanho) {
        removerFim(L);
        return;
    }

    int C = 0, M = 0;
    clock_t t0 = clock();

    Item rem = L->itens[pos - 1];
    M++;
    for (int i = pos - 1; i < L->tamanho - 1; ++i) {
        L->itens[i] = L->itens[i + 1];
        M++;
    }
    L->tamanho--;

    double tempo = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("\nRemocao Posicao %d:\n"
           " Nome: %s, RG: %d\n"
           " C(n): %d, M(n): %d\n"
           " Tempo: %.6f s\n"
           " Posicao: %d\n",
           pos, rem.nome, rem.rg, C, M, tempo, pos);
}

void buscarPorRG(Lista *L, int rg) {
    int C = 0, M = 0;
    clock_t t0 = clock();

    for (int i = 0; i < L->tamanho; ++i) {
        C++;
        if (L->itens[i].rg == rg) {
            double tempo = (double)(clock() - t0) / CLOCKS_PER_SEC;
            printf("\nBusca RG %d:\n"
                   " Nome: %s, RG: %d\n"
                   " C(n): %d, M(n): %d\n"
                   " Tempo: %.6f s\n"
                   " Posicao: %d\n",
                   rg, L->itens[i].nome, rg, C, M, tempo, i + 1);
            return;
        }
        M++;
    }
    double tempo = (double)(clock() - t0) / CLOCKS_PER_SEC;
    printf("\nBusca RG %d:\n"
           " Nao encontrado.\n"
           " C(n): %d, M(n): %d\n"
           " Tempo: %.6f s\n",
           rg, C, M, tempo);
}

void imprimirLista(Lista *L) {
    if (L->tamanho == 0) {
        printf("\nLista vazia.\n");
        return;
    }
    printf("\nLista atual:\n");
    for (int i = 0; i < L->tamanho; ++i) {
        printf("%d: %s, %d\n", i + 1,
               L->itens[i].nome,
               L->itens[i].rg);
    }
}

void salvarLista(Lista *L, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("fopen");
        return;
    }
    for (int i = 0; i < L->tamanho; ++i) {
        fprintf(f, "%s,%d\n",
                L->itens[i].nome,
                L->itens[i].rg);
    }
    fclose(f);
    printf("\nLista salva em '%s'.\n", filename);
}

void lerLista(Lista *L, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("fopen");
        return;
    }
    int linhas = 0;
    char buf[256];
    while (fgets(buf, sizeof(buf), f)) linhas++;
    rewind(f);

    free(L->itens);
    L->itens = malloc(linhas * sizeof(Item));
    L->capacidade = linhas;
    L->tamanho = 0;

    while (fgets(buf, sizeof(buf), f)) {
        char nome[50];
        int rg;
        if (sscanf(buf, "%49[^,],%d", nome, &rg) == 2) {
            copiarString(L->itens[L->tamanho].nome, nome);
            L->itens[L->tamanho].rg = rg;
            L->tamanho++;
        }
    }
    fclose(f);
    printf("\nLista carregada de '%s' (%d itens).\n",
           filename, L->tamanho);
}

void sairDoSistema(void) {
    printf("\nSaindo do sistema...\n");
    exit(EXIT_SUCCESS);
}

void menuSequencial(Lista *L) {
    int opc, rg, pos;
    char nome[50], filename[100];
    do {
        printf("\n=== Menu Lista Sequencial Dinamica ===\n"
               "1 - Inserir no Inicio\n"
               "2 - Inserir no Fim\n"
               "3 - Inserir na Posicao N\n"
               "4 - Remover do Inicio\n"
               "5 - Remover do Fim\n"
               "6 - Remover da Posicao N\n"
               "7 - Buscar por RG\n"
               "8 - Mostrar Lista\n"
               "9 - Salvar Lista em Arquivo\n"
               "10 - Ler Lista de Arquivo\n"
               "0 - Sair\n"
               "Escolha uma opcao: ");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                printf("Nome: "); scanf(" %49[^\n]", nome);
                printf("RG:   "); scanf("%d", &rg);
                inserirInicio(L, nome, rg);
                break;
            case 2:
                printf("Nome: "); scanf(" %49[^\n]", nome);
                printf("RG:   "); scanf("%d", &rg);
                inserirFim(L, nome, rg);
                break;
            case 3:
                printf("Nome:    "); scanf(" %49[^\n]", nome);
                printf("RG:      "); scanf("%d", &rg);
                printf("Posicaoo: "); scanf("%d", &pos);
                inserirPosicao(L, nome, rg, pos);
                break;
            case 4:
                removerInicio(L);
                break;
            case 5:
                removerFim(L);
                break;
            case 6:
                printf("Posicao: "); scanf("%d", &pos);
                removerPosicao(L, pos);
                break;
            case 7:
                printf("RG:      "); scanf("%d", &rg);
                buscarPorRG(L, rg);
                break;
            case 8:
                imprimirLista(L);
                break;
            case 9:
                printf("Arquivo p/ salvar: "); scanf(" %99s", filename);
                salvarLista(L, filename);
                break;
            case 10:
                printf("Arquivo p/ ler:   "); scanf(" %99s", filename);
                lerLista(L, filename);
                break;
            case 0:
                sairDoSistema();
                break;
            default:
                printf("\nOpção invalida!\n");
        }
    } while (opc != 0);
}

int main(void) {
    Lista clientes;
    inicializarLista(&clientes);
    menuSequencial(&clientes);
    liberarLista(&clientes);
    return 0;
}
