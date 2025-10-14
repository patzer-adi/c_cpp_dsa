#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("sorted.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int n, M, SP;
    fscanf(in, "n %d", &n);
    fscanf(in, " M %d", &M);
    fscanf(in, " SP %d", &SP);

    int weight[50], cost[50];
    float profit[50], pw[50];

    fscanf(in, " Items");
    for (int i = 0; i < n; i++) {
        fscanf(in, "%d %d", &weight[i], &cost[i]);
        profit[i] = SP - cost[i];
        pw[i] = profit[i] / weight[i];
    }

    // Selection sort on profit/weight
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (pw[j] > pw[max])
                max = j;
        }
        if (max != i) {
            float t1 = pw[i]; pw[i] = pw[max]; pw[max] = t1;
            float t2 = profit[i]; profit[i] = profit[max]; profit[max] = t2;
            int t3 = weight[i]; weight[i] = weight[max]; weight[max] = t3;
            int t4 = cost[i]; cost[i] = cost[max]; cost[max] = t4;
        }
    }

    fprintf(out, "n %d\n", n);
    fprintf(out, "M %d\n", M);
    fprintf(out, "SP %d\n", SP);
    fprintf(out, "Items (Sorted by profit/weight):\n");

    for (int i = 0; i < n; i++) {
        fprintf(out, "%d %d %.2f %.2f\n", weight[i], cost[i], profit[i], pw[i]);
    }

    fclose(in);
    fclose(out);

    printf("Sorting done. Output written to sorted.txt\n");
    return 0;
}