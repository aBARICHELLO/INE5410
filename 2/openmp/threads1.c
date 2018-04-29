#include <stdio.h>
#include <omp.h>

void* thread_function();
int contador_global = 0;

int main(int argc, char* argv[]) {
    unsigned int num_threads = omp_get_thread_num();
    if (argc >= 2) {
        num_threads = atoi(argv[1]);
    }
    printf("Executing with %d threads.\n", num_threads);

    #pragma omp parallel for
    for (unsigned int i = 0; i < num_threads; ++i) {
        thread_function(num_threads);
    }

    #pragma omp single
    printf("%d", contador_global);
    return 0;
}

void* thread_function(unsigned int num_threads) {
    for (int i = 0; i < num_threads * 1000; ++i) {
        #pragma omp critical
        contador_global++;
    }
}
