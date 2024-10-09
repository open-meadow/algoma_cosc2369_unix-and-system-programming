/******************************************************************************
Rohan Varughese_Assignment 4
Question 4

As the question asked to modify the existing word counting program from Lesson 1,
the Lines and Character counts are still included.

*******************************************************************************/

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while((c = getchar()) != EOF) {
		++nc;
		if(c == '\n') {
			++nl;
		}
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
		    // only count as word it first character after space is a letter
			if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
				state = IN;
				++nw;
			}
		}
	}

	printf("Lines: %d Words: %d Characters: %d\n", nl, nw, nc);
	return 0;
}