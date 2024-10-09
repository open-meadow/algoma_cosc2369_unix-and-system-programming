#include <stdio.h>

// Declare your invert function
unsigned int invert(unsigned int x, int p, int n) {
    // Solution found on internet
    // ((1 << n) - 1) creates mask with n-ones
    // e.g. if n = 3, then 00000111
    // << (p - n + 1) shifts it to correct position
    unsigned int mask = ((1 << n) - 1) << (p - n + 1);
    return x ^ mask;
}

int main() {
    // Test case 1
    unsigned int x1 = 45; // binary 00101101
    int p1 = 4;
    int n1 = 3;
    unsigned int result1 = invert(x1, p1, n1);
    printf("Test 1: invert(%u, %d, %d) = %u\n", x1, p1, n1, result1); // Expected: 45 (binary 00110001)

    // Test case 2
    unsigned int x2 = 240; // binary 11110000
    int p2 = 7;
    int n2 = 4;
    unsigned int result2 = invert(x2, p2, n2);
    printf("Test 2: invert(%u, %d, %d) = %u\n", x2, p2, n2, result2); // Expected: 0 (binary 00000000)

    // Additional Test Case
    unsigned int x3 = 170; // binary 10101010
    int p3 = 5;
    int n3 = 4;
    unsigned int result3 = invert(x3, p3, n3);
    printf("Additional Test: invert(%u, %d, %d) = %u\n", x3, p3, n3, result3); // Expected: [Hidden]

    return 0;
}