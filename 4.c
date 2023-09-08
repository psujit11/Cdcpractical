#include <stdio.h>
#include <string.h>

#define MAX_VARIABLES 100

struct Variable {
    char name[50];
    char type[20];
    char value[50];
    int address;
};

struct Variable symbolTable[MAX_VARIABLES];
int symbolCount = 0;
int currentAddress = 100;

// Function to add a variable to the symbol table
void addVariable(const char *name, const char *type, const char *value) {
    struct Variable var;
    strcpy(var.name, name);
    strcpy(var.type, type);
    strcpy(var.value, value);
    var.address = currentAddress;
    symbolTable[symbolCount++] = var;
    currentAddress += (strcmp(type, "integer") == 0) ? sizeof(int) : sizeof(float);
}

// Function to print the symbol table
void printSymbolTable() {
    printf("Variable Name   Type           Value          Address\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%-15s%-15s%-15s%d\n", symbolTable[i].name, symbolTable[i].type, symbolTable[i].value, symbolTable[i].address);
    }
}

int main() {
    char input[200];
    printf("Enter variable declarations (e.g., int a = 2, float b = 3.5): ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, ",;");
    while (token != NULL) {
        char name[50], type[20], value[50];
        if (sscanf(token, "%s %s = %s", type, name, value) == 3) {
            addVariable(name, type, value);
        }
        token = strtok(NULL, ",;");
    }

    printf("\nSymbol Table:\n");
    printSymbolTable();

    return 0;
}
