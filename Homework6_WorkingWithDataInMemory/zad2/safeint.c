#include "safeint.h"

    struct SafeResult safeadd(int number1, int number2){
        struct SafeResult safeResult = {number1+number2, 0};

        if(number1 > 0 && number2 > 0 && (number1 + number2) < 0){
            safeResult.error = 1;
        }else if(number1 < 0 && number2 < 0 && (number1 + number2) > 0){
            safeResult.error = 1;
        }
        
        return safeResult;
    };

    struct SafeResult safesubtract(int number1, int number2){
        struct SafeResult safeResult = safeadd(number1, -number2);

        return safeResult;
    };

    struct SafeResult safemultiply(int number1, int number2){
        struct SafeResult safeResult = {number1 * number2, 0};
        struct SafeResult Test = {0, 0};

        int lastNumber = number1;
        int counter = (number2 < 0) ? -number2 : number2;
        
        for(int i = 0; i < counter; i++){
            Test = safeadd(number1, number2);
            if(Test.error == 1){
                safeResult.error = 1;
                break;
            }
        }

        return safeResult;
    };

    struct SafeResult safedivide(int number1, int number2){
        struct SafeResult safeResult = {number1 / number2, 0};
        
        if(number2 == 0){
            safeResult.error = 1;
        }

        return safeResult;
    };

    struct SafeResult safestrtoint(char *str){
        /*Тук преизползвах код от едно минало домашно със transformerfunction за превръщане на string --> integer*/
        struct SafeResult safeResult = {0, 0};
        int size;
        for(int i = 0; str[i] != '\0'; i++){
            size = i+1;
        }

        int modifier = 1;
        for(int i = 0; i < size - 1; i++){
            modifier *= 10;
        }
        int positiveOrNegative = 1;
        long int result = 0;

        for(int i = 0; i < size; i++){
            switch(str[i])
            {
                case '-': if(i > 0 || size == 1){safeResult.error = 1; break;} else{positiveOrNegative = -1; modifier /= 10;} break;
                case '1': result += 1*modifier; modifier /= 10; break;
                case '2': result += 2*modifier; modifier /= 10; break;
                case '3': result += 3*modifier; modifier /= 10; break;
                case '4': result += 4*modifier; modifier /= 10; break;
                case '5': result += 5*modifier; modifier /= 10; break;
                case '6': result += 6*modifier; modifier /= 10; break;
                case '7': result += 7*modifier; modifier /= 10; break;
                case '8': result += 8*modifier; modifier /= 10; break;
                case '9': result += 9*modifier; modifier /= 10; break;
                default: safeResult.error = 1; ; break;
            }
        }
        result = result * positiveOrNegative;

        struct SafeResult Test = safeadd(result, 0);

        if(Test.error == 1){
            safeResult.error = 1;
        }

        safeResult.value = result;
        return safeResult;
    };