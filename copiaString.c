#include"lib.h"
void copiarString(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0' && i < 49) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}