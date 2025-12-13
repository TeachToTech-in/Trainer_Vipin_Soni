/**
 * Problem: Largest Odd Number in String
 * LeetCode Link: https://leetcode.com/problems/largest-odd-number-in-string/
 * Description: Given a string num representing a large integer, return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * char* largestOddNumber(char* num)
 */
char* largestOddNumber(char* num) {
    int len = strlen(num);
    int last_odd_index = -1;

    // Find the rightmost odd digit
    for (int i = len - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        if (digit % 2 != 0) {
            last_odd_index = i;
            break;
        }
    }

    // If no odd digit is found
    if (last_odd_index == -1) {
        char* result = (char*)malloc(1);
        if (result == NULL) return NULL;
        result[0] = '\0';
        return result;
    }

    // The largest odd number is the substring from the start up to and including the last odd digit
    int result_len = last_odd_index + 1;
    char* result = (char*)malloc(result_len + 1);
    if (result == NULL) return NULL;

    strncpy(result, num, result_len);
    result[result_len] = '\0';

    return result;
}

// Example usage
int main() {
    char* s1 = "52";
    char* result1 = largestOddNumber(s1);
    printf("Input: \"%s\", Output: \"%s\"\n", s1, result1); // Expected: "5"
    free(result1);

    char* s2 = "4206";
    char* result2 = largestOddNumber(s2);
    printf("Input: \"%s\", Output: \"%s\"\n", s2, result2); // Expected: ""
    free(result2);

    char* s3 = "35427";
    char* result3 = largestOddNumber(s3);
    printf("Input: \"%s\", Output: \"%s\"\n", s3, result3); // Expected: "35427"
    free(result3);

    return 0;
}
