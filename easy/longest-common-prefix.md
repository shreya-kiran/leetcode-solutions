## Problem: Longest Common Prefix (Easy)

**Link:** https://leetcode.com/problems/longest-common-prefix/

### Approach
Used horizontal character-by-character comparison across all input strings using the first string as a benchmark. Stopped matching as soon as a mismatch occurred or any string ended.

### Complexity
- Time: 56 mins

### Notes
A `goto` or early return simplifies exiting nested character comparison loops cleanly.