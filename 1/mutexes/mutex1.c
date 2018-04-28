#include "mutex1.h"

int contador_global = 0;
pthread_mutex_t mutex;

void* thread_function(void* argv) {
    int num_threads = *((int *)argv);
    for (int i = 0; i < num_threads * 1000; ++i) {
        pthread_mutex_lock(&mutex);
        contador_global++;
        pthread_mutex_unlock(&mutex);
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
