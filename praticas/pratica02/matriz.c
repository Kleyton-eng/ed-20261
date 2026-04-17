#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define REP 10000000


void preencher(int m[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            m[i][j] = i * TAM + j;
        }
    }
}

void exibirDoisLacos(int m[TAM][TAM]) {
    printf("Com dois lacos:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}


void exibirUmLaco(int m[TAM][TAM]) {
    printf("\nCom um unico laco:\n");
    for (int k = 0; k < TAM * TAM; k++) {
        int i = k / TAM;
        int j = k % TAM;

        printf("%3d ", m[i][j]);

        if ((k + 1) % TAM == 0) {
            printf("\n");
        }
    }
}



void testeDoisLaco(int m[TAM][TAM]) {
    int soma = 0;
    for (int r = 0; r < REP; r++){
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            soma += m[i][j];
        }
    } 
    }
}


void testeUmLaco(int m[TAM][TAM]) {
    int soma = 0;
    for (int r = 0; r < REP; r++) {
    for (int k = 0; k < TAM * TAM; k++) {
        int i = k / TAM; // linha
        int j = k % TAM; // coluna
        soma += m[i][j];

        
        }
    }
}

int main() {
    int matriz[TAM][TAM];
    clock_t inicio, fim;
    double tempo;

    preencher(matriz);
    exibirDoisLacos(matriz);
    exibirUmLaco(matriz);
    
    inicio = clock();
    testeDoisLaco(matriz);
     fim = clock();
    
    tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
    printf("Tempo (dois lacos): %f s\n", tempo);
    
     inicio = clock();
    testeDoisLaco(matriz);
     fim = clock();
    
     tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
     printf("Tempo (um lacos): %f s\n", tempo);
    

    return 0;
}