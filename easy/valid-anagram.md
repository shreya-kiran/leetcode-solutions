## Problem: Valid Anagram (Easy)

**Link:** https://leetcode.com/problems/valid-anagram/

### Approach
Used a fixed-size frequency array of length 26 to count frequencies of lowercase English letters. Incremented frequencies for string `s` and decremented for string `t`, verifying all counts net to zero.

### Complexity
- Time: 35 mins

### Notes
Checking length mismatch early avoids unnecessary loop iterations.