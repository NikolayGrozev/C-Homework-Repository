#include <stdio.h>

int main(){
    int a = 15;
    int b = 12;
    int ok = 0;
    int number = 0;

    while(!ok){
        number++;
        if(number % a == 0 && number % b == 0){
            ok = 1;
        }
    }

    printf("The number is: %d", number);

    return 0;
}