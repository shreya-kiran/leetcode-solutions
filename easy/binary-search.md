## Problem: Binary Search (Easy)

**Link:** https://leetcode.com/problems/binary-search/

### Approach
Used standard binary search with `left` and `right` pointers on a sorted array. Computed `mid = left + (right - left) / 2` to prevent potential integer overflow while narrowing search bounds.

### Complexity
- Time: 48 mins

### Notes
Computing `mid` using `left + (right - left) / 2` avoids potential `(left + right)` integer overflow errors in C.