// main.c
#include "lib.h"

int main(void) {
    Lista clientes;
    inicializarLista(&clientes);
    menuSequencial(&clientes);
    liberarLista(&clientes);
    return 0;
}
