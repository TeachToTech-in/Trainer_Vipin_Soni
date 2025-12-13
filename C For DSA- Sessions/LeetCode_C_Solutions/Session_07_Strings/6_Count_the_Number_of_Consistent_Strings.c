/**
 * Problem: Count the Number of Consistent Strings
 * LeetCode Link: https://leetcode.com/problems/count-the-number-of-consistent-strings/
 * Description: You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed. Return the number of consistent strings in the array words.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: The LeetCode function signature for this problem is:
 * int countConsistentStrings(char* allowed, char** words, int wordsSize)
 */

// Helper function to check if a word is consistent
bool isConsistent(char* allowed, char* word) {
    // Create a boolean array (or int array) to act as a set for allowed characters
    bool allowed_set[26] = {false};

    // Populate the set with allowed characters
    for (int i = 0; allowed[i] != '\0'; i++) {
        allowed_set[allowed[i] - 'a'] = true;
    }

    // Check if all characters in the word are in the allowed set
    for (int i = 0; word[i] != '\0'; i++) {
        if (!allowed_set[word[i] - 'a']) {
            return false;
        }
    }

    return true;
}

int countConsistentStrings(char* allowed, char** words, int wordsSize) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (isConsistent(allowed, words[i])) {
            count++;
        }
    }
    return count;
}

// Example usage
int main() {
    char* allowed1 = "ab";
    char* words1[] = {"ad", "bd", "aaab", "baa", "badab"};
    int wordsSize1 = 5;
    printf("Allowed: \"%s\", Words: [\"ad\", \"bd\", \"aaab\", \"baa\", \"badab\"], Output: %d\n", allowed1, countConsistentStrings(allowed1, words1, wordsSize1)); // Expected: 2 ("aaab", "baa")

    char* allowed2 = "abc";
    char* words2[] = {"a", "b", "c", "ab", "ac", "bc", "abc"};
    int wordsSize2 = 7;
    printf("Allowed: \"%s\", Words: [\"a\", \"b\", \"c\", \"ab\", \"ac\", \"bc\", \"abc\"], Output: %d\n", allowed2, countConsistentStrings(allowed2, words2, wordsSize2)); // Expected: 7

    return 0;
}
