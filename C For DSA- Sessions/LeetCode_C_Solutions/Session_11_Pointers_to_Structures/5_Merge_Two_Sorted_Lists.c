/**
 * Problem: Merge Two Sorted Lists
 * LeetCode Link: https://leetcode.com/problems/merge-two-sorted-lists/
 * Description: Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
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
 * struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to serve as the start of the merged list
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part of the non-empty list
    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }

    return dummy.next;
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
    // list1: 1 -> 2 -> 4 -> NULL
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    // list2: 1 -> 3 -> 4 -> NULL
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(merged); // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL

    freeList(merged); // Freeing the merged list also frees the nodes from list1 and list2

    return 0;
}
