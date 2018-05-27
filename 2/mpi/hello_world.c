#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int size, rank;
    MPI_Status st;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int buffer[2] = {1, 2};

    if (rank == 0) {
        printf("Total processes: %d\n", size);
        for (int i = 1; i < size; i++) {
            MPI_Send(&buffer, 2, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        printf("Hello world from process rank: %d\n", rank);
        MPI_Recv(&buffer, 2, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &st);
        printf("%d", buffer[0]);
        printf("%d", buffer[1]);
    }

    MPI_Finalize();
}