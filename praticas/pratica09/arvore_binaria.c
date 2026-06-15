#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    struct no_t *esquerda;
    int valor;
    struct no_t *direita;
} No;

struct arvore_t {
    No *raiz;
};

static No *inserir_no(No *raiz, int valor);
static void exibir_pre_ordem(No *raiz);
static void exibir_em_ordem(No *raiz);
static void exibir_pos_ordem(No *raiz);
static void destruir_nos(No *raiz);

Arvore *arvore_criar() {

    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));

    if (arvore == NULL) {
        return NULL;
    }

    arvore->raiz = NULL;

    return arvore;
}

int arvore_esta_vazia(Arvore *arvore) {
    return arvore != NULL && arvore->raiz == NULL;
}

static No *inserir_no(No *raiz, int valor) {

    if (raiz == NULL) {

        No *novo = (No *)malloc(sizeof(No));

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor);
    }
    else {
        raiz->direita = inserir_no(raiz->direita, valor);
    }

    return raiz;
}

void arvore_inserir(Arvore *arvore, int valor) {
    arvore->raiz = inserir_no(arvore->raiz, valor);
}

static void exibir_pre_ordem(No *raiz) {

    if (raiz == NULL) {
        return;
    }

    printf("%d ", raiz->valor);

    exibir_pre_ordem(raiz->esquerda);
    exibir_pre_ordem(raiz->direita);
}

void arvore_exibir_pre_ordem(Arvore *arvore) {

    exibir_pre_ordem(arvore->raiz);

    printf("\n");
}

static void exibir_em_ordem(No *raiz) {

    if (raiz == NULL) {
        return;
    }

    exibir_em_ordem(raiz->esquerda);

    printf("%d ", raiz->valor);

    exibir_em_ordem(raiz->direita);
}

void arvore_exibir_em_ordem(Arvore *arvore) {

    exibir_em_ordem(arvore->raiz);

    printf("\n");
}

static void exibir_pos_ordem(No *raiz) {

    if (raiz == NULL) {
        return;
    }

    exibir_pos_ordem(raiz->esquerda);
    exibir_pos_ordem(raiz->direita);

    printf("%d ", raiz->valor);
}

void arvore_exibir_pos_ordem(Arvore *arvore) {

    exibir_pos_ordem(arvore->raiz);

    printf("\n");
}

static void destruir_nos(No *raiz) {

    if (raiz == NULL) {
        return;
    }

    destruir_nos(raiz->esquerda);
    destruir_nos(raiz->direita);

    free(raiz);
}

void arvore_destruir(Arvore *arvore) {

    destruir_nos(arvore->raiz);

    free(arvore);
}