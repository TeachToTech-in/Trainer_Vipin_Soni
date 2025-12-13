/**
 * Problem: Rotate String
 * LeetCode Link: https://leetcode.com/problems/rotate-string/
 * Description: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s. A shift on s consists of moving the leftmost character of s to the rightmost position.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * bool rotateString(char* s, char* goal)
 */
bool rotateString(char* s, char* goal) {
    int len_s = strlen(s);
    int len_goal = strlen(goal);

    if (len_s != len_goal) {
        return false;
    }
    if (len_s == 0) {
        return true;
    }

    // The core idea: if 'goal' is a rotation of 's', then 'goal' must be a substring of 's' concatenated with itself (s + s).
    // Example: s = "abcde", s+s = "abcdeabcde". goal = "cdeab" is a substring of s+s.

    // Create s + s
    char* s_s = (char*)malloc(2 * len_s + 1);
    if (s_s == NULL) return false;

    strcpy(s_s, s);
    strcat(s_s, s);

    // Check if 'goal' is a substring of 's + s'
    bool found = (strstr(s_s, goal) != NULL);

    free(s_s);
    return found;
}

// Example usage
int main() {
    printf("s=\"abcde\", goal=\"cdeab\", Output: %s\n", rotateString("abcde", "cdeab") ? "true" : "false"); // Expected: true
    printf("s=\"abcde\", goal=\"abced\", Output: %s\n", rotateString("abcde", "abced") ? "true" : "false"); // Expected: false
    printf("s=\"\", goal=\"\", Output: %s\n", rotateString("", "") ? "true" : "false"); // Expected: true

    return 0;
}
