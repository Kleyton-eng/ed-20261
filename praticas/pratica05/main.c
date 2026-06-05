#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 10000

int main() {
    int v[TAM];
    int copia[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % 1000;
        copia[i] = v[i];
    }

    int k = 20;

    clock_t inicio, fim;

    inicio = clock();
    int res1 = linearSearch(v, TAM, k);
    fim = clock();
    double tempo1 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // quickSelect
    inicio = clock();
    int res2 = quickSelect(copia, 0, TAM - 1, k);
    fim = clock();
    double tempo2 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Selecao O(n^2):\n");
    printf("%d-esimo menor: %d\n", k, res1);
    printf("Tempo: %f segundos\n\n", tempo1);

    printf("Quick Select:\n");
    printf("%d-esimo menor: %d\n", k, res2);
    printf("Tempo: %f segundos\n", tempo2);

    return 0;
}