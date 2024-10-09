#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int lim);
int find_index(char source[], char searchfor[]);

int main() {
    char line[MAXLINE]; // Array to store the input line
    char pattern[] = "the"; // Pattern to search in the input

    // Read each line and check if it contains the pattern
    while(get_line(line, MAXLINE) > 0) {
        if(find_index(line, pattern) >= 0) {
            printf("%s", line);
        }
    }

    return 0;
}

// Function to get line of input into array s and to return it's length
int get_line(char s[], int lim) {
    int c, i;

    // Read characters until limit is reached, EOF or newline
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if(c == '\n') { // if a newline is encountered
        s[i] = c;
        ++i;
    }

    s[i] = '\0'; // Terminate the string with a null character
    return i;
}

// Function to find first occurrence of string t in string s
int find_index(char s[], char t[]) {
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++) {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if(t[k] == '\0') {
            return i;
        }
    }

    return -1;
}