#include <stdio.h>
#include <string.h>

/**
 * LeetCode 344: Reverse String
 * Reverses an array of characters in-place with O(1) extra memory.
 */
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;

    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

int main() {
    // --- TEST CASE 1 ---
    char tc1[] = {'h', 'e', 'l', 'l', 'o'};
    int size1 = 5;
    char expected1[] = {'o', 'l', 'l', 'e', 'h'};

    reverseString(tc1, size1);

    printf("Test Case 1: ");
    if (memcmp(tc1, expected1, size1) == 0) {
        printf("PASSED [Output: ");
        for (int i = 0; i < size1; i++) printf("%c", tc1[i]);
        printf("]\n");
    } else {
        printf("FAILED\n");
    }

    // --- TEST CASE 2 ---
    char tc2[] = {'H', 'a', 'n', 'n', 'a', 'h'};
    int size2 = 6;
    char expected2[] = {'h', 'a', 'n', 'n', 'a', 'H'};

    reverseString(tc2, size2);

    printf("Test Case 2: ");
    if (memcmp(tc2, expected2, size2) == 0) {
        printf("PASSED [Output: ");
        for (int i = 0; i < size2; i++) printf("%c", tc2[i]);
        printf("]\n");
    } else {
        printf("FAILED\n");
    }

    return 0;
}