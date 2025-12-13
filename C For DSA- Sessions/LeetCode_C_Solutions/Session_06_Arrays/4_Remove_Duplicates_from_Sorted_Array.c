/**
 * Problem: Remove Duplicates from Sorted Array
 * LeetCode Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Description: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Return the number of unique elements.
 */

#include <stdio.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int removeDuplicates(int* nums, int numsSize)
 */
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int k = 1; // k is the count of unique elements, and also the index to place the next unique element.

    for (int i = 1; i < numsSize; i++) {
        // If the current element is different from the last unique element (at index k-1)
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

// Example usage
int main() {
    int nums1[] = {1, 1, 2};
    int numsSize1 = 3;
    int k1 = removeDuplicates(nums1, numsSize1);
    printf("Input: [1, 1, 2]\n");
    printf("Output k: %d, nums: [", k1);
    for (int i = 0; i < k1; i++) {
        printf("%d%s", nums1[i], (i == k1 - 1) ? "" : ", ");
    }
    printf("]\n"); // Expected k: 2, nums: [1, 2, ...]

    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize2 = 10;
    int k2 = removeDuplicates(nums2, numsSize2);
    printf("Input: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]\n");
    printf("Output k: %d, nums: [", k2);
    for (int i = 0; i < k2; i++) {
        printf("%d%s", nums2[i], (i == k2 - 1) ? "" : ", ");
    }
    printf("]\n"); // Expected k: 5, nums: [0, 1, 2, 3, 4, ...]

    return 0;
}
