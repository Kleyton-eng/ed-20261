#include <stdio.h>
#include "arvore_binaria.h"

int main() {

    Arvore *arvore = arvore_criar();

    arvore_inserir(arvore, 50);
    arvore_inserir(arvore, 30);
    arvore_inserir(arvore, 70);
    arvore_inserir(arvore, 20);
    arvore_inserir(arvore, 40);
    arvore_inserir(arvore, 60);
    arvore_inserir(arvore, 80);

    printf("Pre-ordem:\n");
    arvore_exibir_pre_ordem(arvore);

    printf("Em ordem:\n");
    arvore_exibir_em_ordem(arvore);

    printf("Pos-ordem:\n");
    arvore_exibir_pos_ordem(arvore);

    arvore_destruir(arvore);

    return 0;
}