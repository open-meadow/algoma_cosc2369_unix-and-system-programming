#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i = 0, j = 0;
    
    while(s1[i] != '\0') {
        int found = 0;
        
        for(int k = 0; s2[k] != '\0'; k++) {
            if(s1[i] == s2[k]) {
                found = 1;
                break;
            }
        }
        
        if(!found)
            s1[j++] = s1[i];
        
        i++;
    }
    
    s1[j] = '\0';
    printf("%s", s1);
}

int main() {
    char s1[] = "hello world";
    char s2[] = "hello";
    squeeze(s1, s2);
    return 0;
}