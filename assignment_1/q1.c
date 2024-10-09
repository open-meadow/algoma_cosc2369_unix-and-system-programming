/******************************************************************************

Rohan Varughese_Assignment 1
Question 1

*******************************************************************************/

#include <stdio.h>

int main() {
    int lower, upper, step;
    float fahr, celsius;
    
    lower = 0;
    upper = 60;
    step = 20;
    
    celsius = lower;
    
    printf("Celsius\tFahrenheit\n");
    while(celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) + 32.0;
        printf("%4.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    
    return 0;
}