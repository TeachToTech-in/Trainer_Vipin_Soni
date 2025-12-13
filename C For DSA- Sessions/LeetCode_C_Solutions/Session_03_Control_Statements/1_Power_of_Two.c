/**
 * Problem: Power of Two
 * LeetCode Link: https://leetcode.com/problems/power-of-two/
 * Description: Given an integer n, return true if it is a power of two. Otherwise, return false.
 */

#include <stdbool.h>
#include <stdio.h>

bool isPowerOfTwo(int n) {
    // A number n is a power of two if and only if n > 0 and (n & (n - 1)) == 0.
    // The expression n & (n - 1) clears the least significant set bit.
    // If n is a power of two, it has only one set bit, so clearing it results in 0.
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Example usage
int main() {
    printf("1 is power of two: %s\n", isPowerOfTwo(1) ? "true" : "false");   // Expected: true
    printf("16 is power of two: %s\n", isPowerOfTwo(16) ? "true" : "false"); // Expected: true
    printf("3 is power of two: %s\n", isPowerOfTwo(3) ? "true" : "false");   // Expected: false
    printf("0 is power of two: %s\n", isPowerOfTwo(0) ? "true" : "false");   // Expected: false
    printf("-16 is power of two: %s\n", isPowerOfTwo(-16) ? "true" : "false"); // Expected: false

    return 0;
}
