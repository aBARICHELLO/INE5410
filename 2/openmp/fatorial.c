#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long fat(int n) {
    long res;
    int i;
    res = 1;

    #pragma omp parallel for reduction(*:res)
    for(i = 2; i <= n; i++){
       res *= i;
    }
    return res;
}

int main(int argc, char **argv) {
    int n;
    long resultado;
    if(argc < 2){
        printf("uso ./fatorial <numero natural>\n");
        exit(1);
    }
    n = atoi(argv[1]);
    if(n < 0){
        printf("Erro! Numero de entrada não é natural\n");
        exit(1);
    }
    // omp_set_num_threads(1);

    printf("Calculando fatorial de %d com %d threads.\n", n, omp_get_max_threads());

    resultado = fat(n);
    printf("fatorial(%d) = %ld\n", n, resultado);

    return 0;
}
