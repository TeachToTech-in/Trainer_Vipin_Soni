/**
 * Problem: Valid Anagram
 * LeetCode Link: https://leetcode.com/problems/valid-anagram/
 * Description: Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isAnagram(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t) {
        return false;
    }

    // Array to store the frequency of each character (a-z)
    int count[26] = {0};

    // Count characters in s
    for (int i = 0; i < len_s; i++) {
        count[s[i] - 'a']++;
    }

    // Decrement count for characters in t
    for (int i = 0; i < len_t; i++) {
        count[t[i] - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

// Example usage
int main() {
    printf("s=\"anagram\", t=\"nagaram\" is anagram: %s\n", isAnagram("anagram", "nagaram") ? "true" : "false"); // Expected: true
    printf("s=\"rat\", t=\"car\" is anagram: %s\n", isAnagram("rat", "car") ? "true" : "false");             // Expected: false

    return 0;
}
