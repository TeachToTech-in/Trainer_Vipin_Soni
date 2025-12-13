/**
 * Problem: Reverse Integer (Recursive Solution for Session 5: Functions & Recursion)
 * LeetCode Link: https://leetcode.com/problems/reverse-integer/
 * Description: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 * Note: Implementing this recursively while handling the LeetCode constraints (overflow) is complex. The provided solution uses a helper function with a static variable to simulate the state needed for overflow check, which is a common pattern for recursive solutions in C.
 */

#include <stdio.h>
#include <limits.h>

// Global/static variable to store the reversed number
static long reversed_num = 0;

// Helper function for the recursive logic
void reverse_helper(int x) {
    if (x == 0) {
        return;
    }

    int digit = x % 10;
    reversed_num = reversed_num * 10 + digit;

    // Check for overflow before the next recursive call
    if (reversed_num > INT_MAX || reversed_num < INT_MIN) {
        reversed_num = 0; // Mark as overflow
        return;
    }

    reverse_helper(x / 10);
}

int reverse_recursive(int x) {
    reversed_num = 0; // Reset for each new call
    reverse_helper(x);

    // If overflow occurred, reversed_num is 0, but 0 is also a valid result.
    // A more robust solution would require passing a status flag or using the iterative approach.
    // For simplicity and to demonstrate recursion, we use the static variable.
    // The iterative solution is generally preferred for this problem.
    if (reversed_num == 0 && x != 0) {
        // This is a simplification. The iterative solution is better for LeetCode.
        // For demonstration of recursion, we'll return 0 on overflow.
        return 0;
    }

    return (int)reversed_num;
}

// Example usage
int main() {
    printf("Reverse of 123: %d\n", reverse_recursive(123));   // Expected: 321
    printf("Reverse of -123: %d\n", reverse_recursive(-123)); // Expected: -321
    printf("Reverse of 120: %d\n", reverse_recursive(120));   // Expected: 21
    // Note: Overflow check is tricky with this recursive pattern.
    // The iterative solution (Session 4) is the standard LeetCode answer.

    return 0;
}
