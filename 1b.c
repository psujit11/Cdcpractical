#include <stdio.h>
#include <string.h>

// Define the states
enum States {
    Q0,  // Initial state
    Q1,  // Accepting state
    Q2   // Dead-end state (final, non-accepting)
};

// Function to check if a string is a valid variable name
int isValidVariableName(char input[]) {
    enum States currentState = Q0;
    int i = 0;
    int len = strlen(input);

    while (i < len) {
        char symbol = input[i];

        switch (currentState) {
            case Q0:
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || symbol == '_') {
                    currentState = Q1;
                } else {
                    return 0; // Invalid variable name
                }
                break;
            case Q1:
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9') || symbol == '_') {
                    currentState = Q1;
                } else {
                    return 0; // Invalid variable name
                }
                break;
            case Q2:
                return 0; // Invalid variable name
        }

        i++;
    }

    return (currentState == Q1); // Return 1 if it's a valid variable name, 0 otherwise
}

int main() {
    char input[100];
    printf("Enter a variable name: ");
    scanf("%s", input);

    if (isValidVariableName(input)) {
        printf("Valid variable name\n");
    } else {
        printf("Invalid variable name\n");
    }

    return 0;
}
