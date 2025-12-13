/**
 * Problem: Counting Bits
 * LeetCode Link: https://leetcode.com/problems/counting-bits/
 * Description: Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int* countBits(int n, int* returnSize)
 * The provided solution uses a simple main function for demonstration.
 */

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    if (ans == NULL) {
        // Handle memory allocation failure
        *returnSize = 0;
        return NULL;
    }

    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        // Dynamic programming approach: ans[i] = ans[i >> 1] + (i & 1)
        // i >> 1 is i / 2, which shifts the bits to the right, effectively removing the last bit.
        // i & 1 is the last bit (0 or 1).
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}

// Example usage
int main() {
    int n = 5;
    int returnSize;
    int* result = countBits(n, &returnSize);

    if (result != NULL) {
        printf("Input n = %d, Output: [", n);
        for (int i = 0; i < returnSize; i++) {
            printf("%d%s", result[i], (i == returnSize - 1) ? "" : ", ");
        }
        printf("]\n"); // Expected: [0, 1, 1, 2, 1, 2]
        free(result);
    }

    return 0;
}
