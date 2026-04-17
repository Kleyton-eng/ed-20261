#include <stdio.h>

int potencia(int base, int expoente){
    if((expoente==0 && base==0) || (expoente<0)){
        return 0;
    }

    int resultado = 1;
    
    for(int i = 0; i < expoente; i++){
        resultado *= base;
    }
    return resultado;
}

int main(){

    int resultado = 0;

    resultado = potencia(0, 2);
    printf("Base = 0, Expoente = 2, resultado = %d => %i\n", resultado, resultado == 0);
    
    resultado = potencia(2, -4);
    printf("Base = 2, Expoente = -4, resultado = %d => %i\n", resultado, resultado == 0);

    resultado = potencia(2, 0);
    printf("Base = 2, Expoente = 0, resultado = %d => %i\n", resultado, resultado == 1);

    resultado = potencia(2, 3);
    printf("Base = 2, Expoente = 3, resultado = %d => %i\n", resultado, resultado == 8);

    resultado = potencia(2, 4);
    printf("Base = 2, Expoente = 4, resultado = %d => %i\n", resultado, resultado == 16);

    resultado = potencia(2, 5);
    printf("Base = 2, Expoente = 5, resultado = %d => %i\n", resultado, resultado == 32);

    resultado = potencia(10, 1);
    printf("Base = 10, Expoente = 1, resultado = %d => %i\n", resultado, resultado == 10);

    resultado = potencia(7, 2);
    printf("Base = 7, Expoente = 2, resultado = %d => %i\n", resultado, resultado == 49);

    return 0;
}