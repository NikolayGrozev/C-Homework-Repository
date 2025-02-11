#include <stdio.h>

int differentOsSorter(int *array, int size){
    #ifdef _WIN32
        printf("Windows\n");

        int isSorted = 0;
        int swapVariable = 0;

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

    #elif defined __linux__
        printf("Linux\n");

        int minIndex = 0;
        int swapperVar = 0;

        for(int i = 0; i < size-1; i++){
            minIndex = i;
            for(int j = i+1; j < size; j++){
                if(array[j] < array[minIndex]){
                    minIndex = j;
                }
            }
            swapperVar = array[i];
            array[i] = array[minIndex];
            array[minIndex] = swapperVar;

        }
    #elif defined __APPLE__
        printf("MacOS\n");

        int key = 0;
        int j = 0;

    for (int i = 1; i < size; ++i) {
        key = array[i];
        // key = 0
        j = i - 1;
        // j = 2

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    #else
        printf("Not Windows, Linux or MacOS\n");

        int pointer1 = 0;
        int pointer2 = size - 1;
        int swapperVar = 0;
        
        for(int i = 0; i < size/2; i++){
            swapperVar = array[pointer1];
            array[pointer1] = array[pointer2];
            array[pointer2] = swapperVar;
            pointer1++;
            pointer2--;
        }
    #endif
}

int main(){
    int array[] = {4, 0, -3, 5, 9};
    int size = sizeof(array)/sizeof(array[0]);

    for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }

    differentOsSorter(array, size);

    for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }

    return 0;
}