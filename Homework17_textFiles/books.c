#include <stdio.h>
#include <stdlib.h>

#include "books.h"

static void index_check(dynArr * arr, uint index){
    if((arr->size - 1) < index || index < 0){
        printf("Invalid Index");
        exit(1);
    }
};

dynArr init(uint initial_capacity){
    if(initial_capacity < 0){
        printf("Invalid Capacity");
        exit(1);
    } else {

        dynArr new_arr = {
            .buffer = NULL,
            .capacity = initial_capacity,
            .size = 0
        };
    
        new_arr.buffer = malloc(sizeof(Book) * new_arr.capacity);
        if(new_arr.buffer == NULL){
            printf("Error in allocating memory");
            exit(1);
        }
        return new_arr;
    }
};

static void resize(dynArr * arr, uint newSize){
    if (newSize > arr->capacity) {
        if (arr->capacity == 0) {
            arr->capacity = 1;
        }

        while (arr->capacity <= newSize) {
            arr->capacity *= 2;
        }
    } else if (newSize <= arr->capacity / 2) {
        arr->capacity = newSize;
    }

    if (arr->capacity == 0) {
        free(arr->buffer);
    } else {
        Book * temp = realloc(arr->buffer, arr->capacity * sizeof(Book));
        if(temp == NULL){
            printf("Error in reallocating memory");
            exit(1);
        }
        arr->buffer = temp;
    }

    arr->size = newSize;
};


void pop(dynArr * arr, uint index){
    index_check(arr, index);

    uint newSize = arr->size-1;

    for(uint i = index; i < newSize; i++){
        arr->buffer[i] = arr->buffer[i+1];
    }
    resize(arr, newSize);
};

void pushback(dynArr * arr, Book book){
    uint newSize = arr->size+1;
    resize(arr, newSize);
    arr->buffer[newSize-1] = book;
};

void release(dynArr * arr){
    free(arr->buffer);
    arr->capacity = 0;
    arr->size = 0;
};
