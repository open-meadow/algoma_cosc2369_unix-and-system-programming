#include <stdio.h>

char line[200];
char longest[200];
int max = 0;

int get_line(void);
void copy(void);

int main() {
    int line_length = get_line();
    
    while(line_length > 0) {
        if (max < line_length) {
            max = line_length;
            copy();
        }
        
        line_length = get_line();
    }
    
    if(max > 0)
        printf("Longest line: %s", longest);
        
    return 0;
}

int get_line() {
    int i = 0;
    int c;
    
    for(i = 0; ; ++i) {
        c = getchar();
        
        if(c == EOF || c == '\n')
            break;
        
        line[i] = c;
    }
    
    line[i] = '\0';
    
    return i;
}

void copy() {
    int i = 0;
    extern char longest[], line[];
    
    while(line[i] != '\0') {
        longest[i] = line[i];
        ++i;
    }
    
    longest[i] = '\0';
}