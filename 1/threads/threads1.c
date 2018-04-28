#include "threads1.h"

int contador_global = 0;

void* thread_function(void* argv) {
    int num_threads = *((int *)argv);
    for (int i = 0; i < num_threads * 1000; ++i) {
        contador_global++;
    }
}

int main(int argc, char* argv[]) {
    int num_threads;
    if (argc < 2) {
        printf("Not enough arguments");
        return -1;
    }
    num_threads = atoi(argv[1]);
    printf("%d", num_threads);

    pthread_t threads[num_threads];
    for (uint i = 0; i < num_threads; ++i) {
        pthread_create(&threads[i], NULL, thread_function, &num_threads);
    }

    for (uint i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }
    printf("%d", contador_global);
    return 0;
}
