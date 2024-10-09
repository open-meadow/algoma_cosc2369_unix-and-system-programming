#include <stdio.h>

int r_index(char s[], char t[]) {
    int i, j, k;
    int s_len, t_len;

    // find lengths of s and t
    for(s_len = 0; s[s_len] != '\0'; s_len++);
    for(t_len = 0; t[t_len] != '\0'; t_len++);

    for(i = s_len; i >= 0; i--) {
        for(j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++);
        if(t[k] == '\0') {
            return i;
        }
    }

    return -1;
}

int main() {
    char s[] = "this is the thing that we think";
    char t[] = "th";
    int pos = r_index(s, t);
    printf("The rightmost occurrence of '%s' in '%s' is at position %d\n", t, s, pos);
}