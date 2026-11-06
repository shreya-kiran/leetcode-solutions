#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * LeetCode 14: Longest Common Prefix
 * Finds the longest common prefix string amongst an array of strings.
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int i = 0;
    while (strs[0][i]) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            // Mismatch, or strs[j] ended (its '\0' never equals c)
            if (strs[j][i] != c) {
                goto done;
            }
        }
        i++;
    }

done:;
    char* result = (char*)malloc(i + 1);
    memcpy(result, strs[0], i);
    result[i] = '\0';
    return result;
}

int main() {
    // --- TEST CASE 1 (Common Prefix Exists) ---
    char* strs1[] = {"flower", "flow", "flight"};
    int size1 = 3;
    char* res1 = longestCommonPrefix(strs1, size1);

    printf("Test Case 1: ");
    if (res1 != NULL && strcmp(res1, "fl") == 0) {
        printf("PASSED [Prefix: \"%s\"]\n", res1);
    } else {
        printf("FAILED [Got: \"%s\", Expected: \"fl\"]\n", res1 ? res1 : "NULL");
    }
    free(res1);

    // --- TEST CASE 2 (No Common Prefix) ---
    char* strs2[] = {"dog", "racecar", "car"};
    int size2 = 3;
    char* res2 = longestCommonPrefix(strs2, size2);

    printf("Test Case 2: ");
    if (res2 != NULL && strcmp(res2, "") == 0) {
        printf("PASSED [Prefix: \"\"]\n");
    } else {
        printf("FAILED [Got: \"%s\", Expected: \"\"]\n", res2 ? res2 : "NULL");
    }
    free(res2);

    return 0;
}