#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * LeetCode 20: Valid Parentheses
 * Determines if an input string of brackets is valid using a stack.
 */
bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 != 0) return false;   // odd length can never be balanced

    char* stack = (char*)malloc(n);
    int top = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[top++] = c;
        } else {
            if (top == 0) {          // closer with nothing to match
                free(stack);
                return false;
            }
            char open = stack[--top];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool ok = (top == 0);            // leftover openers mean invalid
    free(stack);
    return ok;
}

int main() {
    // --- TEST CASE 1 (Valid mixed brackets) ---
    char s1[] = "()[]{}";
    bool res1 = isValid(s1);

    printf("Test Case 1: ");
    if (res1 == true) {
        printf("PASSED [Output: true]\n");
    } else {
        printf("FAILED [Output: false]\n");
    }

    // --- TEST CASE 2 (Mismatched brackets) ---
    char s2[] = "(]";
    bool res2 = isValid(s2);

    printf("Test Case 2: ");
    if (res2 == false) {
        printf("PASSED [Output: false]\n");
    } else {
        printf("FAILED [Output: true]\n");
    }

    return 0;
}
