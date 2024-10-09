#include <stdio.h>

#define MAXOP 20
#define NUMBER '0'
#define TOOBIG '9'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char s[], int lim);
double atof(char s[]);
void push(double f);
double pop(void);
void clear(void);
int getch(void);
void ungetch(int c);

int main() {
    int type;
    char s[MAXOP];
    double op2;

    while((type = getop(s, MAXOP)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;
            
            case '*':
                push(pop() * pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            
            case '/':
                op2 = pop();
                if(op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero division\n");
                }

                break;

            case '=':
                printf("\t%.8g\n", pop());
                break;

            case 'c':
                clear();
                break;

            case TOOBIG:
                printf("%.20s ... is too long\n", s);
                break;
            
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

void push(double f) {
    if(sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, cannot push %g\n", f);
    }
}

double pop(void) {
    if(sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear(void) {
    sp = 0;
}

int getop(char s[], int lim) {
    int i, c;

    while((c = getch()) == ' ' || c == '\t' || c == '\n');

    if(c != '.' && (c < '0' || c > '9'))
        return c;
    
    s[0] = c;
    for(i = 1; i < lim && (c = getchar()) >= '0' && c <= '9'; i++)
        s[i] = c;
    if(c == '.') {
        s[i++] = c;
        while(i < lim && (c = getchar()) >= '0' && c <= '9')
            s[i++] = c;
    }
    s[i] = '\0';

    if(c != EOF)
        ungetch(c);
    
    return NUMBER;
}

double atof(char s[]) {
    double val, power;
    int i, sign;

    for(i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; i++);

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    
    for(val = 0.0; s[i] >= '0' && s[i] <= '9'; i++)
        val = 10.0 * val + (s[i] - '0');

    if(s[i] == '.')
        i++;
    
    for(power = 1.0; s[i] >= '0' && s[i] <= '9'; i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters");
    else
        buf[bufp++] = c;
}