/**
 * Problem: Kth from End of Linked List
 * GeeksforGeeks Link: https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
 * Description: Given a linked list and an integer n, return the value of the nth node from the end of the linked list.
 */

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
 * Function to find the Nth node from the end of a linked list.
 * Returns the value of the node, or -1 if the list is too short.
 */
int getNthFromEnd(struct ListNode* head, int n) {
    // Use the two-pointer approach (fast and slow)
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            // List is shorter than n
            return -1;
        }
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // slow is now at the Nth node from the end
    return slow->val;
}

// Helper function to free the list memory
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
    // List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    struct ListNode* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    int n1 = 2;
    printf("2nd node from end: %d (Expected: 40)\n", getNthFromEnd(head, n1));

    int n2 = 5;
    printf("5th node from end: %d (Expected: 10)\n", getNthFromEnd(head, n2));

    int n3 = 6;
    printf("6th node from end: %d (Expected: -1)\n", getNthFromEnd(head, n3));

    freeList(head);

    return 0;
}
