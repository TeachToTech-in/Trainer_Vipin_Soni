/**
 * Problem: Reverse String (Recursive Solution for Session 5: Functions & Recursion)
 * LeetCode Link: https://leetcode.com/problems/reverse-string/
 * Description: Write a function that reverses a string. The input string is given as an array of characters s.
 */

#include <stdio.h>
#include <string.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * void reverseString(char* s, int sSize)
 */

void reverseStringRecursiveHelper(char* s, int left, int right) {
    if (left >= right) {
        return;
    }

    // Swap characters at left and right
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    // Recurse on the inner part of the string
    reverseStringRecursiveHelper(s, left + 1, right - 1);
}

void reverseString(char* s, int sSize) {
    reverseStringRecursiveHelper(s, 0, sSize - 1);
}

// Example usage
int main() {
    char s1[] = "hello";
    int size1 = strlen(s1);
    reverseString(s1, size1);
    printf("Input: \"hello\", Output: \"%s\"\n", s1); // Expected: olleh

    char s2[] = "Hannah";
    int size2 = strlen(s2);
    reverseString(s2, size2);
    printf("Input: \"Hannah\", Output: \"%s\"\n", s2); // Expected: hannaH

    return 0;
}
