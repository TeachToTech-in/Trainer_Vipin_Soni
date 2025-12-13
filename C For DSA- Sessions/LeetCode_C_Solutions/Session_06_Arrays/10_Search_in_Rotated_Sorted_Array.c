/**
 * Problem: Search in Rotated Sorted Array
 * LeetCode Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 * Description: There is an integer array nums sorted in ascending order (with distinct values). Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k. Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 */

#include <stdio.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int search(int* nums, int numsSize, int target)
 */
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Determine which side is sorted
        if (nums[left] <= nums[mid]) { // Left side is sorted
            if (target >= nums[left] && target < nums[mid]) {
                // Target is in the sorted left half
                right = mid - 1;
            } else {
                // Target is in the unsorted right half
                left = mid + 1;
            }
        } else { // Right side is sorted
            if (target > nums[mid] && target <= nums[right]) {
                // Target is in the sorted right half
                left = mid + 1;
            } else {
                // Target is in the unsorted left half
                right = mid - 1;
            }
        }
    }

    return -1;
}

// Example usage
int main() {
    int nums1[] = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int size1 = 7;
    printf("Input: [4, 5, 6, 7, 0, 1, 2], Target: 0, Output: %d\n", search(nums1, size1, target1)); // Expected: 4

    int nums2[] = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    int size2 = 7;
    printf("Input: [4, 5, 6, 7, 0, 1, 2], Target: 3, Output: %d\n", search(nums2, size2, target2)); // Expected: -1

    int nums3[] = {1};
    int target3 = 0;
    int size3 = 1;
    printf("Input: [1], Target: 0, Output: %d\n", search(nums3, size3, target3)); // Expected: -1

    return 0;
}
