/**
 * Problem: Fibonacci Number (Recursive Solution for Session 5: Functions & Recursion)
 * LeetCode Link: https://leetcode.com/problems/fibonacci-number/
 * Description: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
 */

#include <stdio.h>

int fib_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Example usage
int main() {
    printf("Fib(2): %d\n", fib_recursive(2)); // Expected: 1
    printf("Fib(3): %d\n", fib_recursive(3)); // Expected: 2
    printf("Fib(4): %d\n", fib_recursive(4)); // Expected: 3
    printf("Fib(10): %d\n", fib_recursive(10)); // Expected: 55

    return 0;
}
