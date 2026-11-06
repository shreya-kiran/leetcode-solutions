#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * LeetCode 206: Reverse Linked List
 * Reverses a singly linked list iteratively.
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr) {
        struct ListNode* next = curr->next;  // save the rest of the list
        curr->next = prev;                   // flip the pointer
        prev = curr;                         // advance prev
        curr = next;                         // advance curr
    }

    return prev;  // prev is the new head
}

// Helper function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }
    return head;
}

// Helper function to free a linked list
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d%s", head->val, head->next ? " -> " : "");
        head = head->next;
    }
    printf("]\n");
}

int main() {
    // --- TEST CASE 1 ---
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* head1 = createList(arr1, 5);

    printf("Test Case 1 Input:  ");
    printList(head1);

    struct ListNode* reversed1 = reverseList(head1);

    printf("Test Case 1 Output: ");
    printList(reversed1);
    freeList(reversed1);

    printf("\n");

    // --- TEST CASE 2 ---
    int arr2[] = {1, 2};
    struct ListNode* head2 = createList(arr2, 2);

    printf("Test Case 2 Input:  ");
    printList(head2);

    struct ListNode* reversed2 = reverseList(head2);

    printf("Test Case 2 Output: ");
    printList(reversed2);
    freeList(reversed2);

    return 0;
}