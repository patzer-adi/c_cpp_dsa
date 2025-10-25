#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUF 1024
#define EPS 1e-12


// allocate a matrix
double **alloc_mat(int n)
{
    double **mat = (double **) malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        mat[i] = (double *) calloc(n, sizeof(double));
    return mat;
}//end



//free func
void free_mat(double **mat, int n)
{
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}//end



// Display on terminal
void display_mat(const char *title, double **mat, int n)
{
    printf("%s\n", title);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%12.6f ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}//end



// Save matrix in file
void save_mat_in_file(FILE *fp, const char *title, double **mat, int n)
{
    fprintf(fp, "%s\n", title);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fprintf(fp, "%12.6f ", mat[i][j]);
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
}//end



int main()
{
    char line[BUF];
    int n = 0;

    printf("Enter first row of the matrix (space-separated):\n");
    if (!fgets(line, sizeof(line), stdin))
    {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    // tokenizaition
    char *token = strtok(line, " \t\n");
    double *first_row = (double *) malloc(BUF * sizeof(double));
    int idx = 0;
    while (token != NULL)
    {
        first_row[idx++] = atof(token);
        token = strtok(NULL, " \t\n");
    }
    n = idx;

    // allocate matrices in function
    double **A = alloc_mat(n);
    double **L = alloc_mat(n);
    double **U = alloc_mat(n);
    double **Inv = alloc_mat(n);

    // first row
    for (int j = 0; j < n; j++)
        A[0][j] = first_row[j];
    free(first_row);

    for (int i = 1; i < n; i++)
    {
        printf("Enter row %d:\n", i + 1);
        if (!fgets(line, sizeof(line), stdin)) return 1;
        token = strtok(line, " \t\n");
        for (int j = 0; j < n; j++)
        {
            if (!token)
            {
                fprintf(stderr, "Row %d incomplete\n", i + 1);
                return 1;
            }
            A[i][j] = atof(token);
            token = strtok(NULL, " \t\n");
        }
    }

    for (int i = 0; i < n; i++)
    {
        L[i][i] = 1.0;
        for (int j = 0; j < n; j++)
            U[i][j] = A[i][j];
    }

    //create file...
    FILE *fp = fopen("row_operations_summary.txt", "w");
    if (!fp)
    {
        perror("Cannot open row_operations_summary.txt");
        return 1;
    }


    for (int k = 0; k < n; k++)
    {
        if (fabs(U[k][k]) < EPS) // floating point absolute
        {
            fprintf(stderr, "Zero pivot at row %d\n", k + 1); //division by zero happens
            fclose(fp);
            return 1;
        }
        for (int i = k + 1; i < n; i++)
        {
            double factor = U[i][k] / U[k][k];
            L[i][k] = factor;
            fprintf(fp, "R%d = R%d - %.6f * R%d\n", i + 1, i + 1, factor, k + 1);

            for (int j = k; j < n; j++)
                U[i][j] -= factor * U[k][j];
        }
        save_mat_in_file(fp, "Matrix U after this step:", U, n);
    }

    // print matrices on terminal
    display_mat("Original Matrix A:", A, n);
    display_mat("L Matrix:", L, n);
    display_mat("U Matrix:", U, n);


    // using A^-1
    for (int col = 0; col < n; col++)
    {
        double *b = (double *) calloc(n, sizeof(double));
        double *y = (double *) calloc(n, sizeof(double));
        double *x = (double *) calloc(n, sizeof(double));

        b[col] = 1.0;

        // forward substitution Ly = b
        for (int i = 0; i < n; i++)
        {
            y[i] = b[i];
            for (int j = 0; j < i; j++)
                y[i] -= L[i][j] * y[j];
        }

        // backward substitution Ux = y
        for (int i = n - 1; i >= 0; i--)
        {
            x[i] = y[i];
            for (int j = i + 1; j < n; j++)
                x[i] -= U[i][j] * x[j];
            x[i] /= U[i][i];
        }

        for (int i = 0; i < n; i++)
            Inv[i][col] = x[i];

        free(b);
        free(y);
        free(x);
    }

    display_mat("Inverse Matrix A^-1:", Inv, n);

    // Save L, U and Inverse matrices in file
    save_mat_in_file(fp, "L Matrix:", L, n);
    save_mat_in_file(fp, "U Matrix:", U, n);
    save_mat_in_file(fp, "Inverse Matrix A^-1:", Inv, n);

    fclose(fp);
    free_mat(A, n);
    free_mat(L, n);
    free_mat(U, n);
    free_mat(Inv, n);

    printf("\nSaving Row operations perfromed in row_operations_summary.txt file\n");
    return 0;
}
