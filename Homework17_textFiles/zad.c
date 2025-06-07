#include <stdio.h>
#include <stdlib.h>

#include "books.h"

typedef enum{
    NEW_BOOK = 1,
    LIST_BOOKS,
    DELETE_BOOK,
    SAVE_IN_FILE,
    EXIT
} options;

void removeNewLine(char * string){
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == '\n'){
            string[i] = '\0';
            return;
        }
    }
};



void new_book(dynArr * books){
    Book newBook;

    printf("\nEnter the name of the book: ");
    fgets(newBook.name, 30, stdin);
    printf("\nEnter the name of the book's author: ");
    fgets(newBook.author, 30, stdin);
    printf("\nEnter the book's genre: ");
    fgets(newBook.genre, 10, stdin);
    printf("\nEnter the year when the book was published: ");
    scanf("%hd", &(newBook.year_published));
    printf("\nEnter the ISBN number of the book: ");
    scanf("%ld", &(newBook.ISBN_number));

    removeNewLine(newBook.name);
    removeNewLine(newBook.author);
    removeNewLine(newBook.genre);

    pushback(books, newBook);
};

void list_books(dynArr * books){
    if(books->size == 0){
        printf("There are currently no books stored");
    } else{
        printf("\nList of books");
        printf("\n|%-30s|%-30s|%-10s|%-10s|%-15s|", "Book", "Author", "genre", "Published", "ISBN number");
    
        for(uint i = 0; i < books->size; i++){
            printf("\n|%-30s|%-30s|%-10s|%-10hd|%-15ld|", 
                books->buffer[i].name, 
                books->buffer[i].author,
                books->buffer[i].genre,
                books->buffer[i].year_published,
                books->buffer[i].ISBN_number
            );
        }
    
        printf("\n");
    }
};

short is_ISBN_valid(dynArr * books, long * number){
    for(uint i = 0; i < books->size; i++){
        if(books->buffer[i].ISBN_number == *number){
            return 1;
        }
    }
    return 0;
}

void delete_book(dynArr * books){
    long answer = 0;
    if(books->size == 0){
        printf("\nThe book list is empty, add a new book to be able to delete it");
        return;
    }

    do{
        printf("\nDelete Book");
        printf("\nISBN number of book to delete: ");
        scanf("%ld", &answer);
        if(is_ISBN_valid(books, &answer)){
            break;
        } else{
            printf("\nNo such book with this ISBN exists");
            return;
        }
    }while(1);

    uint index = 0;

    for(uint i = 0; i < books->size; i++){
        if(books->buffer[i].ISBN_number == answer){
            printf("Succesfully deleted the book with the ISBN number: %ld", books->buffer[i].ISBN_number);
            pop(books, i);
            break;
        }
    }
};

void save_in_file(dynArr * books){
    FILE * capacityFile = fopen("capacity.txt", "w");
    if(capacityFile == NULL){
        printf("Error in opening file");
        exit(1);
    }
    fprintf(capacityFile, "%u", books->capacity);
    fclose(capacityFile);


    FILE * booksFile = fopen("books.txt", "w");
    if(booksFile == NULL){
        printf("Error in opening file");
        exit(1);
    }

    for(uint i = 0; i < books->size; i++){
        fprintf(booksFile, "%s %s %s %hd %ld \n",
            books->buffer[i].name,
            books->buffer[i].author,
            books->buffer[i].genre,
            books->buffer[i].year_published,
            books->buffer[i].ISBN_number
        );
    }

    fclose(booksFile);
};

dynArr read_Initial_file_information(){
    FILE * capacityFile = fopen("capacity.txt", "r");
    if(capacityFile == NULL){
        printf("Error in opening file");
        exit(1);
    }

    uint init_capacity = 0;

    fscanf(capacityFile, "%u", &init_capacity);
    fclose(capacityFile);

    dynArr books = init(init_capacity);

    FILE * booksFile = fopen("books.txt", "r");
    if(booksFile == NULL){
        printf("Error in opening file");
        exit(1);
    }

    int firstChar = fgetc(booksFile);


    if(firstChar == EOF){
        fclose(booksFile);
    } else {
        rewind(booksFile);
        Book * temp = malloc(sizeof(Book) * books.capacity);
        if(temp == NULL){
            printf("Error in allocating memory");
            exit(1);
        }

            for (uint i = 0; i < books.capacity; i++) {
                if (fscanf(booksFile, "%29s %29s %9s %hd %ld", 
                        temp[i].name,
                        temp[i].author,
                        temp[i].genre,
                        &temp[i].year_published,
                        &temp[i].ISBN_number) == EOF) {
                    break;
                }
                books.size++;
            }
        fclose(booksFile);
        books.buffer = temp;
    }

    return books;
};

int main(){
    short input;
    short programIsRunning = 1;



    dynArr books = read_Initial_file_information();



    while(programIsRunning){
        do{
            printf("\nLibrary");
            printf("\n1. New Book");
            printf("\n2. List Books");
            printf("\n3. Delete Book");
            printf("\n4. Save in file");
            printf("\n5. Exit");
            printf("\nInput: ");
            scanf("%hd", &input);
            getchar();
    
            if(input < 1 && input > 5){
                printf("\nInvalid Input, please use 1-5");
            } else{
                break;
            }
    
        }while(1);
    
        options answer = input;
    
        switch (answer)
        {
            case NEW_BOOK:
                new_book(&books);
                break;
            case LIST_BOOKS:
                list_books(&books);
                break;
            case DELETE_BOOK:
                delete_book(&books);
                break;

            case SAVE_IN_FILE:
                save_in_file(&books);
                break;
            case EXIT:
                programIsRunning = 0;
                break;
            default:
                printf("\nInvalid Answer");
                break;
        }
    }

    release(&books);

    return 0;
}