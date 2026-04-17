#include <stdio.h>
#include <stdlib.h>
#include "selecao.h"

#define TAMANHO 10

int busca_sequencial(int v[], int n, int valor){
    for(int i = 0; i < n; i++){
        if(v[i] == valor){
            return i;
        }
    }
    return -1;
}

return 0;