/**
 * Problem: Length of String
 * GeeksforGeeks Link: https://www.geeksforgeeks.org/problems/length-of-string/1
 * Description: Given a string, find its length without using the built-in strlen() function.
 */

#include <stdio.h>

int lengthOfString(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Example usage
int main() {
    char* s1 = "Hello World";
    printf("Input: \"%s\", Length: %d\n", s1, lengthOfString(s1)); // Expected: 11

    char* s2 = "";
    printf("Input: \"%s\", Length: %d\n", s2, lengthOfString(s2)); // Expected: 0

    return 0;
}
