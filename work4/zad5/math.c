#include "math.h"

long int function(long int number){
    long int result = 1;
    for(long int i = 1; i <= number; i++){
        result *= i;
    }
    return result;
};
