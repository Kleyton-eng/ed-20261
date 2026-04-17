#include <stdio.h>
#include <time.h>



 long int fatorial(int n) {
     int numero = 1;
    for(int i = 1; i <= n; i++) {
        numero = numero * i; 
    }
    return numero;
}

long int fatorialrec(int k){
    if(k == 0) return 0;
    if(k == 1) return 1;
    if(k > 1) return k * fatorialrec(k - 1);
}

int main(){
    int numero = 15;
    int num = 15;

    

     if(numero <=0){
        return 0;
     }
     clock_t tempo_inicial = clock();

     printf("o fatorial(repeticao) de %d e %d\n", numero, fatorial(numero));

     clock_t tempo_final = clock();
     double duracao = (double)(tempo_final - tempo_inicial)/CLOCKS_PER_SEC;

     printf("tempo de duracao do comando do fatorial(repeticao): %.6f\n",duracao);

     tempo_inicial = clock();

     printf("o fatorial(Recursivo) de %d e %d\n", num, fatorialrec(num));

      tempo_final = clock();
     duracao = (double)(tempo_final - tempo_inicial)/CLOCKS_PER_SEC;
      printf("tempo de duracao do comando do fatorial(Recursivo): %.6f\n",duracao);



    return 0;
}