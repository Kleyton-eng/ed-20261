#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct hash_t {
    no_t **tabela;
    int tamanho;
    int quantidade;
};

static int calcular_hash(TabelaHash *hash, int valor)
{
    return valor % hash->tamanho;
}

TabelaHash *hash_criar(int tamanho)
{
    TabelaHash *hash = malloc(sizeof(TabelaHash));

    if (hash == NULL)
        return NULL;

    hash->tabela = calloc(tamanho, sizeof(no_t *));
    hash->tamanho = tamanho;
    hash->quantidade = 0;

    return hash;
}

void hash_inserir(TabelaHash *hash, int valor)
{
    int indice = calcular_hash(hash, valor);

    no_t *novo = malloc(sizeof(no_t));

    novo->valor = valor;
    novo->proximo = hash->tabela[indice];

    hash->tabela[indice] = novo;
    hash->quantidade++;
}

int hash_buscar(TabelaHash *hash, int valor)
{
    int indice = calcular_hash(hash, valor);

    no_t *aux = hash->tabela[indice];

    while (aux != NULL)
    {
        if (aux->valor == valor)
            return indice;

        aux = aux->proximo;
    }

    return -1;
}

void hash_remover(TabelaHash *hash, int valor)
{
    int indice = calcular_hash(hash, valor);

    no_t *atual = hash->tabela[indice];
    no_t *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            if (anterior == NULL)
                hash->tabela[indice] = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);
            hash->quantidade--;
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }
}

void hash_exibir(TabelaHash *hash)
{
    for (int i = 0; i < hash->tamanho; i++)
    {
        printf("[%d] -> ", i);

        no_t *aux = hash->tabela[i];

        while (aux != NULL)
        {
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }

        printf("NULL\n");
    }
}

int hash_esta_vazia(TabelaHash *hash)
{
    return hash->quantidade == 0;
}

void hash_destruir(TabelaHash *hash)
{
    for (int i = 0; i < hash->tamanho; i++)
    {
        no_t *aux = hash->tabela[i];

        while (aux != NULL)
        {
            no_t *temp = aux;
            aux = aux->proximo;
            free(temp);
        }
    }

    free(hash->tabela);
    free(hash);
}