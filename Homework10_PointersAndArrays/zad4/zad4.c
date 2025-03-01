#include <stdio.h>

#define ROWS 2
#define COLUMNS 4

void printTable(int (*doubleArr)[COLUMNS], int rowCount){

    printf("| C1 | C2 | C3 | C4 |\n");

    for(int i = 0; i < rowCount ; i++){
        
        for(int j = 0; j < COLUMNS ; j++){
            printf("| %d  ", *(*(doubleArr+i) + j));
        }
        printf("|\n");
    }

}


int main(){
    int arr[ROWS][COLUMNS] = {
        {1, 6, 3, 9},
        {5, 6, 7, 8}
    };

    printTable(arr, ROWS);


    return 0;
}