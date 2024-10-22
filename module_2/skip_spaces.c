#include <stdio.h>

int get_line(char line[]);

int main() {
    char line[100];
    int line_length = get_line(line);
    
    while(line_length > 0) {
        printf("%s", line);
        line_length = get_line(line);
    }
    
    return 0;
}

int get_line(char line[]) {
    int c;
    int i = 0;
    
    for(i = 0; ; ++i) {
        c = getchar();
        
        if(c == EOF || c == '\n')
            break;
        if(c == ' ' || c == '\t') {
            i--;
            continue;
        }
        
        line[i] = c;
    }
    
    line[i] = '\0';
    return i;
}