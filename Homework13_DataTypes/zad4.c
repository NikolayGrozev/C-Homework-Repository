#include <stdio.h>

typedef union diffTypeUnion{
    long odd;
    short even;
} strangeUnion;

int main(){
    strangeUnion arr[10];

    for(int i = 0; i < 10; i++){
        if( i % 2 == 0){
            arr[i].even = i;
        }else{
            arr[i].odd = i;
        }
    }

    printf("\nOdds: ");
    for(int i = 1; i < 10;){
        printf(" %ld ", arr[i].odd);
        i+=2;
    }

    printf("\nEvens: ");
    for(int i = 0; i < 10;){
        printf(" %hd ", arr[i].even);
        i+=2;
    }

    return 0;
}