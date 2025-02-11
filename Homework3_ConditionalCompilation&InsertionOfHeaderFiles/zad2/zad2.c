#include <stdio.h>

#define ARRAY_SIZE 10

int main(){

    #if !(defined ARRAY_SIZE) || ARRAY_SIZE > 10 || ARRAY_SIZE < 1
        printf("There isn't an ENTERED array size which IS SUPPORTED by this application");
    #else
        int array[ARRAY_SIZE];
        int number = 1;
        array[0] = 1;

        for(int i = 1; i < ARRAY_SIZE; i++){
            number *= 2;
            array[i] = number;
        }
        
        for(int i = 0; i < ARRAY_SIZE; i++){
            printf("%d\n", array[i]);
        }
    #endif
}