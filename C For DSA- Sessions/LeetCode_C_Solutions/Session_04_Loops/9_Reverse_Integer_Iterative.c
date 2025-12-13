/**
 * Problem: Reverse Integer (Iterative Solution for Session 4: Loops)
 * LeetCode Link: https://leetcode.com/problems/reverse-integer/
 * Description: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 */

#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    long reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;

        // Check for overflow before the next iteration
        if (reversed > INT_MAX || reversed < INT_MIN) {
            return 0;
        }
    }

    return (int)reversed;
}

// Example usage
int main() {
    printf("Reverse of 123: %d\n", reverse(123));   // Expected: 321
    printf("Reverse of -123: %d\n", reverse(-123)); // Expected: -321
    printf("Reverse of 120: %d\n", reverse(120));   // Expected: 21
    printf("Reverse of 1534236469: %d\n", reverse(1534236469)); // Expected: 0 (Overflow)

    return 0;
}
