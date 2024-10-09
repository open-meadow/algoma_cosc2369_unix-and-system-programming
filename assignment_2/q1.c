#include <stdio.h>

int strlength(char *s) {
    int i = 0;
    while(s[i] != '\0') {
        ++i;
    }
    
    return i;
}

int any(const char *s1, const char *s2) {
    int lengthS1 = strlength((char*)s1); // (char*) part found from internet
    int lengthS2 = strlength((char*)s2);
    
    int index = -1;
    
    for(int i = 0; i < lengthS2; i++) {
        for(int j = 0; j < lengthS1; j++) {
            if(s2[i] == s1[j]) {
                if(index == -1) {
                    index = j;
                } else {
                    if (index > j) {
                        index = j;
                    }
                }
            }
        }
        
    }
    
    return index;
}

// Declare your any function
int any(const char *s1, const char *s2);

int main() {
    printf("Hello world!\n");
    
    // Test case 1
    const char *s1_1 = "hello world";
    const char *s2_1 = "od";
    int result1 = any(s1_1, s2_1);
    printf("Test 1: any(\"%s\", \"%s\") = %d\n", s1_1, s2_1, result1); // Expected: 4
    
    // Test case 2
    const char *s1_2 = "abcdefg";
    const char *s2_2 = "xyz";
    int result2 = any(s1_2, s2_2);
    printf("Test 2: any(\"%s\", \"%s\") = %d\n", s1_2, s2_2, result2); // Expected: -1

    // Additional Test Case
    const char *s1_3 = "computer science";
    const char *s2_3 = "ueo";
    int result3 = any(s1_3, s2_3);
    printf("Additional Test: any(\"%s\", \"%s\") = %d\n", s1_3, s2_3, result3); // Expected: [Hidden]
    
    return 0;
}