## Problem: Best Time to Buy and Sell Stock (Easy)

**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach
Maintained a running minimum price while iterating through daily prices. Calculated potential profit at each step and updated maximum profit whenever `current_price - min_price` exceeded the previously recorded max.

### Complexity
- Time: 1 hour 20 mins

### Notes
Single-pass tracking eliminates the need for $O(N^2)$ nested loop combinations.