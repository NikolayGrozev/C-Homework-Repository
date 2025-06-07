#ifndef BOOKS_H_
#define BOOKS_H_

typedef unsigned int uint;

typedef struct{
    char name[30];
    char author[30];
    char genre[10];
    short year_published;
    long ISBN_number;
} Book;

typedef struct{
    Book * buffer;
    uint size;
    uint capacity;
} dynArr;

dynArr init(uint initial_capacity);

void pop(dynArr * arr, uint index);
void pushback(dynArr * arr, Book book);

void release(dynArr * arr);


#endif