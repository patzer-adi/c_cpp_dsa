#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Enter files as : %s <input_file.txt>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("Error: Cannot open input file '%s'\n", argv[1]);
        return 1;
    }


    int n, M, SP;
    char line[100];

    if (!fgets(line, sizeof(line), in) || sscanf(line, "n %d", &n) != 1) {
        printf("Error: No value of n.\n");
        fclose(in);
        return 1;
    }
    if (n <= 0) {
        printf("Error: Invalid number of items (n <= 0).\n");
        return 1;
    }

    if (!fgets(line, sizeof(line), in) || sscanf(line, "M %d", &M) != 1) {
        printf("Error: No value of M.\n");
        fclose(in);
        return 1;
    }
    if (M <= 0) {
        printf("Error: Invalid knapsack capacity (M <= 0).\n");
        return 1;
    }

    if (!fgets(line, sizeof(line), in) || sscanf(line, "SP %d", &SP) != 1) {
        printf("Error: No value of SP\n");
        fclose(in);
        return 1;
    }
    if (SP <= 0) {
        printf("Error: Invalid selling price (SP <= 0).\n");
        return 1;
    }

    if (!fgets(line, sizeof(line), in)) {
        printf("Error: Missing 'Items' line.\n");
        fclose(in);
        return 1;
    }

    if (!fgets(line, sizeof(line), in)) {
        printf("Error: Missing 'Items' line.\n");
        fclose(in);
        return 1;
    }

    int *weight = malloc(n * sizeof(int));
    int *cost = malloc(n * sizeof(int));
    float *profit = malloc(n * sizeof(float));
    float *pw = malloc(n * sizeof(float));
    if (!weight || !cost || !profit || !pw) {
        printf("Error: Memory allocation failed.\n");
        fclose(in);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(in, "%d %d %f %f", &weight[i], &cost[i], &profit[i], &pw[i]) != 4) {
            printf("Error: Expected %d items, found %d.\n", n, i);
            free(weight); free(cost); free(profit); free(pw);
            fclose(in);
            return 1;
        }
    }
    fclose(in);

    FILE *out = fopen("output.txt", "w");
    if (!out) {
        printf("Error: Cannot create 'output.txt'\n");
        free(weight); free(cost); free(profit); free(pw);
        return 1;
    }

    fprintf(out, "Selected Items (weight, profit):\n");

    int cap = M;
    float totalProfit = 0.0;
    for (int j = 0; j < n && cap > 0; j++) {
        if (weight[j] <= cap) {
            totalProfit += profit[j];
            fprintf(out, "%d %.2f\n", weight[j], profit[j]);
            cap -= weight[j];
        } else {
            float fraction = (float)cap / weight[j];
            float fracProfit = profit[j] * fraction;
            totalProfit += fracProfit;
            fprintf(out, "%d %.2f (Fraction %.2f)\n", cap, fracProfit, fraction);
            cap = 0;
        }
    }

    fprintf(out, "\nTotal Profit: %.2f\n", totalProfit);
    fclose(out);

    printf("Knapsack complete. Output: 'output.txt'\n");
    printf("Total Profit: %.2f\n", totalProfit);

    free(weight); free(cost); free(profit); free(pw);
    return 0;
}
