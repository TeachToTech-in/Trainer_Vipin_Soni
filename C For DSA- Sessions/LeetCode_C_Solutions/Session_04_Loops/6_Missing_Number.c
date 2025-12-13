/**
 * Problem: Missing Number
 * LeetCode Link: https://leetcode.com/problems/missing-number/
 * Description: Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 */

#include <stdio.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int missingNumber(int* nums, int numsSize)
 */
int missingNumber(int* nums, int numsSize) {
    // Method 1: Summation
    // The sum of numbers from 0 to n is n * (n + 1) / 2.
    // The missing number is the difference between the expected sum and the actual sum.
    long long expectedSum = (long long)numsSize * (numsSize + 1) / 2;
    long long actualSum = 0;

    for (int i = 0; i < numsSize; i++) {
        actualSum += nums[i];
    }

    return (int)(expectedSum - actualSum);

    /*
    // Method 2: XOR (More robust against overflow)
    int missing = numsSize; // Initialize with n
    for (int i = 0; i < numsSize; i++) {
        missing ^= i;       // XOR with index
        missing ^= nums[i]; // XOR with element
    }
    return missing;
    */
}

// Example usage
int main() {
    int nums1[] = {3, 0, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Input: [3, 0, 1], Missing Number: %d\n", missingNumber(nums1, numsSize1)); // Expected: 2

    int nums2[] = {0, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Input: [0, 1], Missing Number: %d\n", missingNumber(nums2, numsSize2)); // Expected: 2

    int nums3[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Input: [9, 6, 4, 2, 3, 5, 7, 0, 1], Missing Number: %d\n", missingNumber(nums3, numsSize3)); // Expected: 8

    return 0;
}
