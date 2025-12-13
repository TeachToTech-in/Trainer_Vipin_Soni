/**
 * Problem: Search in Rotated Sorted Array II (with Duplicates)
 * LeetCode Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * Description: Given the array nums after the possible rotation and an integer target, return true if target is in nums, or false otherwise.
 * Note: The presence of duplicates complicates the binary search, as it can be impossible to tell which side is sorted when nums[left] == nums[mid] == nums[right].
 */

#include <stdbool.h>
#include <stdio.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * bool search(int* nums, int numsSize, int target)
 */
bool search_with_duplicates(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }

        // Handle the duplicate case: if nums[left] == nums[mid] == nums[right], we can't tell which side is sorted.
        // We safely shrink the search space by moving the left pointer.
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
            continue;
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

    return false;
}

// Example usage
int main() {
    int nums1[] = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    int size1 = 7;
    printf("Input: [2, 5, 6, 0, 0, 1, 2], Target: 0, Output: %s\n", search_with_duplicates(nums1, size1, target1) ? "true" : "false"); // Expected: true

    int nums2[] = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    int size2 = 7;
    printf("Input: [2, 5, 6, 0, 0, 1, 2], Target: 3, Output: %s\n", search_with_duplicates(nums2, size2, target2) ? "true" : "false"); // Expected: false

    int nums3[] = {1, 0, 1, 1, 1};
    int target3 = 0;
    int size3 = 5;
    printf("Input: [1, 0, 1, 1, 1], Target: 0, Output: %s\n", search_with_duplicates(nums3, size3, target3) ? "true" : "false"); // Expected: true

    return 0;
}
