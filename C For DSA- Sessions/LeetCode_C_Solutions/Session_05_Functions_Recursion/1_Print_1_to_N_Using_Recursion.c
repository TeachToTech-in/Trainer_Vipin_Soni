/**
 * Problem: Print 1 to N Using Recursion
 * Description: Write a C program to print numbers from 1 to N using recursion.
 */

#include <stdio.h>

void print_recursive(int n) {
    if (n > 0) {
        // Recursive call first (Head Recursion)
        print_recursive(n - 1);
        // Print after the recursive call returns
        printf("%d ", n);
    }
}

// Example usage
int main() {
    int N = 10;
    printf("Printing numbers from 1 to %d using recursion:\n", N);
    print_recursive(N);
    printf("\n");

    return 0;
}
