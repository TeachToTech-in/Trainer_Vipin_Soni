/**
 * Problem: Remove Outermost Parentheses
 * LeetCode Link: https://leetcode.com/problems/remove-outermost-parentheses/
 * Description: A valid parentheses string is primitive if it is non-empty, and there does not exist a way to split it into S = A+B, where A and B are non-empty valid parentheses strings. Given a valid parentheses string S, consider its primitive decomposition S = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings. Return S after removing the outermost parentheses of every primitive string in the decomposition.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * char* removeOuterParentheses(char* s)
 */
char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(len + 1); // Max size is the original string length + null terminator
    if (result == NULL) return NULL;

    int balance = 0;
    int result_index = 0;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (c == '(') {
            // If balance > 0, it means we are inside a primitive string, so we keep the opening parenthesis.
            if (balance > 0) {
                result[result_index++] = c;
            }
            balance++;
        } else { // c == ')'
            balance--;
            // If balance > 0, it means we are inside a primitive string, so we keep the closing parenthesis.
            if (balance > 0) {
                result[result_index++] = c;
            }
        }
    }

    result[result_index] = '\0'; // Null-terminate the result string
    return result;
}

// Example usage
int main() {
    char* s1 = "(()())(())";
    char* result1 = removeOuterParentheses(s1);
    printf("Input: \"%s\", Output: \"%s\"\n", s1, result1); // Expected: "()()()"
    free(result1);

    char* s2 = "(()())(())(()(()))";
    char* result2 = removeOuterParentheses(s2);
    printf("Input: \"%s\", Output: \"%s\"\n", s2, result2); // Expected: "()()()(())"
    free(result2);

    return 0;
}
