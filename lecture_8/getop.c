#include <stdio.h>

char getop(char s[], int lim)
{
    int i, c;

    // skip whitespace, tabs or newline]
    while ((c = getch()) == ' ' || c == '\t' || c == '\n')
        ;

    // if the character is not a digit or a decimal point,
    // return it as an operator
    if (c != '.' && (c < '0' || c > '9'))
    {
        return c;
    }
    s[0] = c;

    // collect the integer part of a number, one digit at
    // a time
    for (i = 1; (c = getchar()) >= '0' && c <= '9'; i++)
    {
        if (i < lim)
        {
            s[i] = c;
        }
    }
    // if a decimal point is found, collect the fractional part of the number
    if (c == '.')
    {
        if (i < lim)
        {
            s[i] = c;
        }
        // continue collecting digits for the fractional part
        for (i++; (c = getchar()) >= '0' && c <= '9'; i++)
        {
            if (i < lim)
            {
                s[i] = c;
            }
        }
    }

    if (i < lim)
    {
        ungetch(c);
        s[i] = '\0';
        return (i);
    }
    else
    {
        while (c != '\n' && c != EOF)
            c = getchar();
        s[lim - 1] = '\0';
        return ("TOOBIG");
    }
}

int main()
{
    printf("Hello world");
    return 0;
}