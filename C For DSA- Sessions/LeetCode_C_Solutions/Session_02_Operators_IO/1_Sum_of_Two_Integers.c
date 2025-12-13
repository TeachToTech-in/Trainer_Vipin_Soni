/**
 * Problem: Sum of Two Integers
 * Description: Given two integers a and b, return the sum of the two integers without using the operators + and -.
 * Note: This is a common LeetCode problem (e.g., LeetCode 371). Since the PDF does not provide a link,
 * a general solution using bit manipulation is provided.
 */

#include <stdio.h>

// Function to calculate the sum of two integers without using + or -
int getSum(int a, int b) {
    while (b != 0) {
        // 'carry' now holds the bits that need to be added to 'a'
        unsigned int carry = a & b;

        // 'a' now holds the sum without considering the carry
        a = a ^ b;

        // 'b' now holds the carry, shifted one position to the left
        b = carry << 1;
    }
    return a;
}

// Example usage
int main() {
    int num1 = 5;
    int num2 = 7;
    printf("Sum of %d and %d is: %d\n", num1, num2, getSum(num1, num2)); // Expected: 12

    num1 = -1;
    num2 = 1;
    printf("Sum of %d and %d is: %d\n", num1, num2, getSum(num1, num2)); // Expected: 0

    return 0;
}
