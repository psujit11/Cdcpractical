#include <stdio.h>

// Function to check if a string is a valid prepaid NTC number
int isValidNTCNumber(char input[]) {
    // Check the length of the number
    int length = 0;
    while (input[length] != '\0') {
        length++;
    }
    if (length != 10) {
        return 0; // Length should be 10 digits
    }

    // Check the first digit
    if (input[0] != '9') {
        return 0; // First digit must be 9
    }

    // Check the second digit
    char secondDigit = input[1];
    if (secondDigit != '6' && secondDigit != '7' && secondDigit != '8') {
        return 0; // Second digit must be 6, 7, or 8
    }

    // Check the remaining 8 digits
    for (int i = 2; i < 10; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0; // Other digits must be between 0 and 9
        }
    }

    return 1; // Passed all checks, it's a valid prepaid NTC number
}

int main() {
    char input[11]; // 10 digits plus '\0'
    printf("Enter a prepaid NTC number: ");
    scanf("%s", input);

    if (isValidNTCNumber(input)) {
        printf("Valid prepaid NTC number\n");
    } else {
        printf("Invalid prepaid NTC number\n");
    }

    return 0;
}
