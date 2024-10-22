#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "stuff";
    char s2[] = "f";
    squeeze(s1, s2);
    
    
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int s1_length = 0;
    int s2_length = 0;
    
    while(s1[s1_length++] != '\0');
    while(s2[s2_length++] != '\0');
    
    for(int i = 0; i < s1_length; i++) {
        for(int j = 0; j < s2_length; j++) {
            if(s1[i] == s2[j] && s2[j] != '\0') {
                s1[i] = ' ';
                break;
            }
        }
    }
    
    printf("%s", s1);
    
}