#include <stdio.h>
#include "tabela_hash.h"

int main()
{
    TabelaHash *hash = hash_criar(10);

    hash_inserir(hash, 15);
    hash_inserir(hash, 25);
    hash_inserir(hash, 35);
    hash_inserir(hash, 12);

    printf("Tabela Hash:\n");
    hash_exibir(hash);

    printf("\nBuscando 25...\n");

    if (hash_buscar(hash, 25) != -1)
        printf("Valor encontrado.\n");
    else
        printf("Valor nao encontrado.\n");

    printf("\nRemovendo 25...\n");

    hash_remover(hash, 25);
    
    hash_exibir(hash);

    if (hash_esta_vazia(hash))
        printf("\nTabela vazia.\n");
    else
        printf("\nTabela possui elementos.\n");

    hash_destruir(hash);

    return 0;
}