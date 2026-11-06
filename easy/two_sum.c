#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int cap = 1;
    while (cap < numsSize * 2) cap <<= 1;
    int mask = cap - 1;

    int* keys = (int*)malloc(cap * sizeof(int));
    int* vals = (int*)malloc(cap * sizeof(int));
    char* used = (char*)calloc(cap, sizeof(char));

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        // Search for complement in hash table
        unsigned int h = ((unsigned int)complement * 2654435761u) & mask;
        while (used[h]) {
            if (keys[h] == complement) {
                result[0] = vals[h];
                result[1] = i;
                free(keys);
                free(vals);
                free(used);
                return result;
            }
            h = (h + 1) & mask;
        }

        // Insert nums[i] -> i
        h = ((unsigned int)nums[i] * 2654435761u) & mask;
        while (used[h]) {
            h = (h + 1) & mask;
        }
        used[h] = 1;
        keys[h] = nums[i];
        vals[h] = i;
    }

    // Problem guarantees a solution, so this is not reached
    free(keys);
    free(vals);
    free(used);
    *returnSize = 0;
    free(result);
    return NULL;
}

int main() {
    int returnSize;

    // --- TEST CASE 1 ---
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int* res1 = twoSum(nums1, 4, target1, &returnSize);

    printf("Test Case 1: ");
    if (res1 != NULL && res1[0] == 0 && res1[1] == 1) {
        printf("PASSED [Output: %d, %d]\n", res1[0], res1[1]);
    } else {
        printf("FAILED\n");
    }
    free(res1);

    // --- TEST CASE 2 ---
    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int* res2 = twoSum(nums2, 3, target2, &returnSize);

    printf("Test Case 2: ");
    if (res2 != NULL && res2[0] == 1 && res2[1] == 2) {
        printf("PASSED [Output: %d, %d]\n", res2[0], res2[1]);
    } else {
        printf("FAILED\n");
    }
    free(res2);

    return 0;
}