#include <stdio.h>
#include <ctype.h>

float getfloat(void);

int main() {
    float number;

    printf("Enter a floating-point number: ");
    number = getfloat();

    if (number == 0 && ferror(stdin)) {
        printf("No valid floating-point number was entered.\n");
    } else {
        printf("You entered: %f\n", number);
    }

    return 0;
}

float getfloat(void) {
    int c, sign;
    float number = 0.0, power = 1.0;
    
    while((c = getchar()) != EOF && isspace(c));
    
    sign = (c == '-') ? -1 : 1;
    if(c == '-' || c == '+') {
        c = getchar();
    }
    
    while(isdigit(c)) {
        number = number * 10.0 + (c - '0');
        c = getchar();
    }
    
    if(c == '.') {
        c = getchar();
        while(isdigit(c)) {
            number = number * 10.0 + (c - '0');
            power *= 10.0;
            c = getchar();
        }
    }
    
    number = sign * number / power;
    
    if(c != EOF) {
        ungetc(c, stdin);
    }
    
    return number;
}