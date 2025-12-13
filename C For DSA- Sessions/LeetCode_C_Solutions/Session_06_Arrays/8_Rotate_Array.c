/**
 * Problem: Rotate Array
 * LeetCode Link: https://leetcode.com/problems/rotate-array/
 * Description: Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 */

#include <stdio.h>

// Helper function to reverse a portion of the array
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

/**
 * Note: The LeetCode function signature for this problem is:
 * void rotate(int* nums, int numsSize, int k)
 */
void rotate(int* nums, int numsSize, int k) {
    // Handle cases where k is larger than numsSize
    k = k % numsSize;

    // 1. Reverse the entire array
    reverse(nums, 0, numsSize - 1);

    // 2. Reverse the first k elements
    reverse(nums, 0, k - 1);

    // 3. Reverse the remaining elements
    reverse(nums, k, numsSize - 1);
}

// Example usage
void print_array(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i == size - 1) ? "" : ", ");
    }
    printf("]");
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    int size1 = 7;
    rotate(nums1, size1, k1);
    printf("Input: [1, 2, 3, 4, 5, 6, 7], k=3, Output: ");
    print_array(nums1, size1); // Expected: [5, 6, 7, 1, 2, 3, 4]
    printf("\n");

    int nums2[] = {-1, -100, 3, 99};
    int k2 = 2;
    int size2 = 4;
    rotate(nums2, size2, k2);
    printf("Input: [-1, -100, 3, 99], k=2, Output: ");
    print_array(nums2, size2); // Expected: [3, 99, -1, -100]
    printf("\n");

    return 0;
}
