#include <stdio.h>

#define SIZE 5

void swap(int * p1, int * p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort(int * arr, int size){

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                swap( arr+j, arr+j+1 );
            }
        }
    }

}

int main(){
    int arr[SIZE] = {3, 2, 7, 1, 9};

    printf("[");
    for(int i = 0; i < SIZE; i++){
        printf(" %d ", arr[i]);
    }
    printf("]\n");

    sort(arr, SIZE);

    printf("[");
    for(int i = 0; i < SIZE; i++){
        printf(" %d ", arr[i]);
    }
    printf("]");



    return 0;
}