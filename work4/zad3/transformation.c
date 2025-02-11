#include "transformation.h"

struct Transformation TransformerFunction(char *arr, int size){

    int modifier = 1;
    for(int i = 0; i < size - 1; i++){
        modifier *= 10;
    }
    int positiveOrNegative = 1;
    long int result = 0;
    struct Transformation errorTransformation = {0, "invalid input string"};

    for(int i = 0; i < size; i++){
        switch(arr[i])
        {
            case '-': if(i > 0 || size == 1){return errorTransformation;} else{positiveOrNegative = -1; modifier /= 10;} break;
            case '1': result += 1*modifier; modifier /= 10; break;
            case '2': result += 2*modifier; modifier /= 10; break;
            case '3': result += 3*modifier; modifier /= 10; break;
            case '4': result += 4*modifier; modifier /= 10; break;
            case '5': result += 5*modifier; modifier /= 10; break;
            case '6': result += 6*modifier; modifier /= 10; break;
            case '7': result += 7*modifier; modifier /= 10; break;
            case '8': result += 8*modifier; modifier /= 10; break;
            case '9': result += 9*modifier; modifier /= 10; break;
            default: return errorTransformation; break;
        }
    }
    result = result * positiveOrNegative;
    struct Transformation transformation = {result, "\0"};

    return transformation;
}