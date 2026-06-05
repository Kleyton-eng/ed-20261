#ifndef SELECAO_H
#define SELECAO_H

int linearSearch(int vetor[], int n, int valor);
void troca(int *a, int *b);
int particionar(int vetor[], int inicio, int fim);
int quickSelect(int vetor[], int inicio, int fim, int k);

#endif