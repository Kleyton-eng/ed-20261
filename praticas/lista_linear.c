#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    struct no_t *anterior;
    int valor;
    struct no_t *proximo;
} No;

typedef struct lista_t {
    No *primeiro;
    No *ultimo;
} Lista;

Lista *lista_criar() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));

    if (lista == NULL)
        return NULL;

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

int lista_esta_vazia(Lista *lista) {
    return lista != NULL && lista->primeiro == NULL;
}

void lista_inserir(Lista *lista, int valor) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->ultimo;

    if (lista_esta_vazia(lista)) {
        lista->primeiro = novo;
        lista->ultimo = novo;
        return;
    }

    lista->ultimo->proximo = novo;
    lista->ultimo = novo;
}

int lista_buscar(Lista *lista, int valor) {
    No *aux = lista->primeiro;

    while (aux != NULL) {
        if (aux->valor == valor)
            return 1;

        aux = aux->proximo;
    }

    return 0;
}

void lista_remover(Lista *lista, int valor) {
    if (lista_esta_vazia(lista))
        return;

    No *aux = lista->primeiro;

    while (aux != NULL) {

        if (aux->valor == valor) {

            if (aux == lista->primeiro) {
                lista->primeiro = aux->proximo;

                if (lista->primeiro != NULL)
                    lista->primeiro->anterior = NULL;
                else
                    lista->ultimo = NULL;
            }
            else if (aux == lista->ultimo) {
                lista->ultimo = aux->anterior;
                lista->ultimo->proximo = NULL;
            }
            else {
                aux->anterior->proximo = aux->proximo;
                aux->proximo->anterior = aux->anterior;
            }

            free(aux);
            return;
        }

        aux = aux->proximo;
    }
}

void lista_exibir(Lista *lista) {
    No *aux = lista->primeiro;

    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }

    printf("NULL\n");
}

void lista_destruir(Lista *lista) {
    No *aux = lista->primeiro;

    while (aux != NULL) {
        No *temp = aux;
        aux = aux->proximo;
        free(temp);
    }

    free(lista);
}
