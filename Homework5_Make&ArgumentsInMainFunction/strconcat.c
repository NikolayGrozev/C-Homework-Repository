#include <stdio.h>
#include <string.h>
#include "mystrings.h"

int main(int argc, char ** argv){
    

    if(argc < 3){
        printf("Error: Not enough arguments(strconcat requires 2 arguments)");
        return 0;
    }else if (argc > 3){
        printf("Error: Too many Arguments(strconcat requires 2 arguments)");
        return 0;
    }

    if(strlength(argv[1]) > 50 || strlength(argv[2]) > 50){
        printf("Error: Input too long, an argument cannot exceed the length of 50");
        return 0;
    }

    printf("\nfirst: %s", argv[1]);
    printf("\nsecond: %s", argv[2]);

    char a[50];

    strcpy(a, argv[1]);

    strconcat(a, argv[2]);

    printf("\nfirst after: %s", a);
    printf("\nsecond after: %s", argv[2]);

    return 0;
}