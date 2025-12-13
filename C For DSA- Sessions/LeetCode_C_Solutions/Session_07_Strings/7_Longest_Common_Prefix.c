/**
 * Problem: Longest Common Prefix
 * LeetCode Link: https://leetcode.com/problems/longest-common-prefix/
 * Description: Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * char* longestCommonPrefix(char** strs, int strsSize)
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* result = (char*)malloc(1);
        if (result == NULL) return NULL;
        result[0] = '\0';
        return result;
    }

    // The first string is the initial prefix candidate
    char* first_str = strs[0];
    int len = strlen(first_str);

    // The result string will be a substring of the first string
    char* result = (char*)malloc(len + 1);
    if (result == NULL) return NULL;

    for (int i = 0; i < len; i++) {
        char c = first_str[i];

        // Compare this character with the character at the same position in all other strings
        for (int j = 1; j < strsSize; j++) {
            // If the current string is shorter or the characters don't match
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                // The common prefix ends before this character
                strncpy(result, first_str, i);
                result[i] = '\0';
                return result;
            }
        }
    }

    // If the loop completes, the entire first string is the common prefix
    strcpy(result, first_str);
    return result;
}

// Example usage
int main() {
    char* strs1[] = {"flower", "flow", "flight"};
    int size1 = 3;
    char* result1 = longestCommonPrefix(strs1, size1);
    printf("Input: [\"flower\", \"flow\", \"flight\"], Output: \"%s\"\n", result1); // Expected: "fl"
    free(result1);

    char* strs2[] = {"dog", "racecar", "car"};
    int size2 = 3;
    char* result2 = longestCommonPrefix(strs2, size2);
    printf("Input: [\"dog\", \"racecar\", \"car\"], Output: \"%s\"\n", result2); // Expected: ""
    free(result2);

    return 0;
}
