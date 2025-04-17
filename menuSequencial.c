#include"lib.h"
void menuSequencial(Lista *L) {
    int opcao, rg, pos;
    char nome[50], arquivo[100];

    do {
        printf("\n=== Menu (Lista Sequencial) ===\n"
               "1. Inserir no inicio\n"
               "2. Inserir no fim\n"
               "3. Inserir na posicao N\n"
               "4. Remover do inicio\n"
               "5. Remover do fim\n"
               "6. Remover da posicao N\n"
               "7. Buscar por RG\n"
               "8. Mostrar lista\n"
               "9. Salvar lista em arquivo\n"
               "10. Ler lista de arquivo\n"
               "0. Sair\n"
               "Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome: "); scanf("%s", nome);
                printf("RG: ");   scanf("%d", &rg);
                inserirInicio(L, nome, rg);
                break;
            case 2:
                printf("Nome: "); scanf("%s", nome);
                printf("RG: ");   scanf("%d", &rg);
                inserirFim(L, nome, rg);
                break;
            case 3:
                printf("Nome: "); scanf("%s", nome);
                printf("RG: ");   scanf("%d", &rg);
                printf("Posicao: "); scanf("%d", &pos);
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
                printf("RG: "); scanf("%d", &rg);
                buscarPorRG(L, rg);
                break;
            case 8:
                imprimirLista(L);
                break;
            case 9:
                printf("Arquivo para salvar: "); scanf("%s", arquivo);
                salvarLista(L, arquivo);
                break;
            case 10:
                printf("Arquivo para ler: "); scanf("%s", arquivo);
                lerLista(L, arquivo);
                break;
            case 0:
                sairDoSistema();
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}