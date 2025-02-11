#include <stdio.h>
#include <math.h>

void function(long int *arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = pow(arr[i], 4);
    }
}

int main(){
    long int arr[] = {4, 3, 7, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Before\n");
    for(int i = 0; i < size; i++){
        printf("%ld\n", arr[i]);
    }

    function(arr, size);

    printf("After\n");
    for(int i = 0; i < size; i++){
        printf("%ld\n", arr[i]);
    }    

}