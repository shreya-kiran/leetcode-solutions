#include <stdio.h>
#include <stdbool.h>

/**
 * LeetCode 242: Valid Anagram
 * Determines if string 't' is an anagram of string 's'.
 */
bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    int i = 0;

    // Walk both strings together
    while (s[i] && t[i]) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
        i++;
    }

    // If either string has leftover characters, the lengths differ
    if (s[i] || t[i]) return false;

    for (int k = 0; k < 26; k++) {
        if (count[k] != 0) return false;
    }
    return true;
}

int main() {
    // --- TEST CASE 1 (Valid Anagram) ---
    char s1[] = "anagram";
    char t1[] = "nagaram";
    bool res1 = isAnagram(s1, t1);

    printf("Test Case 1: ");
    if (res1 == true) {
        printf("PASSED [Output: true]\n");
    } else {
        printf("FAILED [Output: false]\n");
    }

    // --- TEST CASE 2 (Invalid Anagram) ---
    char s2[] = "rat";
    char t2[] = "car";
    bool res2 = isAnagram(s2, t2);

    printf("Test Case 2: ");
    if (res2 == false) {
        printf("PASSED [Output: false]\n");
    } else {
        printf("FAILED [Output: true]\n");
    }

    return 0;
}