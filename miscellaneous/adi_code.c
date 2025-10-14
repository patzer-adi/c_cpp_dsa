#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("sorted.txt", "r");
    out = fopen("output.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int n, M, SP;
    fscanf(in, "n %d", &n);
    fscanf(in, "M %d", &M);
    fscanf(in, "SP %d", &SP);

    int weight[50], cost[50];
    float profit[50], pw[50];
    char temp[50];
    fgets(temp, sizeof(temp), in); // skip line
    fgets(temp, sizeof(temp), in); // skip header

    for (int i = 0; i < n; i++) {
        fscanf(in, "%d %d %f %f", &weight[i], &cost[i], &profit[i], &pw[i]);
    }

    int cap = M;
    float totalProfit = 0.0;

    fprintf(out, "Selected Items with weight & profit:\n");

    for (int i = 0; i < n; i++) {
        if (weight[i] <= cap) {
            totalProfit += profit[i];
            cap -= weight[i];
            fprintf(out, "%d %.2f\n", weight[i], profit[i]);
        } else {
            float fraction = (float)cap / weight[i];
            float fracProfit = profit[i] * fraction;
            totalProfit += fracProfit;
            fprintf(out, "%d %.2f (Fraction %.2f)\n", cap, fracProfit, fraction);
            cap = 0;
            break;
        }
    }

    fprintf(out, "\nTotal Profit: %.2f\n", totalProfit);

    fclose(in);
    fclose(out);

    printf("Knapsack complete. Output written to output.txt\n");
    return 0;
}