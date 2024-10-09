#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int state = IN;
    int c;
    
    while((c = getchar()) != EOF) {
        if(state == IN) {
            putchar(c);
            
            if(c == ' ') {
                state = OUT;
            }
        } else {
            if (c == ' ' || c == '\t') {
                continue;
            } else {
                putchar(c);
                state = IN;
            }
        }
    }
    
    return 0;
}