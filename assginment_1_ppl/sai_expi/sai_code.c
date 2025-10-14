#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Enter files as : %s <input_file.txt>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("Error: Cannot open '%s'\n", argv[1]);
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
        if (fscanf(in, "%d %d", &weight[i], &cost[i]) != 2) {
            printf("Error: Expected %d items, found %d.\n", n, i);
            free(weight); free(cost); free(profit); free(pw);
            fclose(in);
            return 1;
        }
        profit[i] = SP - cost[i];
        pw[i] = profit[i] / weight[i];
    }
    fclose(in);

    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (pw[j] > pw[max])
                max = j;
        }
        if (max != i) {
            float tempF = pw[i]; pw[i] = pw[max]; pw[max] = tempF;
            tempF = profit[i]; profit[i] = profit[max]; profit[max] = tempF;
            int tempI = weight[i]; weight[i] = weight[max]; weight[max] = tempI;
            tempI = cost[i]; cost[i] = cost[max]; cost[max] = tempI;
        }
    }

    FILE *out = fopen("sorted.txt", "w");
    if (!out) {
        printf("Error: Cannot create 'sorted.txt'\n");
        free(weight); free(cost); free(profit); free(pw);
        return 1;
    }

    fprintf(out, "n %d\nM %d\nSP %d\nItems (Sorted by profit/weight):\n", n, M, SP);
    for (int i = 0; i < n; i++)
        fprintf(out, "%d %d %.2f %.3f\n", weight[i], cost[i], profit[i], pw[i]);
    fclose(out);

    printf("Sorting complete. Output: 'sorted.txt'\n");

    free(weight); free(cost); free(profit); free(pw);
    return 0;
}
