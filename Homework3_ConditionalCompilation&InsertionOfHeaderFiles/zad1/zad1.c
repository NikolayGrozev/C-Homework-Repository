#include <stdio.h>

#define DEBUG

int Function(int *array, int size){
    int swapVariable = 0;
    int isSorted = 0;
    int sum = 0;

    for(int counter = 0; counter < size && !isSorted; counter++){
    isSorted = 1;
        for(int index = 0; index < size - 1; index++){
            if(array[index] > array[index+1]){
                swapVariable = array[index];
                array[index] = array[index+1];
                array[index+1] = swapVariable;
                isSorted = 0;
            }
        }
    }

    for(int i = 0; i < size; i++){
        if(i % 3 == 0){
            sum += array[i];
        }
    }

    return sum;
}


int main(){
    int array[] = {1, 4, 10, 8, 5};
    int size = sizeof(array)/sizeof(array[0]);


    #ifdef DEBUG
        printf("\nThe sum is: %d", Function(array, size));
    #endif

    return 0;
}