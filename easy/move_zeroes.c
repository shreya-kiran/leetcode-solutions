#include <stdio.h>
#include <string.h>

/**
 * LeetCode 283: Move Zeroes
 * Moves all 0's to the end of an array while maintaining non-zero element order in-place.
 */
void moveZeroes(int* nums, int numsSize) {
    int write = 0;

    for (int read = 0; read < numsSize; read++) {
        if (nums[read] != 0) {
            if (read != write) {
                int tmp = nums[write];
                nums[write] = nums[read];
                nums[read] = tmp;
            }
            write++;
        }
    }
}

int main() {
    // --- TEST CASE 1 (Mixed array) ---
    int nums1[] = {0, 1, 0, 3, 12};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int expected1[] = {1, 3, 12, 0, 0};

    moveZeroes(nums1, size1);

    printf("Test Case 1: ");
    if (memcmp(nums1, expected1, sizeof(expected1)) == 0) {
        printf("PASSED [Output: ");
        for (int i = 0; i < size1; i++) printf("%d ", nums1[i]);
        printf("]\n");
    } else {
        printf("FAILED\n");
    }

    // --- TEST CASE 2 (Single zero or no zeroes shift required) ---
    int nums2[] = {0, 0, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int expected2[] = {1, 0, 0};

    moveZeroes(nums2, size2);

    printf("Test Case 2: ");
    if (memcmp(nums2, expected2, sizeof(expected2)) == 0) {
        printf("PASSED [Output: ");
        for (int i = 0; i < size2; i++) printf("%d ", nums2[i]);
        printf("]\n");
    } else {
        printf("FAILED\n");
    }

    return 0;
}