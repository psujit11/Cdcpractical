#include <stdio.h>
#include <string.h>


int main() {
    char string[100];
    int flag = 1;
    printf("Enter a string: ");
    scanf("%s", string);

    for (int i= 0; i < strlen(string)-1; i++) {
        if((string[i] =='b') || (string[i] == 'a')){
            continue;
        }
        else{
            printf("Rejected\n");
            return 0;
        }
    }

    if(string[strlen(string)-1]!='a'){
        printf("Rejected\n");
        return 0;
    }

    printf("Accepted\n");
    return 0;
}