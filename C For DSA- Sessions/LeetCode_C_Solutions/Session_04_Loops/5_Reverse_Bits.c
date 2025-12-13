/**
 * Problem: Reverse Bits
 * LeetCode Link: https://leetcode.com/problems/reverse-bits/
 * Description: Reverse bits of a given 32-bit unsigned integer.
 */

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        // Shift the result to the left to make space for the next bit
        result <<= 1;

        // Check the last bit of n and add it to the result
        if (n & 1) {
            result |= 1;
        }

        // Shift n to the right to process the next bit
        n >>= 1;
    }
    return result;
}

// Example usage
int main() {
    uint32_t n1 = 43261596; // 00000010100101000001111010011100
    uint32_t reversed1 = reverseBits(n1);
    printf("Input: %u (0x%x)\n", n1, n1);
    printf("Output: %u (0x%x)\n", reversed1, reversed1);
    // Expected output in hex: 0x3e660000 (10000000000000000000000000000000 in binary)

    return 0;
}
