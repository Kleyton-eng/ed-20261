#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

struct pilha_t {
    No *topo;
};

Pilha *pilha_criar() {

    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));

    if (pilha == NULL) {
        return NULL;
    }

    pilha->topo = NULL;

    return pilha;
}

int pilha_esta_vazia(Pilha *pilha) {
    return pilha != NULL && pilha->topo == NULL;
}

void pilha_empilhar(Pilha *pilha, int valor) {

    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) {
        return;
    }

    novo->valor = valor;
    novo->proximo = pilha->topo;

    pilha->topo = novo;
}

void pilha_desempilhar(Pilha *pilha) {

    if (pilha_esta_vazia(pilha)) {
        return;
    }

    No *aux = pilha->topo;

    pilha->topo = aux->proximo;

    free(aux);
}

int pilha_topo(Pilha *pilha) {

    if (pilha_esta_vazia(pilha)) {
        return -1;
    }

    return pilha->topo->valor;
}

void pilha_exibir(Pilha *pilha) {

    No *aux = pilha->topo;

    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }

    printf("NULL\n");
}

void pilha_destruir(Pilha *pilha) {

    while (!pilha_esta_vazia(pilha)) {
        pilha_desempilhar(pilha);
    }

    free(pilha);
}