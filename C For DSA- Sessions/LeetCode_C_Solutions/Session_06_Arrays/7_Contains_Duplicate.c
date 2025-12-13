/**
 * Problem: Contains Duplicate
 * LeetCode Link: https://leetcode.com/problems/contains-duplicate/
 * Description: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 * Note: The most efficient solution uses a hash set, but a simpler, less efficient solution using sorting is provided here, as hash sets are not a standard C concept.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The LeetCode function signature for this problem is:
 * bool containsDuplicate(int* nums, int numsSize)
 */
bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return false;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Check for adjacent duplicates
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}

// Example usage
int main() {
    int nums1[] = {1, 2, 3, 1};
    int numsSize1 = 4;
    printf("Input: [1, 2, 3, 1], Contains Duplicate: %s\n", containsDuplicate(nums1, numsSize1) ? "true" : "false"); // Expected: true

    int nums2[] = {1, 2, 3, 4};
    int numsSize2 = 4;
    printf("Input: [1, 2, 3, 4], Contains Duplicate: %s\n", containsDuplicate(nums2, numsSize2) ? "true" : "false"); // Expected: false

    return 0;
}
