/**
 * Problem: Remove Element
 * LeetCode Link: https://leetcode.com/problems/remove-element/
 * Description: Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed. Return the number of elements in nums which are not equal to val.
 */

#include <stdio.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int removeElement(int* nums, int numsSize, int val)
 */
int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // k is the count of elements not equal to val, and also the index to place the next non-val element.

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

// Example usage
int main() {
    int nums1[] = {3, 2, 2, 3};
    int val1 = 3;
    int numsSize1 = 4;
    int k1 = removeElement(nums1, numsSize1, val1);
    printf("Input: [3, 2, 2, 3], val: 3\n");
    printf("Output k: %d, nums: [", k1);
    for (int i = 0; i < k1; i++) {
        printf("%d%s", nums1[i], (i == k1 - 1) ? "" : ", ");
    }
    printf("]\n"); // Expected k: 2, nums: [2, 2, ...]

    int nums2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int numsSize2 = 8;
    int k2 = removeElement(nums2, numsSize2, val2);
    printf("Input: [0, 1, 2, 2, 3, 0, 4, 2], val: 2\n");
    printf("Output k: %d, nums: [", k2);
    for (int i = 0; i < k2; i++) {
        printf("%d%s", nums2[i], (i == k2 - 1) ? "" : ", ");
    }
    printf("]\n"); // Expected k: 5, nums: [0, 1, 3, 0, 4, ...]

    return 0;
}
