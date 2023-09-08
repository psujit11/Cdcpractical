#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the states
enum States {
    Q0,     // Initial state
    Q1,     // State after seeing local part characters
    Q2,     // State after seeing '@' symbol
    Q3,     // State after seeing domain characters
    Q4,     // State after seeing '.' in domain
    Q5      // Accepting state (valid email)
};

// Function to check if a string is a valid email address
bool isValidEmail(char input[]) {
    enum States currentState = Q0;
    int i = 0;
    int len = strlen(input);

    while (i < len) {
        char symbol = input[i];

        switch (currentState) {
            case Q0:
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9')) {
                    currentState = Q1;
                } else {
                    return false; // Invalid email
                }
                break;
            case Q1:
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9')) {
                    currentState = Q1;
                } else if (symbol == '@') {
                    currentState = Q2;
                } else {
                    return false; // Invalid email
                }
                break;
            case Q2:
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9')) {
                    currentState = Q3;
                } else {
                    return false; // Invalid email
                }
                break;
            case Q3:
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9')) {
                    currentState = Q3;
                } else if (symbol == '.') {
                    currentState = Q4;
                } else {
                    return false; // Invalid email
                }
                break;
            case Q4:
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9')) {
                    currentState = Q3;
                } else {
                    return false; // Invalid email
                }
                break;
        }

        i++;
    }

    return currentState == Q3; // Accept if it reaches the Q3 state (valid email)
}

int main() {
    char input[100];
    printf("Enter an email address: ");
    scanf("%s", input);

    if (isValidEmail(input)) {
        printf("Valid email address\n");
    } else {
        printf("Invalid email address\n");
    }

    return 0;
}
