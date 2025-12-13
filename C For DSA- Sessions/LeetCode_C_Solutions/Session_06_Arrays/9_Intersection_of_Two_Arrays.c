/**
 * Problem: Intersection of Two Arrays
 * LeetCode Link: https://leetcode.com/problems/intersection-of-two-arrays/
 * Description: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
 * Note: The solution uses sorting and two pointers, which is a common technique for array problems.
 */

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The LeetCode function signature for this problem is:
 * int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // 1. Sort both arrays
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    // 2. Use two pointers
    int i = 0, j = 0, k = 0;
    int capacity = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(capacity * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            // Found an intersection
            // Check for duplicates in the result array
            if (k == 0 || result[k - 1] != nums1[i]) {
                result[k++] = nums1[i];
            }
            i++;
            j++;
        }
    }

    *returnSize = k;
    // Reallocate to the exact size (optional, but good practice)
    int* final_result = (int*)realloc(result, k * sizeof(int));
    return final_result ? final_result : result;
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
    int nums1_1[] = {1, 2, 2, 1};
    int nums2_1[] = {2, 2};
    int returnSize1;
    int* result1 = intersection(nums1_1, 4, nums2_1, 2, &returnSize1);
    printf("Input: [1, 2, 2, 1], [2, 2], Output: ");
    print_array(result1, returnSize1); // Expected: [2]
    printf("\n");
    free(result1);

    int nums1_2[] = {4, 9, 5};
    int nums2_2[] = {9, 4, 9, 8, 4};
    int returnSize2;
    int* result2 = intersection(nums1_2, 3, nums2_2, 5, &returnSize2);
    printf("Input: [4, 9, 5], [9, 4, 9, 8, 4], Output: ");
    print_array(result2, returnSize2); // Expected: [4, 9] (or [9, 4])
    printf("\n");
    free(result2);

    return 0;
}
