#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int N;          // Array size
    int *array = NULL;

    // Only rank 0 takes input
    if (world_rank == 0) {
        printf("Enter the number of elements: ");
        fflush(stdout);  // Ensure prompt is displayed immediately
        scanf("%d", &N);

        array = (int*)malloc(N * sizeof(int));
        printf("Enter %d integers: ", N);
        fflush(stdout);  // Ensure prompt is displayed immediately
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }
    }

    // Broadcast the size of the array to all processes
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Determine chunk size for each process
    int chunk_size = N / world_size;
    int remainder = N % world_size;

    // Allocate space for each process's local chunk
    int *local_chunk = (int*)malloc(chunk_size * sizeof(int));

    // Scatter array to all processes
    MPI_Scatter(array, chunk_size, MPI_INT, local_chunk, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process calculates its local sum
    int local_sum = 0;
    for (int i = 0; i < chunk_size; i++) {
        local_sum += local_chunk[i];
    }

    // Rank 0 handles remaining elements if N % world_size != 0
    if (world_rank == 0) {
        for (int i = chunk_size * world_size; i < N; i++) {
            local_sum += array[i];
        }
    }

    // Reduce all local sums to a total sum in rank 0
    int total_sum = 0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        printf("Total sum of the array: %d\n", total_sum);
    }

    free(local_chunk);
    if (world_rank == 0) free(array);

    MPI_Finalize();
    return 0;
}
