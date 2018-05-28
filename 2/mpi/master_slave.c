#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int size, rank;
    MPI_Status st;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        int message = 7;
        printf("Total processes: %d\n", size);
        for (int i = 1; i < size; i++) {
            MPI_Send(&message, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } else {
        printf("Hello world from slave rank: %d\n", rank);
        int response;
        MPI_Recv(&response, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &st);
        printf("Message received from master: %d\n", response);
        response = response + rank;
        MPI_Send(&response, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        int report;
        MPI_Recv(&report, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &st);
        printf("Report received from slave: %d", report);
    }

    MPI_Finalize();
}