#include <stdio.h>

// Declare your lower function
int lower(int c) {
    return (c >= 65 && c <= 90) ? c + 32 : c;
}

int main() {
    // Test case 1
    char c1 = 'A';
    int result1 = lower(c1);
    printf("Test 1: lower('%c') = '%c'\n", c1, result1); // Expected: 'a'
    
    // Test case 2
    char c2 = 'm';
    int result2 = lower(c2);
    printf("Test 2: lower('%c') = '%c'\n", c2, result2); // Expected: 'm'

    // Additional Test Case
    char c3 = 'Z';
    int result3 = lower(c3);
    printf("Additional Test: lower('%c') = '%c'\n", c3, result3); // Expected: [Hidden]
    
    return 0;
}