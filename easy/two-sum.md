## Problem: Two Sum (Easy)

**Link:** https://leetcode.com/problems/two-sum/

### Approach
Used a custom hash map (hash table with linear probing) to store numbers and their indices while iterating through the array. For each number, we look up its complement (`target - nums[i]`) in $O(1)$ average time.

### Complexity
- Time: 48 mins

### Notes
Using dynamic memory allocation (`malloc`/`calloc`) and custom hashing in C allows optimal time efficiency similar to C++ `unordered_map`.