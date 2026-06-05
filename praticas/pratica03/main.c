#include <stdio.h>
#include <math.h>
#include "conta.h"

int main() {
    Conta* c = conta_criar(123);

    conta_depositar(c, 500.0);
    conta_depositar(c, 150.0);

    float saldo = conta_ver_saldo(c);

    printf("Saldo atual: 500\n");
    printf("Deposito de 150\n");
    printf("Teste deposito: saldo = %.2f -> %s\n",
           saldo,
           (fabs(saldo - 650.0) < 0.001) ? "PASSOU" : "FALHOU");

    if (conta_sacar(c, 200.0)) {
        saldo = conta_ver_saldo(c);

        printf("Saque de 200\n");
        printf("Teste saque: saldo = %.2f -> %s\n",
               saldo,
               (fabs(saldo - 450.0) < 0.001) ? "PASSOU" : "FALHOU");
    } else {
        printf("Teste saque: FALHOU (nao conseguiu sacar)\n");
    }

    conta_destruir(c);
    return 0;
}