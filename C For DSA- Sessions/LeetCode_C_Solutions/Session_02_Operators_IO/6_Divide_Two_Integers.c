/**
 * Problem: Divide Two Integers
 * LeetCode Link: https://leetcode.com/problems/divide-two-integers/
 * Description: Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    // Determine the sign of the result
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Use long long for absolute values to handle INT_MIN
    long long abs_dividend = labs((long long)dividend);
    long long abs_divisor = labs((long long)divisor);

    long long quotient = 0;

    while (abs_dividend >= abs_divisor) {
        long long temp_divisor = abs_divisor;
        long long multiple = 1;

        // Find the largest multiple of abs_divisor that is less than or equal to abs_dividend
        while (abs_dividend >= (temp_divisor << 1)) {
            temp_divisor <<= 1;
            multiple <<= 1;
        }

        abs_dividend -= temp_divisor;
        quotient += multiple;
    }

    return negative ? (int)-quotient : (int)quotient;
}

// Example usage
int main() {
    printf("10 / 3 = %d\n", divide(10, 3));       // Expected: 3
    printf("7 / -3 = %d\n", divide(7, -3));      // Expected: -2
    printf("0 / 1 = %d\n", divide(0, 1));        // Expected: 0
    printf("1 / 1 = %d\n", divide(1, 1));        // Expected: 1
    printf("-2147483648 / -1 = %d\n", divide(INT_MIN, -1)); // Expected: 2147483647 (INT_MAX)
    printf("-2147483648 / 2 = %d\n", divide(INT_MIN, 2)); // Expected: -1073741824

    return 0;
}
