/**
 * Problem: Length of Last Word
 * LeetCode Link: https://leetcode.com/problems/length-of-last-word/
 * Description: Given a string s consisting of words and spaces, return the length of the last word in the string. A word is a maximal substring consisting of non-space characters only.
 */

#include <stdio.h>
#include <string.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int lengthOfLastWord(char* s)
 */
int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int length = 0;
    int i = len - 1;

    // 1. Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // 2. Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

// Example usage
int main() {
    printf("Input: \"Hello World\", Output: %d\n", lengthOfLastWord("Hello World")); // Expected: 5
    printf("Input: \"   fly me   to   the moon  \", Output: %d\n", lengthOfLastWord("   fly me   to   the moon  ")); // Expected: 4
    printf("Input: \"luffy is still joyboy\", Output: %d\n", lengthOfLastWord("luffy is still joyboy")); // Expected: 6

    return 0;
}
