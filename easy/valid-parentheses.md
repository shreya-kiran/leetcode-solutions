## Problem: Valid Parentheses (Easy)

**Link:** https://leetcode.com/problems/valid-parentheses/

### Approach
Implemented an array-backed stack to track opening brackets. When encountering a closing bracket, popped top opening bracket from stack and verified matching pairs.

### Complexity
- Time: 1 hour 21 mins

### Notes
Odd string length can immediately return `false` before stack allocation.