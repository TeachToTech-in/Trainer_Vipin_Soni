/**
 * Problem: Fibonacci Number (Iterative Solution for Session 4: Loops)
 * LeetCode Link: https://leetcode.com/problems/fibonacci-number/
 * Description: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
 */

#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return n;
    }

    int a = 0;
    int b = 1;
    int result = 0;

    // Loop from 2 up to n
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

// Example usage
int main() {
    printf("Fib(2): %d\n", fib(2)); // Expected: 1
    printf("Fib(3): %d\n", fib(3)); // Expected: 2
    printf("Fib(4): %d\n", fib(4)); // Expected: 3
    printf("Fib(10): %d\n", fib(10)); // Expected: 55

    return 0;
}
