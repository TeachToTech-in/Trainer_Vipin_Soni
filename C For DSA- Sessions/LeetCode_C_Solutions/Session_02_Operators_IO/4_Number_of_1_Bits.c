/**
 * Problem: Number of 1 Bits (Hamming Weight)
 * LeetCode Link: https://leetcode.com/problems/number-of-1-bits/
 * Description: Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 */

#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        // n & (n - 1) clears the least significant set bit
        n &= (n - 1);
        count++;
    }
    return count;
}

// Example usage
int main() {
    uint32_t n1 = 0b000000000000000000001011; // 11
    printf("Input: %u, Output: %d\n", n1, hammingWeight(n1)); // Expected: 3

    uint32_t n2 = 0b11111111111111111111111111111101; // 4294967293
    printf("Input: %u, Output: %d\n", n2, hammingWeight(n2)); // Expected: 31

    return 0;
}
