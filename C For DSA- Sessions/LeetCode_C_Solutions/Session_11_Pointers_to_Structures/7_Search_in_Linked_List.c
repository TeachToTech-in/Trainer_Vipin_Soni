/**
 * Problem: Search in Linked List
 * GeeksforGeeks Link: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1
 * Description: Given a linked list and an integer key, check if the key is present in the linked list.
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
 * Function to search for a key in a linked list.
 * Returns true if found, false otherwise.
 */
bool search(struct ListNode* head, int key) {
    struct ListNode* current = head;
    while (current != NULL) {
        if (current->val == key) {
            return true;
        }
        current = current->next;
    }
    return false;
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
    // List: 10 -> 20 -> 30 -> 40 -> NULL
    struct ListNode* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    int key1 = 30;
    printf("Searching for %d: %s (Expected: true)\n", key1, search(head, key1) ? "true" : "false");

    int key2 = 50;
    printf("Searching for %d: %s (Expected: false)\n", key2, search(head, key2) ? "true" : "false");

    freeList(head);

    return 0;
}
