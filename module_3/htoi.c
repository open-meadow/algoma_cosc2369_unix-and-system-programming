#include <stdio.h>

int htoi(char s[]);

int main() {
    int c;
    char s[6];
    int i = 0;
    
    while(c != EOF) {
        c = getchar();
        s[i] = c;
        ++i;
    }
    
    printf("\n");
    int hexa = htoi(s);
    printf("%d", hexa);
    
    return 0;
}

int htoi(char s[]) {
    int i = 0;
    int sum = 0;
    int value;
    
    if(s[i] == 0) {
        if(s[i] == 'x' || s[i] == 'X')
            i += 2;
    }
    
    for(; s[i] != '\0'; ++i) {
        if(s[i] >= '0' && s[i] <= '9')
            value = s[i] - '0';
        else if(s[i] >= 'a' && s[i] <= 'f')
            value = s[i] - 'a' + 10;
        else if(s[i] >= 'A' && s[i] <= 'F')
            value = s[i] - 'A' + 10;
        else
            break;
        
        sum = 16 * sum + value;
    }
    
    return sum;
}