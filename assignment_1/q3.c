/******************************************************************************

Rohan Varughese_Assignment 1
Question 3

*******************************************************************************/

#include <stdio.h>

int main() {
    int c;
    
    while((c = getchar()) != EOF) {
        if(c == '\t') {
           putchar('>'); 
        } else if (c == ' ') {
            putchar('.');
        } else {
            putchar(c);
        }
    }
    
    return 0;
}