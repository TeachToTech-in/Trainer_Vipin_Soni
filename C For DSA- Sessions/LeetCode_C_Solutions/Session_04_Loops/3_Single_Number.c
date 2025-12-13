/**
 * Problem: Single Number
 * LeetCode Link: https://leetcode.com/problems/single-number/
 * Description: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * Note: The solution uses the XOR bitwise operator, which is often covered in the "Operators" session, but the problem is listed under "Loops" in the PDF.
 */

#include <stdio.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int singleNumber(int* nums, int numsSize)
 */
int singleNumber(int* nums, int numsSize) {
    int result = 0;
    // XORing all elements: a ^ a = 0, a ^ 0 = a.
    // Since every element appears twice except one, all pairs will cancel out to 0,
    // leaving only the single number.
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

// Example usage
int main() {
    int nums1[] = {2, 2, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Input: [2, 2, 1], Output: %d\n", singleNumber(nums1, numsSize1)); // Expected: 1

    int nums2[] = {4, 1, 2, 1, 2};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Input: [4, 1, 2, 1, 2], Output: %d\n", singleNumber(nums2, numsSize2)); // Expected: 4

    return 0;
}
