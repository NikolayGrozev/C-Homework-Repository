#include <stdio.h>

int getStringSize(char * string){
    int size = 0;

    for(int i = 0; *(string + i) != '\0'; i++){
        size++;
    }

    return size;
}


int main(){
    char str[] = "Ivan";

    printf("%d", getStringSize(str));



    return 0;
}