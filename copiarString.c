#include"lib.h"


void copiarString(char *destino, const char *origem) {
    int i = 0;
    while (origem[i] != '\0' && i < 49) {
        destino[i] = origem[i++];
    }
    destino[i] = '\0';
}
