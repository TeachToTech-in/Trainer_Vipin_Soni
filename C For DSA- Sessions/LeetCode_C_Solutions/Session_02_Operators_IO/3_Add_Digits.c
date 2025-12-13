/**
 * Problem: Add Digits
 * LeetCode Link: https://leetcode.com/problems/add-digits/
 * Description: Given an integer num, repeatedly add all its digits until the result has only one digit.
 */

#include <stdio.h>

// Solution using the Digital Root formula: dr(n) = 1 + (n - 1) % 9
int addDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return 1 + (num - 1) % 9;
}

// Example usage
int main() {
    int n1 = 38;
    printf("Input: %d, Output: %d\n", n1, addDigits(n1)); // Expected: 2 (3+8=11, 1+1=2)

    int n2 = 0;
    printf("Input: %d, Output: %d\n", n2, addDigits(n2)); // Expected: 0

    int n3 = 9;
    printf("Input: %d, Output: %d\n", n3, addDigits(n3)); // Expected: 9

    return 0;
}
