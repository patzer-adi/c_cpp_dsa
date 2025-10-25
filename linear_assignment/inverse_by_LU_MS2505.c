#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUF 1024
#define EPS 1e-12

// Function to print a matrix to a file
void print_matrix(FILE *fp, const char* title, double **mat, int n) {
    fprintf(fp, "%s\n", title);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fprintf(fp, "%12.6f ", mat[i][j]);
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
}

// Swap two rows of a matrix
void swap_rows(double **mat, int r1, int r2, int n) {
    for (int j = 0; j < n; j++) {
        double temp = mat[r1][j];
        mat[r1][j] = mat[r2][j];
        mat[r2][j] = temp;
    }
}

// Function to allocate a square matrix dynamically
double** allocate_matrix(int n) {
    double **mat = (double**) malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        mat[i] = (double*) calloc(n, sizeof(double));
    return mat;
}

// Free dynamically allocated matrix
void free_matrix(double **mat, int n) {
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}

int main() {
    char line[BUF];
    int n = 0;

    printf("Enter first row of the matrix (space-separated):\n");
    if (!fgets(line, sizeof(line), stdin)) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    // Count number of elements in first row
    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        n++;
        token = strtok(NULL, " \t\n");
    }

    if (n == 0) {
        fprintf(stderr, "Invalid matrix\n");
        return 1;
    }

    // Allocate matrices dynamically
    double **A = allocate_matrix(n);
    double **L = allocate_matrix(n);
    double **U = allocate_matrix(n);
    double **Inv = allocate_matrix(n);

    // Re-read first row and store in A
    printf("Enter first row again:\n");
    if (!fgets(line, sizeof(line), stdin)) return 1;
    token = strtok(line, " \t\n");
    for (int j = 0; j < n; j++) {
        A[0][j] = atof(token);
        token = strtok(NULL, " \t\n");
    }

    // Read remaining rows
    for (int i = 1; i < n; i++) {
        printf("Enter row %d:\n", i+1);
        if (!fgets(line, sizeof(line), stdin)) return 1;
        token = strtok(line, " \t\n");
        for (int j = 0; j < n; j++) {
            if (!token) {
                fprintf(stderr, "Row %d incomplete\n", i+1);
                return 1;
            }
            A[i][j] = atof(token);
            token = strtok(NULL, " \t\n");
        }
    }

    // Initialize L and U
    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;
        for (int j = 0; j < n; j++)
            U[i][j] = A[i][j];
    }

    FILE *fp = fopen("LU_steps.txt", "w");
    if (!fp) {
        perror("Cannot open file");
        return 1;
    }

    print_matrix(fp, "Original Matrix:", A, n);

    // LU Decomposition (Gaussian elimination)
    for (int k = 0; k < n; k++) {
        if (fabs(U[k][k]) < EPS) {
            fprintf(stderr, "Zero pivot at row %d\n", k+1);
            fclose(fp);
            return 1;
        }
        for (int i = k+1; i < n; i++) {
            double factor = U[i][k] / U[k][k];
            L[i][k] = factor;
            for (int j = k; j < n; j++)
                U[i][j] -= factor * U[k][j];
        }
    }

    print_matrix(fp, "L Matrix:", L, n);
    print_matrix(fp, "U Matrix:", U, n);

    // Compute inverse
    for (int col = 0; col < n; col++) {
        double *b = (double*) calloc(n, sizeof(double));
        double *y = (double*) calloc(n, sizeof(double));
        double *x = (double*) calloc(n, sizeof(double));

        b[col] = 1.0;

        // Forward substitution Ly = b
        for (int i = 0; i < n; i++) {
            y[i] = b[i];
            for (int j = 0; j < i; j++)
                y[i] -= L[i][j] * y[j];
        }

        // Backward substitution Ux = y
        for (int i = n-1; i >= 0; i--) {
            x[i] = y[i];
            for (int j = i+1; j < n; j++)
                x[i] -= U[i][j] * x[j];
            x[i] /= U[i][i];
        }

        for (int i = 0; i < n; i++)
            Inv[i][col] = x[i];

        free(b); free(y); free(x);
    }

    print_matrix(fp, "Inverse Matrix:", Inv, n);

    fclose(fp);
    free_matrix(A, n);
    free_matrix(L, n);
    free_matrix(U, n);
    free_matrix(Inv, n);

    printf("Computation finished. Check LU_steps.txt for details.\n");
    return 0;
}
