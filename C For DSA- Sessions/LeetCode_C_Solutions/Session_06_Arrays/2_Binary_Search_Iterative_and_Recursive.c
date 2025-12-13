/**
 * Problem: Binary Search (Iterative and Recursive)
 * LeetCode Link: https://leetcode.com/problems/binary-search/
 * Description: Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 */

#include <stdio.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int search(int* nums, int numsSize, int target)
 */

// --- Iterative Solution ---
int binarySearchIterative(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids potential overflow

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// --- Recursive Solution ---
int binarySearchRecursiveHelper(int* nums, int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        return binarySearchRecursiveHelper(nums, mid + 1, right, target);
    } else {
        return binarySearchRecursiveHelper(nums, left, mid - 1, target);
    }
}

int binarySearchRecursive(int* nums, int numsSize, int target) {
    return binarySearchRecursiveHelper(nums, 0, numsSize - 1, target);
}

// Example usage
int main() {
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target1 = 9;
    int target2 = 2;

    printf("Iterative Search:\n");
    printf("Target %d found at index: %d (Expected: 4)\n", target1, binarySearchIterative(nums, numsSize, target1));
    printf("Target %d found at index: %d (Expected: -1)\n", target2, binarySearchIterative(nums, numsSize, target2));

    printf("\nRecursive Search:\n");
    printf("Target %d found at index: %d (Expected: 4)\n", target1, binarySearchRecursive(nums, numsSize, target1));
    printf("Target %d found at index: %d (Expected: -1)\n", target2, binarySearchRecursive(nums, numsSize, target2));

    return 0;
}
