/**
 * Problem: Add Two Numbers
 * LeetCode Link: https://leetcode.com/problems/add-two-numbers/
 * Description: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
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
 * struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = createNode(0);
    struct ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        int digit = sum % 10;

        current->next = createNode(digit);
        current = current->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    struct ListNode* result = dummyHead->next;
    free(dummyHead);
    return result;
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
    // l1: 2 -> 4 -> 3 (represents 342)
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // l2: 5 -> 6 -> 4 (represents 465)
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    printf("List 1 (342): ");
    printList(l1);
    printf("List 2 (465): ");
    printList(l2);

    struct ListNode* result = addTwoNumbers(l1, l2); // Expected: 7 -> 0 -> 8 (represents 807)

    printf("Result (807): ");
    printList(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
