#include <stdio.h>

float media_aritmetica(int n, float valores[]){
    if(n <= 0 || n > 100){
        return 0.0f;
    }

    float soma = 0.0f;

    for(int i = 0; i < n; i++){
        soma += valores[i];
    }

    return soma / n;
}

int main(){

    float m = 0.0f;

    float v1[] = {10, 20, 30};
    m = media_aritmetica(3, v1);
    printf("n = 3, media = %.2f => %i\n", m, m == 20.0f);

    float v2[] = {5, 5, 5, 5};
    m = media_aritmetica(4, v2);
    printf("n = 4, media = %.2f => %i\n", m, m == 5.0f);

    float v3[] = {1, 2, 3, 4, 5};
    m = media_aritmetica(5, v3);
    printf("n = 5, media = %.2f => %i\n", m, m == 3.0f);

    float v4[] = {0};
    m = media_aritmetica(0, v4);
    printf("n = 0, media = %.2f => %i\n", m, m == 0.0f);

    float v5[] = {100, 200};
    m = media_aritmetica(101, v5);
    printf("n = 101, media = %.2f => %i\n", m, m == 0.0f);

    return 0;
}