#include <stdio.h>
#include <stdlib.h>
// this was done along with the help of abdulla sir

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2 * numsSize;

    int *ans = (int*)malloc(sizeof(int) * (*returnSize));
    if (ans == NULL) {
        printf("Error allocating memory...\n");
        return NULL;
    }

    for (int i = 0; i < numsSize; ++i) {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];  
    }

    return ans;
}

// --- Testing ---
int main() {
    int nums[] = {1, 2, 3};
    int numsSize = 3;
    int returnSize;

    int* result = getConcatenation(nums, numsSize, &returnSize);

    printf("Concatenated Array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); 
    return 0;
}
