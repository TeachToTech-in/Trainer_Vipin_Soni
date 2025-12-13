/**
 * Problem: Reverse String
 * LeetCode Link: https://leetcode.com/problems/reverse-string/
 * Description: Write a function that reverses a string. The input string is given as an array of characters s.
 * Note: This is the iterative solution, which is generally preferred over the recursive one for performance.
 */

#include <stdio.h>
#include <string.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * void reverseString(char* s, int sSize)
 */
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;

    while (left < right) {
        // Swap characters at left and right
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Move pointers inward
        left++;
        right--;
    }
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
