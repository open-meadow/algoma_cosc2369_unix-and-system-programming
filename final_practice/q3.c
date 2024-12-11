#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100

int main() {
    char input[MAX_INPUT];
    double operand1, operand2, result = 0.0;
    char oper;

    while (1) {
        printf("Enter operation (operand1 operator operand2) or '=' to quit:\n");
        fgets(input, MAX_INPUT, stdin); // Read the input as a single string
        
        if (input[0] == '=') { // Check if the input is the '=' character
            printf("Final Result: %.2f\n", result);
            return 0;
        }
        
        printf("%s\n", input);

        // Parse the input
        sscanf(input, "%lf %lf %c", &operand1, &operand2, &oper);
        
        printf("%lf %lf %c", operand1, operand2, oper);

        // Perform the operation
        switch (oper) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            printf("Unknown operator '%c'.\n", oper);
            continue;
        }

        printf("Result: %.2f\n", result);
    }

    return 0;
}
