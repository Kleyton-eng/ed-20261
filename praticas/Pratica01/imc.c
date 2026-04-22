#include <stdio.h>

float calculo_imc(float A, float P){
    if(A <= 0.0f || P <= 0.0f){
        return 0.0f;
    }
    return P/(A*A);
}

    int main(){
    
        float imc = 0.0f;
    
        imc = calculo_imc(0.0f, 45.0f);
        printf("A = 0, P = 45, imc = %.1f => %i\n", imc, imc == 0);
    
        imc = calculo_imc(1.73f, 0.0f);
        printf("A = 1.73, P = 0, imc = %.2f => %i\n", imc, imc == 0.0f);
    
        imc = calculo_imc(1.73f, 55.0f);
        printf("A = 1.73, P = 55, imc = %.2f => %i\n", imc, imc < 18.5f);
    
        imc = calculo_imc(1.73f, 65.0f);
        printf("A = 1.73, P = 65, imc = %.2f => %i\n", imc, imc >= 18.5f && imc <= 24.9f);
    
        imc = calculo_imc(1.73f, 75.0f);
        printf("A = 1.73, P = 75, imc = %.2f => %i\n", imc, imc >= 25.0f && imc <= 29.9f);
    
        imc = calculo_imc(1.73f, 95.0f);
        printf("A = 1.73, P = 95, imc = %.2f => %i\n", imc, imc >= 30.0f);

    return 0;
}