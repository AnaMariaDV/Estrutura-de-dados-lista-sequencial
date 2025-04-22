#include"lib.h"

void menuSequencial(Lista *lista) {
    int opcao, rg, pos;
    char nome[50], arq[100];
    do {
        printf("\n1-Ini 2-Fim 3-Pos 4-RIni 5-RFim 6-RPos "
               "7-Busca 8-Imp 9-Salva 10-Le 0-Sair: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Nome: "); scanf("%49s", nome);
                printf("RG:   "); scanf("%d", &rg);
                inserirInicio(lista, nome, rg);
                break;
            case 2:
                printf("Nome: "); scanf("%49s", nome);
                printf("RG:   "); scanf("%d", &rg);
                inserirFim(lista, nome, rg);
                break;
            case 3:
                printf("Nome:    "); scanf("%49s", nome);
                printf("RG:      "); scanf("%d", &rg);
                printf("Posicao: "); scanf("%d", &pos);
                inserirPosicao(lista, nome, rg, pos);
                break;
            case 4:
                removerInicio(lista);
                break;
            case 5:
                removerFim(lista);
                break;
            case 6:
                printf("Posicao: "); scanf("%d", &pos);
                removerPosicao(lista, pos);
                break;
            case 7:
                printf("RG:      "); scanf("%d", &rg);
                buscarPorRG(lista, rg);
                break;
            case 8:
                imprimirLista(lista);
                break;
            case 9:
                printf("Arquivo: "); scanf("%s", arq);
                salvarLista(lista, arq);
                break;
            case 10:
                printf("Arquivo: "); scanf("%s", arq);
                lerLista(lista, arq);
                break;
            case 0:
                sairDoSistema();
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}