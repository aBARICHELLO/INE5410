#include "main.h"

int main(int argc, char* argv[]) {
    srand(time(0));
    if (argc == 1) {
        printf("No arguments were given.");
    }

    unsigned int vector_size = atoi(argv[1]);
    printf("%s%d\n", "Vector size: ", vector_size);

    // Generating random vector
    unsigned int* v1 = malloc(4 * sizeof(int));
    printf("%s", "Vector v1 is: ");
    for (unsigned int i = 0; i < vector_size; ++i) {
        v1[i] = rand() % 10; // Random numbers between 0 and 10
        printf("%d ", v1[i]);
    }

    float v1_average = average(v1, vector_size);
    float v1_variance = variance(v1, vector_size);
    printf("%s %f", "\nVector average:", v1_average);
    printf("%s %f", "\nVector variance:", v1_variance);
    printf("\n%s %f", "Vector standard deviation:", standard_deviation(v1_variance));
    return 0;
}

float average(unsigned int* v1, unsigned int vector_size) {
    float average = 0;
    for (unsigned int i = 0; i < vector_size; ++i) {
        average += v1[i];
    }
    return average / vector_size;
}

float variance(unsigned int* v1, unsigned int vector_size) {
    float avrg = average(v1, vector_size);
    float variance = 0;
    for (unsigned int i = 0; i < vector_size; ++i) {
        variance += pow(v1[i] - avrg, 2);
    }
    return variance;
}

float standard_deviation(float variance) {
    return sqrt((float)variance);
}
