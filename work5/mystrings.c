#include "mystrings.h"

int strlength(char str[]){
    int size = 0;
    for(int i = 0; str[i] != '\0'; i++){
        size++;
    }

    return size;
}

void strconcat(char *str1, char *str2){
    int size1 = strlength(str1);
    int size2 = strlength(str2);

    for(int i = 0; i < size2+1; i++){
        str1[size1 + i] = str2[i];
    }
}

int strcompare(char *str1, char *str2){
    int comparisson = 0;
    int size1 = strlength(str1);
    int size2 = strlength(str2);

    for(int i = 0; i <= size1 || i <= size2; i++){
        if(str1[i] < str2[i]){
            comparisson = -1;
            break;
        } else if(str1[i] > str2[i]){
            comparisson = 1;
            break;
        }
    }

    return comparisson;
};

