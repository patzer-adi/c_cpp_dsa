#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int N = sizeof(array)/sizeof(array[0]);

    int chunk_size = N / world_size;
    int remainder = N % world_size;

    int local_chunk[chunk_size];
    
    // Scatter array to all processes
    MPI_Scatter(array, chunk_size, MPI_INT, local_chunk, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process computes local sum
    int local_sum = 0;
    for (int i = 0; i < chunk_size; i++) {
        local_sum += local_chunk[i];
    }

    // Rank 0 handles remaining elements (if N % world_size != 0)
    if (world_rank == 0) {
        for (int i = chunk_size * world_size; i < N; i++) {
            local_sum += array[i];
        }
    }

    // Reduce all local sums to a total sum at rank 0
    int total_sum = 0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        printf("Total sum of array: %d\n", total_sum);
    }

    MPI_Finalize();
    return 0;
}
