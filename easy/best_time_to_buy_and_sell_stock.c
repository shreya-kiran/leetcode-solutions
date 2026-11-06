#include <stdio.h>

/**
 * LeetCode 121: Best Time to Buy and Sell Stock
 * Finds the maximum profit achievable from a single buy-and-sell transaction.
 */
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main() {
    // --- TEST CASE 1 (Profitable Trade) ---
    // Buy at 1 (day 2), sell at 6 (day 5), profit = 6 - 1 = 5
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    int expected1 = 5;
    int res1 = maxProfit(prices1, size1);

    printf("Test Case 1: ");
    if (res1 == expected1) {
        printf("PASSED [Max Profit: %d]\n", res1);
    } else {
        printf("FAILED [Expected: %d, Got: %d]\n", expected1, res1);
    }

    // --- TEST CASE 2 (No Profitable Trade) ---
    // Prices continuously fall, no transaction done, max profit = 0
    int prices2[] = {7, 6, 4, 3, 1};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    int expected2 = 0;
    int res2 = maxProfit(prices2, size2);

    printf("Test Case 2: ");
    if (res2 == expected2) {
        printf("PASSED [Max Profit: %d]\n", res2);
    } else {
        printf("FAILED [Expected: %d, Got: %d]\n", expected2, res2);
    }

    return 0;
}