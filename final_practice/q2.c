#include <stdio.h>
#include <ctype.h>
#include <string.h>

void calculate_frequencies(char *input, int *frequencies_upper, int *frequencies_lower)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i]))
        {
            if (isupper(input[i]))
            {
                frequencies_upper[input[i] - 'A']++;
            }
            else
            {
                frequencies_lower[input[i] - 'a']++;
            }
        }
    }
}

int main()
{
    char input[1000];
    int frequencies_upper[26] = {0};
    int frequencies_lower[26] = {0};

    printf("Enter a string:\n");
    fgets(input, sizeof(input), stdin);

    calculate_frequencies(input, frequencies_upper, frequencies_lower);

    for (int i = 0; i < 26; i++)
    {
        printf("%c: %d\n", 'A' + i, frequencies_upper[i]);
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c: %d, ", 'a' + i, frequencies_lower[i]);
    }

    return 0;
}