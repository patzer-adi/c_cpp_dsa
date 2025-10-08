#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N;
    int *array = NULL;

    // Only rank 0 reads input
    if (rank == 0) {
        printf("Enter the number of elements: ");
        fflush(stdout);
        scanf("%d", &N);

        array = (int*)malloc(N * sizeof(int));
        printf("Enter %d integers: ", N);
        fflush(stdout);
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }
    }

    // Broadcast array size to all processes
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Determine counts and displacements for each process
    int *counts = (int*)malloc(size * sizeof(int));
    int *displs = (int*)malloc(size * sizeof(int));
    int base = N / size;
    int rem = N % size;
    for (int i = 0; i < size; i++) {
        counts[i] = base + (i < rem ? 1 : 0);
        displs[i] = (i == 0) ? 0 : displs[i-1] + counts[i-1];
    }

    // Allocate local chunk
    int local_size = counts[rank];
    int *local_chunk = (int*)malloc(local_size * sizeof(int));

    // Scatter variable-sized chunks
    MPI_Scatterv(array, counts, displs, MPI_INT, local_chunk, local_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process computes local sum
    int local_sum = 0;
    for (int i = 0; i < local_size; i++) {
        local_sum += local_chunk[i];
    }

    // Reduce local sums to total sum
    int total_sum = 0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Total sum of array: %d\n", total_sum);
        free(array);
    }

    free(local_chunk);
    free(counts);
    free(displs);

    MPI_Finalize();
    return 0;
}
