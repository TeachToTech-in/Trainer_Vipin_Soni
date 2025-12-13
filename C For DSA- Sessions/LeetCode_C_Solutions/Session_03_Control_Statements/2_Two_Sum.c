/**
 * Problem: Two Sum
 * LeetCode Link: https://leetcode.com/problems/two-sum/
 * Description: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * Note: The optimal solution uses a hash map, but for a "Control Statements" session, a brute-force approach using nested loops is more appropriate to demonstrate control flow.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int* twoSum(int* nums, int numsSize, int target, int* returnSize)
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Brute-force approach using nested loops
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                if (result == NULL) {
                    *returnSize = 0;
                    return NULL;
                }
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL; // Should not happen based on problem constraints
}

// Example usage
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2) {
        printf("Input: [2, 7, 11, 15], Target: 9\n");
        printf("Output: [%d, %d]\n", result[0], result[1]); // Expected: [0, 1]
        free(result);
    } else {
        printf("No two sum solution found.\n");
    }

    return 0;
}
