## Problem: Move Zeroes (Easy)

**Link:** https://leetcode.com/problems/move-zeroes/

### Approach
Used two pointers (`read` and `write`). Iterated through the array with `read`, swapping non-zero elements into `write` index position to preserve relative order of non-zero numbers while moving zeroes to the back.

### Complexity
- Time: 55 mins

### Notes
Swapping elements directly in-place handles zero placement without a second loop pass to append zeros.