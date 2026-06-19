#include <stdio.h>
#include "pilha.h"

int main() {

    Pilha *p = pilha_criar();

    printf("Empilhando elementos...\n");

    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);
    pilha_empilhar(p, 40);

    printf("\nPilha atual:\n");
    pilha_exibir(p);

    printf("\nTopo da pilha: %d\n", pilha_topo(p));

    printf("\nDesempilhando um elemento...\n");
    pilha_desempilhar(p);

    pilha_exibir(p);

    printf("\nNovo topo: %d\n", pilha_topo(p));

    printf("\nDesempilhando outro elemento...\n");
    pilha_desempilhar(p);

    pilha_exibir(p);

    if (pilha_esta_vazia(p)) {
        printf("\nA pilha esta vazia.\n");
    } else {
        printf("\nA pilha nao esta vazia.\n");
    }

    pilha_destruir(p);

    return 0;
}
