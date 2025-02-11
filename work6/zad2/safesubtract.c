#include <stdio.h>
#include "safeint.h"

int main(int argc, char ** argv){

    struct SafeResult check1;
    check1 = safestrtoint(argv[1]);
    struct SafeResult check2;
    check2 = safestrtoint(argv[2]);

    if(!check1.error && !check2.error){
        int argument1 = check1.value;
        int argument2 = check2.value;  

        struct SafeResult Result = safesubtract(argument1, argument2);
        if(!Result.error){
            printf("The number %s subtracted by %s is: %d", argv[1], argv[2], Result.value);
        }else{
            printf("Error: The Substraction either resulted in an overflow or an underflow");
        }
    }else{
            printf("Error: Invalid Input");
    }

    return 0;
}