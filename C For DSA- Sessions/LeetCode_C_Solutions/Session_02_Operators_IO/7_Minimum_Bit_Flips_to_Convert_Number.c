/**
 * Problem: Minimum Bit Flips to Convert Number
 * LeetCode Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
 * Description: Given two numbers start and goal, return the minimum number of bit flips to convert start to goal.
 */

#include <stdio.h>
#include <stdint.h>

int minBitFlips(int start, int goal) {
    // The number of flips is the number of set bits in the XOR result (start ^ goal)
    // XOR operation gives a 1 for every bit that is different between start and goal.
    int xor_result = start ^ goal;
    int flips = 0;

    // Count the set bits (Hamming Weight)
    while (xor_result != 0) {
        // Brian Kernighan's Algorithm: clears the least significant set bit
        xor_result &= (xor_result - 1);
        flips++;
    }

    return flips;
}

// Example usage
int main() {
    int start1 = 10; // 1010
    int goal1 = 7;   // 0111
    printf("Start: %d, Goal: %d, Flips: %d\n", start1, goal1, minBitFlips(start1, goal1)); // Expected: 3

    int start2 = 3; // 011
    int goal2 = 4;  // 100
    printf("Start: %d, Goal: %d, Flips: %d\n", start2, goal2, minBitFlips(start2, goal2)); // Expected: 3

    return 0;
}
