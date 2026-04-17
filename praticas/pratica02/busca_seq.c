#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaseque(int vetor[], int tamanho, int valor){
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] == valor){
            return i;
        }
        
    }
    return -1;
}

int main(){
    int vetor[100];
    int valor, posicao;

    srand(time(NULL));

    printf("Vetor gerado:\n");
    for(int i = 0; i < 100; i++){
        vetor[i] = rand() % 100;
        printf("%d\n ", vetor[i]);
    }

    valor = vetor[0];

    clock_t inicio1 = clock();
    posicao = buscaseque(vetor, 100, valor);
    clock_t fim1 = clock();

    double tempo1 = (double)(fim1 - inicio1)/CLOCKS_PER_SEC;

        printf("\nValor: %d", valor);
        printf("\nPosicao encontrada: %d", posicao);
        printf("\nTempo: %.6f segundos\n", tempo1);

    valor = vetor[99];

    clock_t inicio2 = clock();
    posicao = buscaseque(vetor, 100, valor);
    clock_t fim2 = clock();

    double tempo2 = (double)(fim2 - inicio2)/CLOCKS_PER_SEC;

        printf("\nValor: %d", valor);
        printf("\nPosicao encontrada: %d", posicao);
        printf("\nTempo: %.6f segundos\n", tempo2);

    return 0;
}