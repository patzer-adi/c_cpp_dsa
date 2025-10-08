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

        // Send chunks to other processes
        int base = N / size;
        int rem = N % size;
        int offset = base + rem; // rank 0 keeps extra if any

        for (int i = 1; i < size; i++) {
            int count = base + (i <= rem ? 1 : 0);
            MPI_Send(&array[offset], count, MPI_INT, i, 0, MPI_COMM_WORLD);
            offset += count;
        }
    } else {
        // Non-zero ranks receive their chunks
        MPI_Status status;
        int base = 0; // placeholder
        int rem = 0;  // placeholder
        MPI_Recv(&N, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // optional send of N
    }

    // Determine local size for each process
    int base = N / size;
    int rem = N % size;
    int local_size = (rank == 0) ? base + rem : base;
    int *local_chunk = (int*)malloc(local_size * sizeof(int));

    // Rank 0 copies its own chunk
    if (rank == 0) {
        for (int i = 0; i < local_size; i++) {
            local_chunk[i] = array[i];
        }
    } else {
        MPI_Recv(local_chunk, local_size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Compute local sum
    int local_sum = 0;
    for (int i = 0; i < local_size; i++) {
        local_sum += local_chunk[i];
    }

    printf("Process %d: Local sum = %d\n", rank, local_sum);

    // Send local sums back to rank 0
    if (rank != 0) {
        MPI_Send(&local_sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    } else {
        int total_sum = local_sum;
        int temp;
        for (int i = 1; i < size; i++) {
            MPI_Recv(&temp, 1, MPI_INT, i, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_sum += temp;
        }
        printf("Total sum of array = %d\n", total_sum);
    }

    free(local_chunk);
    if (rank == 0) free(array);

    MPI_Finalize();
    return 0;
}
