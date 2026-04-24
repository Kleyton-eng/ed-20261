#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAM 10000

void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void imprimir_tempo(const char* nome, clock_t inicio, clock_t fim) {
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("%s: %.6f segundos\n", nome, tempo);
}

int main() {
    int v[TAM], copia[TAM];

    srand(time(NULL));

    // gerar vetor aleatório
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
    }

    // BUBBLE SORT 
    copiar_vetor(v, copia, TAM);

    clock_t inicio = clock();
    bubble_sort(copia, TAM);
    clock_t fim = clock();

    imprimir_tempo("Bubble Sort", inicio, fim);

    // SELECTION SORT 
    copiar_vetor(v, copia, TAM);

    inicio = clock();
    selection_sort(copia, TAM);
    fim = clock();

    imprimir_tempo("Selection Sort", inicio, fim);

    // QUICK SORT 
    copiar_vetor(v, copia, TAM);

    inicio = clock();
    quick_sort(copia, 0, TAM - 1);
    fim = clock();

    imprimir_tempo("Quick Sort", inicio, fim);

    return 0;
}