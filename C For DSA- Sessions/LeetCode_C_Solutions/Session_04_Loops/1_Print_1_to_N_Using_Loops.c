/**
 * Problem: Print 1 to N Using Loops
 * Description: Write a C program to print numbers from 1 to N using a for loop, while loop, and do-while loop.
 */

#include <stdio.h>

void print_with_for(int n) {
    printf("Using for loop: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_with_while(int n) {
    printf("Using while loop: ");
    int i = 1;
    while (i <= n) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
}

void print_with_do_while(int n) {
    printf("Using do-while loop: ");
    int i = 1;
    if (n >= 1) {
        do {
            printf("%d ", i);
            i++;
        } while (i <= n);
    }
    printf("\n");
}

// Example usage
int main() {
    int N = 10;
    printf("Printing numbers from 1 to %d:\n", N);
    print_with_for(N);
    print_with_while(N);
    print_with_do_while(N);

    return 0;
}
