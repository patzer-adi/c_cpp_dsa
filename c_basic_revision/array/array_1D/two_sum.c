#include <stdio.h>

// Function to find two indices whose values add up to target
// It will print the indices when found
void twoSum(int nums[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                return; // exit after finding one valid pair
            }
        }
    }
    printf("No solution found\n");
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(nums) / sizeof(nums[0]);

    twoSum(nums, n, target);

    return 0;
}
