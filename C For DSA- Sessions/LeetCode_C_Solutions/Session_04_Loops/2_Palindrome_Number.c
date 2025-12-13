/**
 * Problem: Palindrome Number
 * LeetCode Link: https://leetcode.com/problems/palindrome-number/
 * Description: Given an integer x, return true if x is a palindrome, and false otherwise.
 */

#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    // Negative numbers are not palindromes (e.g., -121 is not 121-)
    // Numbers ending in 0 (except 0 itself) are not palindromes (e.g., 10, 200)
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedNumber = 0;
    while (x > reversedNumber) {
        reversedNumber = reversedNumber * 10 + x % 10;
        x /= 10;
    }

    // When the length is an odd number, we can get rid of the middle digit by reversedNumber/10
    // For example, when the input is 121, at the end of the loop, x = 1, reversedNumber = 12.
    // The middle digit doesn't matter in a palindrome (it's always equal to itself).
    return x == reversedNumber || x == reversedNumber / 10;
}

// Example usage
int main() {
    printf("121 is palindrome: %s\n", isPalindrome(121) ? "true" : "false");   // Expected: true
    printf("-121 is palindrome: %s\n", isPalindrome(-121) ? "true" : "false"); // Expected: false
    printf("10 is palindrome: %s\n", isPalindrome(10) ? "true" : "false");     // Expected: false
    printf("12321 is palindrome: %s\n", isPalindrome(12321) ? "true" : "false"); // Expected: true

    return 0;
}
