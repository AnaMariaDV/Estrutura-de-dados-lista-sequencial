#include"lib.h"
void lerLista(Lista *L, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (!arq) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return;
    }
    inicializarLista(L);
    char linha[100], nome[50]; int rg;
    while (fgets(linha, sizeof(linha), arq)) {
        if (sscanf(linha, "%[^,],%d", nome, &rg) == 2) {
            inserirFim(L, nome, rg);
        }
    }
    fclose(arq);
    printf("Lista carregada de %s\n", nomeArquivo);
}