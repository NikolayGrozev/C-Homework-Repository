#include <stdio.h>
#include <string.h>

#define input_SIZE 15

int main(){
    char input[input_SIZE];

    printf("Enter a input (You're allowed 15 characters): ");
    fgets(input, input_SIZE, stdin);

    char * hasNewLine = strchr(input, '\n');
    if(hasNewLine){
        *hasNewLine = '\0';
    }

    printf("You entered: [%s]", input);
    return 0;
}