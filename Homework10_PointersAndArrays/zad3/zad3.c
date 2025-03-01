#include <stdio.h>

void strhalf(char * str, char **doublePointer){
    int size = 0;

    for(int i = 0; *(str+i) != '\0'; i++){
        size++;
    }

    *doublePointer = str + size/2;

}


int main(){
    char initial = 'i';
    char str[] = "Niki";
    char * pointer = &initial;

    strhalf(str, &pointer);

    printf("%s", pointer);

    return 0;
}