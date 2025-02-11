#include <stdio.h>
#include "mystrings.h"

int main(int argc, char ** argv){

    if(argc < 3){
        printf("Error: Not enough arguments(strcompare requires 2 arguments)");
        return 0;
    }else if (argc > 3){
        printf("Error: Too many Arguments(strcompare requires 2 arguments)");
        return 0;
    }
    
    if(strlength(argv[1]) > 50 || strlength(argv[2]) > 50){
        printf("Error: Input too long, an argument cannot exceed the length of 50");
        return 0;
    }

    printf("Comparisson between %s and %s: %d\n", argv[1],argv[2],strcompare(argv[1], argv[2]));
}