/**
 * Problem: Linked List Cycle
 * LeetCode Link: https://leetcode.com/problems/linked-list-cycle/
 * Description: Given head, the head of a linked list, determine if the linked list has a cycle in it.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for ListNode");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

/**
 * Note: The LeetCode function signature for this problem is:
 * bool hasCycle(struct ListNode *head)
 */
bool hasCycle(struct ListNode *head) {
    // Use the slow and fast pointer technique (Floyd's Cycle-Finding Algorithm)
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If the pointers meet, there is a cycle
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches the end (NULL), there is no cycle
    return false;
}

// Helper function to free the list memory (only for non-cyclic lists)
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

// Example usage
int main() {
    // List 1 (Cycle): 3 -> 2 -> 0 -> -4 -> (points back to 2)
    struct ListNode* head1 = createNode(3);
    head1->next = createNode(2);
    head1->next->next = createNode(0);
    head1->next->next->next = createNode(-4);
    head1->next->next->next->next = head1->next; // Cycle: -4 points to 2

    printf("List 1 has cycle: %s (Expected: true)\n", hasCycle(head1) ? "true" : "false");

    // Clean up the cycle manually to avoid infinite loop in freeList
    head1->next->next->next->next = NULL;
    freeList(head1);

    // List 2 (No Cycle): 1 -> 2 -> NULL
    struct ListNode* head2 = createNode(1);
    head2->next = createNode(2);

    printf("List 2 has cycle: %s (Expected: false)\n", hasCycle(head2) ? "true" : "false");
    freeList(head2);

    return 0;
}
