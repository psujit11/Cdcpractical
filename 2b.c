#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char string[100];
    int flag = 1;
    printf("Enter a string: ");
    scanf("%s", string);
	
	if(strlen(string)!=2){
		printf("Rejected");
	return 0;
	}

    if(((string[0]!='a') && (string[0]!='b')) && ((string[1]!='a') && (string[1]!='b'))){
      printf("Rejected\n");
      return 0;
    }

    printf("Accepeted\n");
    return 0;
}