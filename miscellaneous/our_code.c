#include <stdio.h>

int main() {
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

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

    // -------------------- P1 Part: Selection Sort --------------------
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

    // -------------------- P2 Part: Fractional Knapsack --------------------
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

    printf("Integrated process complete. Check output.txt for results.\n");
    return 0;
}