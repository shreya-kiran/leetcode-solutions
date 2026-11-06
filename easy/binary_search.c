#include <stdio.h>

/**
 * LeetCode 704: Binary Search
 * Searches for target in an array of sorted integers in O(log n) time.
 * Returns the index if target is found, otherwise -1.
 */
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    // --- TEST CASE 1 (Target exists in array) ---
    int nums1[] = {-1, 0, 3, 5, 9, 12};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 9;
    int expected1 = 4;
    int res1 = search(nums1, size1, target1);

    printf("Test Case 1: ");
    if (res1 == expected1) {
        printf("PASSED [Found %d at index %d]\n", target1, res1);
    } else {
        printf("FAILED [Expected index %d, Got %d]\n", expected1, res1);
    }

    // --- TEST CASE 2 (Target does not exist) ---
    int nums2[] = {-1, 0, 3, 5, 9, 12};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int target2 = 2;
    int expected2 = -1;
    int res2 = search(nums2, size2, target2);

    printf("Test Case 2: ");
    if (res2 == expected2) {
        printf("PASSED [Target %d not found, output: -1]\n", target2);
    } else {
        printf("FAILED [Expected -1, Got %d]\n", res2);
    }

    return 0;
}