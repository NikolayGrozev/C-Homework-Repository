#include <stdio.h>


#define SIZE 5


void swap(void * p1, void * p2){
    int temp = *((int *)p1);

    *((int *)p1) = *((int *)p2);
    *((int *)p2) = temp;
};

int compareasc(void * const  pointer1, void * const pointer2){

    if(  *((int *)pointer1) > *((int *)pointer2) ){
        return 1;
    }
    else if( *((int *)pointer1) < *((int *)pointer2) ){
        return -1;
    }

    return 0;
}

int comparedesc(void * const  pointer1, void * const pointer2){

    if(  *((int *)pointer1) < *((int *)pointer2) ){
        return 1;
    }
    else if( *((int *)pointer1) > *((int *)pointer2) ){
        return -1;
    }

    return 0;
}


void bubblesort(int * arrayPointer, int size, int (*compare)(void*, void*), void (*swapelements)( void*, void* )){

    for(int i = 0; i < size-1; i++){
        for( int j = 0; j < size-i-1; j++){
            if(compare( &arrayPointer[j] , &arrayPointer[j+1]) == 1 ){
                swapelements(&arrayPointer[j], &arrayPointer[j+1]);
            }
        }
    }
}

int main(){
    int a = 1;
    int b = -1;

    void * const p1 = &a;
    void * const p2 = &b;

    printf("\nCompareasc using 1 and -1: %d", compareasc(p1, p2));
    printf("\nCompareasc using -1 and 1: %d", compareasc(p2, p1));
    printf("\nCompareasc using 1 and 1: %d", compareasc(p1, p1));

    printf("\n");

    printf("\nComparedesc using 1 and -1: %d", comparedesc(p1, p2));
    printf("\nComparedesc using -1 and 1: %d", comparedesc(p2, p1));
    printf("\nComparedesc using 1 and 1: %d", comparedesc(p1, p1));

    printf("\n");

    int arr[SIZE] = {4, 3, 8, 2, 9};

    printf("\nArray before sorting :[");
    for(int i = 0; i < SIZE; i++){
        printf(" %d ", arr[i]);
    }
    printf("]");


    bubblesort(arr, SIZE, compareasc, swap);


    printf("\nbubblesort with compareasc : [");
    for(int i = 0; i < SIZE; i++){
        printf(" %d ", arr[i]);
    }
    printf("]");


    bubblesort(arr, SIZE, comparedesc, swap);


    printf("\nbubblesort with comparedesc : [");
    for(int i = 0; i < SIZE; i++){
        printf(" %d ", arr[i]);
    }
    printf("]");

    return 0;
}