#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"
#include "util.h"

typedef enum{
    NEW_USER = 1,
    DELETE_USER,
    GET_PINS,
    EXIT
} options;

void deleteUser(DynamicArray * arr){
    if(arr->size > 0){
        DynArrType input;
        printf("\nEnter the PIN of the user you want to delete from the list");
        printf("\nPIN: ");
        scanf("%d", &input);
    
        int index = getElementByValue(arr, input);
        if(index != -1){
            pop(arr, 1);
            printf("\nSucessfully deleted a user with the PIN: %d", input);
        }else{
            printf("\nNo user with the PIN: %d has been found", input);
        }
    } else{
        printf("\nThere are currently no PINS recorded on the list");
    }
};

void newUser(DynamicArray * arr){
    DynArrType input;
    printf("\nWhat will be the PIN of the new user?");
    printf("\nPIN: ");
    scanf("%d", &input);

    pushBack(arr, input);
};

void getPins(DynamicArray * arr){
    if(arr->size > 0){
        printf("\nHere are all of the PINS:");
        printf("\n---------------------------------------------------");
        for(uint i = 0; i < arr->size; i++){
            printf("\n%d. %d", (i+1), arr->buffer[i]);
        }
        printf("\n---------------------------------------------------");
    }else{
        printf("\nThere are currently no PINS recorded on the list");
    }
};

int main(){

    short isProgramRunning = 1;

    uint initialCapacity = 0;
    DynamicArray Pins = init(initialCapacity);

    short input = 0;
    options Answer;

    while(isProgramRunning){

        do{
            printf("\n1. New user");
            printf("\n2. Delete user");
            printf("\n3. Get Pins");
            printf("\n4. Exit");
            printf("\nInput: ");
            scanf("%hd", &input);
            if(input < 1 && input > 4){
                printf("\nInvalid input");
            }else{
                break;
            }
        }while(1);

        Answer = input;

        switch(Answer){
            case NEW_USER:
                newUser(&Pins);
                break;
            case DELETE_USER:
                deleteUser(&Pins);
                break;
            case GET_PINS:
                getPins(&Pins);
                break;
            case EXIT:
                isProgramRunning = 0;
                break;
            default: printf("\n Invalid Answer");
        }

    }

    release(&Pins);

    return 0;
}