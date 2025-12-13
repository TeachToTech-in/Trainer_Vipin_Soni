/**
 * Problem: Subtract the Product and Sum of Digits of an Integer
 * LeetCode Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 * Description: Given an integer n, return the difference between the product of its digits and the sum of its digits.
 */

#include <stdio.h>

int subtractProductAndSum(int n) {
    long product = 1;
    int sum = 0;
    int temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        product *= digit;
        sum += digit;
        temp /= 10;
    }

    return (int)(product - sum);
}

// Example usage
int main() {
    int n1 = 234;
    printf("Input: %d, Output: %d\n", n1, subtractProductAndSum(n1)); // Expected: 15 (2*3*4 - (2+3+4) = 24 - 9 = 15)

    int n2 = 4421;
    printf("Input: %d, Output: %d\n", n2, subtractProductAndSum(n2)); // Expected: 21 (4*4*2*1 - (4+4+2+1) = 32 - 11 = 21)

    return 0;
}
