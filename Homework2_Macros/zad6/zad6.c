#include <stdio.h>

#define SWAP(A, B, TYPE)\
    TYPE swapper = A;\
    A = B;\
    B = swapper;

#define SORT(ARRAY, SIZE, TYPE, COMPARE)\
for(int i = 0; i < SIZE; i++){\
    for(int j = 0; j < SIZE - 1; j++){\
        if(ARRAY[j] COMPARE ARRAY[j+1]){\
            SWAP(ARRAY[j], ARRAY[j+1], TYPE)\
        }\
    }\
}

int main(){
    int array[5] = {1, 4, 3, 2, 5};

    SORT(array, 5, int, <)

    for(int i = 0; i<5; i++){
        printf("%d\n", array[i]);
    }
}