#include <stdio.h>

double atof(char s[]);

double atof(char s[])
{
    double val, power;
    int i, sign, exp_sign = 1, exponent = 0;
    // Skip white space
    for (i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; i++)
        ;
    // Handle optional sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    // Convert integer part
    for (val = 0.0; s[i] >= '0' && s[i] <= '9'; i++) // Handle digits
        val = 10.0 * val + (s[i] - '0');
    // Convert fractional part if any
    if (s[i] == '.')
        i++; // Skip the decimal point
    for (power = 1.0; s[i] >= '0' && s[i] <= '9'; i++)
    { // Handle digits in the fraction
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    // Adjust for the decimal point position
    val = sign * val / power;

    // Handle scientific notation
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++; // Skip the 'e' or 'E'
        if (s[i] == '-')
        {
            exp_sign = -1; // Negative exponent
            i++;
        }
        else if (s[i] == '+')
        {
            i++; // Positive exponent
        }
        // Convert the exponent part
        for (; s[i] >= '0' && s[i] <= '9'; i++) // Handle digits in the exponent
            exponent = 10 * exponent + (s[i] - '0');
        // Apply the exponent manually
        if (exp_sign == 1)
        {
            while (exponent-- > 0) // Multiply by 10 for positive exponent
                val *= 10.0;
        }
        else
        {
            while (exponent-- > 0) // Divide by 10 for negative exponent
                val /= 10.0;
        }
    }

    return val;
}

int main()
{
    char s[] = "123.45e-6";
    double val = atof(s);

    printf("The value of '%s' is %e\n", s, val);

    return 0;
}