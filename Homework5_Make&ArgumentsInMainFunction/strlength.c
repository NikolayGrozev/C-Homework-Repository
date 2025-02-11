#include <stdio.h>
#include<string.h>
#include "mystrings.h"

int main(int argc, char ** argv){



    if(argc == 2){
        if(strlength(argv[1]) > 50){
            printf("Error: Input too long, an argument cannot exceed the length of 50");
            return 0;
        }
        printf("Argument: %s\n", argv[1]);

        printf("Length: %d", strlength(argv[1]));
    } else if(argc == 1){
        printf("Error: No input(You have to type your input after calling this function, but seperate it with a space)");
    } else if (argc > 2){
        printf("Error: Too many Inputs(strlength requires 1 argument)");
    }
    

}