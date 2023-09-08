#include <stdio.h>

// Define the states
enum States {
    Q0,  // Initial state
    Q1,  // State after seeing 0
    Q2   // Final state after seeing 01
};

// Function to check if the input string is accepted
int isAccepted(char input[]) {
    enum States currentState = Q0;
    int i = 0;

    while (input[i] != '\0') {
        char symbol = input[i];

        // Define the transition table
        switch (currentState) {
            case Q0:
                if (symbol == '0') {
                    currentState = Q1;
                } else {
                    return 0; // Invalid input, not accepted
                }
                break;
            case Q1:
                if (symbol == '0') {
                    currentState = Q1;
                } else if (symbol == '1') {
                    currentState = Q2;
                } else {
                    return 0; // Invalid input, not accepted
                }
                break;
            case Q2:
                return 0; // Any additional input is invalid, not accepted
        }

        i++;
    }

    return (currentState == Q2); // Accept if the final state is Q2
}

int main() {
    char input[100];
    printf("Enter a binary string: ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }

    return 0;
}
