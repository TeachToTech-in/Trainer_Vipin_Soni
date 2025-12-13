/**
 * Problem: Plus One
 * LeetCode Link: https://leetcode.com/problems/plus-one/
 * Description: Given a large integer represented as an integer array digits, where each digits[i] is the i-th digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. Increment the large integer by one and return the resulting array of digits.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int* plusOne(int* digits, int digitsSize, int* returnSize)
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Iterate from the least significant digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits; // No carry, return the original array
        }
        digits[i] = 0; // Set to 0 and carry over
    }

    // If the loop completes, it means a carry overflowed the most significant digit (e.g., 999 + 1 = 1000)
    int* newDigits = (int*)malloc((digitsSize + 1) * sizeof(int));
    if (newDigits == NULL) {
        *returnSize = 0;
        return NULL;
    }

    newDigits[0] = 1; // The new most significant digit is 1
    for (int i = 0; i < digitsSize; i++) {
        newDigits[i + 1] = 0; // All other digits are 0
    }

    *returnSize = digitsSize + 1;
    return newDigits;
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
    int digits1[] = {1, 2, 3};
    int size1 = 3;
    int returnSize1;
    int* result1 = plusOne(digits1, size1, &returnSize1);
    printf("Input: [1, 2, 3], Output: ");
    print_array(result1, returnSize1); // Expected: [1, 2, 4]
    printf("\n");
    if (result1 != digits1) free(result1);

    int digits2[] = {9, 9, 9};
    int size2 = 3;
    int returnSize2;
    int* result2 = plusOne(digits2, size2, &returnSize2);
    printf("Input: [9, 9, 9], Output: ");
    print_array(result2, returnSize2); // Expected: [1, 0, 0, 0]
    printf("\n");
    if (result2 != digits2) free(result2);

    return 0;
}
