#include <stdio.h>
#include "fila.h"

int main() {

    Fila *f = fila_criar();

    printf("Enfileirando elementos.\n");

    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);
    fila_enfileirar(f, 40);

    printf("\nFila atual:\n");
    fila_exibir(f);

    printf("\nInicio da fila: %d\n", fila_inicio(f));

    printf("\nDesenfileirando um elemento.\n");
    fila_desenfileirar(f);

    fila_exibir(f);

    printf("\nNovo inicio: %d\n", fila_inicio(f));

    printf("\nDesenfileirando outro elemento.\n");
    fila_desenfileirar(f);

    fila_exibir(f);

    if (fila_esta_vazia(f)) {
        printf("\nA fila esta vazia.\n");
    } else {
        printf("\nA fila nao esta vazia.\n");
    }

    fila_destruir(f);

    return 0;
}