## Problem: Reverse String (Easy)

**Link:** https://leetcode.com/problems/reverse-string/

### Approach
Used a two-pointer approach starting at opposite ends of the character array (`left` at index 0, `right` at index `sSize - 1`). Swapped characters in-place while moving towards the center until `left >= right`.

### Complexity
- Time: 13 mins

### Notes
In-place swapping avoids allocating additional string memory.
