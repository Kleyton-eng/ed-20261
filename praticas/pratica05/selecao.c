#include "selecao.h"

void troca(int *a, int *b) {
    int n = *a;
    *a = *b;
    *b = n;
}

int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio;
    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            troca(&v[i], &v[j]);
            i++;
        }
    }
    troca(&v[i], &v[fim]);
    return i;
}

int linearSearch(int v[], int n, int k){ 
    for (int i = 0; i < n; i++) {
        int menores = 0;
        int iguaisAntes = 0;

        for (int j = 0; j < n; j++) {
            if (v[j] < v[i]) {
                menores++;
            } else if (v[j] == v[i] && j < i) {
                iguaisAntes++;
            }
        }

        if (menores + iguaisAntes == k) {
            return v[i];
        }
    }
    return -1;
}

int quickSelect(int v[], int inicio, int fim, int valor){
    if (valor > 0 && valor <= fim - inicio + 1) {
        int p = particionar(v, inicio, fim);
        if (p - inicio == valor - 1){
            return v[p];
        }
        if (p - inicio > valor - 1){
            return quickSelect(v, inicio, p - 1, valor);
        }
        return quickSelect(v, p + 1, fim, valor - p + inicio - 1);
    }
    return -1;
}