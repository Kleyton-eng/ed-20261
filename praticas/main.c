#include <stdio.h>
#include "lista_linear.h"

int main() {

    Lista *lista = lista_criar();

    printf("Inserindo elementos...\n");

    lista_inserir(lista, 10);
    lista_inserir(lista, 20);
    lista_inserir(lista, 30);
    lista_inserir(lista, 40);

    lista_exibir(lista);

    printf("\nBuscando valor 20...\n");

    if (lista_buscar(lista, 20))
        printf("Valor encontrado\n");
    else
        printf("Valor nao encontrado\n");

    printf("\nRemovendo valor 20...\n");
    lista_remover(lista, 20);

    lista_exibir(lista);

    printf("\nBuscando valor 20 novamente...\n");

    if (lista_buscar(lista, 20))
        printf("Valor encontrado!\n");
    else
        printf("Valor nao encontrado\n");

    printf("\nRemovendo valor 10...\n");
    lista_remover(lista, 10);

    lista_exibir(lista);

    lista_destruir(lista);

    return 0;
}
