## Problem: Reverse Linked List (Easy)

**Link:** https://leetcode.com/problems/reverse-linked-list/

### Approach
Iteratively reversed linked list pointers using `prev`, `curr`, and `next` pointers. Updated `curr->next` to point to `prev` as we traversed forward through the nodes.

### Complexity
- Time: 30 mins

### Notes
Saving `curr->next` before reassigning pointers avoids losing reference to the rest of the list.