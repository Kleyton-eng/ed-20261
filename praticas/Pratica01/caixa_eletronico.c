#include <stdio.h>
     void calcular_notas(int valor){
        int notas200, notas100, notas50, notas20, notas10, notas5, notas2;

        notas200= valor /200
        valor %= 200

        notas200= valor /100
        valor %= 100

        notas200= valor /50
        valor %= 50

        notas200= valor /20
        valor %= 20

        notas200= valor /10
        valor %= 10

        notas200= valor /5
        valor %= 5

        notas200= valor /2
        valor %= 2

        printf("\nQuantidade de notas:\n");
        printf("200: %d\n", notas200);
        printf("100: %d\n", notas100);
        printf("50: %d\n", notas50);
        printf("20: %d\n", notas20);
        printf("10: %d\n", notas10);
        printf("5: %d\n", notas5);
        printf("2: %d\n", notas2);

        if(valor !=0){
            printf("Valor que não pode ser sacado: %d", valor);
        }
     }

int main()[
    int saque;

    printf("digite o valor do saque (maximo 1000): ");
    scanf("%d", &saque);

    if(saque <= 0 || saque > 1000){
        printf("Valor invalido\n");
    }else{
        calcular_notas(saque);
    }

    return 0;
]