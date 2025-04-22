// menu.c
#include "lib.h"

void sairDoSistema(void) {
    printf("\nSaindo do sistema. Ate logo!\n");
    exit(0);
}

void menuSequencial(Lista *L) {
    int opcao, rg, posicao;
    char nome[50], arquivo[100];

    do {
        printf(
            "\n========== Menu de Operacoes ==========\n"
            " 1. Inserir no Inicio\n"
            " 2. Inserir no Fim\n"
            " 3. Inserir na Posicao N\n"
            " 4. Remover do Inicio\n"
            " 5. Remover do Fim\n"
            " 6. Remover da Posicao N\n"
            " 7. Buscar por RG\n"
            " 8. Exibir Lista\n"
            " 9. Salvar Lista em Arquivo\n"
            "10. Carregar Lista de Arquivo\n"
            " 0. Sair\n"
            "Selecione uma opcao: "
        );
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n-- Inserir no Inicio --\n");
                printf("Nome: ");
                scanf(" %49[^\n]", nome);
                printf("RG:   ");
                scanf("%d", &rg);
                inserirInicio(L, nome, rg);
                break;
            case 2:
                printf("\n-- Inserir no Fim --\n");
                printf("Nome: ");
                scanf(" %49[^\n]", nome);
                printf("RG:   ");
                scanf("%d", &rg);
                inserirFim(L, nome, rg);
                break;
            case 3:
                printf("\n-- Inserir na Posicao N --\n");
                printf("Nome:    ");
                scanf(" %49[^\n]", nome);
                printf("RG:      ");
                scanf("%d", &rg);
                printf("Posicao: ");
                scanf("%d", &posicao);
                inserirPosicao(L, nome, rg, posicao);
                break;
            case 4:
                printf("\n-- Remover do Inicio --\n");
                removerInicio(L);
                break;
            case 5:
                printf("\n-- Remover do Fim --\n");
                removerFim(L);
                break;
            case 6:
                printf("\n-- Remover da Posicao N --\n");
                printf("Posicao: ");
                scanf("%d", &posicao);
                removerPosicao(L, posicao);
                break;
            case 7:
                printf("\n-- Buscar por RG --\n");
                printf("RG:      ");
                scanf("%d", &rg);
                buscarPorRG(L, rg);
                break;
            case 8:
                printf("\n-- Exibir Lista --\n");
                imprimirLista(L);
                break;
            case 9:
                printf("\n-- Salvar Lista em Arquivo --\n");
                printf("Nome do arquivo: ");
                scanf(" %99s", arquivo);
                salvarLista(L, arquivo);
                break;
            case 10:
                printf("\n-- Carregar Lista de Arquivo --\n");
                printf("Nome do arquivo: ");
                scanf(" %99s", arquivo);
                lerLista(L, arquivo);
                break;
            case 0:
                sairDoSistema();
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

