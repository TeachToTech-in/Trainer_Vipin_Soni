/**
 * Problem: Middle of the Linked List
 * LeetCode Link: https://leetcode.com/problems/middle-of-the-linked-list/
 * Description: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.
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
 * Note: The LeetCode function signature for this problem is:
 * struct ListNode* middleNode(struct ListNode* head)
 */
struct ListNode* middleNode(struct ListNode* head) {
    // Use the slow and fast pointer technique (Tortoise and Hare)
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // When fast reaches the end, slow is at the middle node (or the second middle node for even length)
    return slow;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d%s", current->val, (current->next != NULL) ? " -> " : "");
        current = current->next;
    }
    printf("\n");
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
    // List 1 (Odd length): 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    printf("List 1: ");
    printList(head1);
    struct ListNode* middle1 = middleNode(head1);
    printf("Middle node value: %d (Expected: 3)\n", middle1->val);
    freeList(head1);

    // List 2 (Even length): 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    struct ListNode* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = createNode(4);
    head2->next->next->next->next = createNode(5);
    head2->next->next->next->next->next = createNode(6);

    printf("\nList 2: ");
    printList(head2);
    struct ListNode* middle2 = middleNode(head2);
    printf("Middle node value: %d (Expected: 4)\n", middle2->val);
    freeList(head2);

    return 0;
}
