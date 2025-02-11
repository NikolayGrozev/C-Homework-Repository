#include <stdio.h>

#define COMMAND(NAME, TYPE) TYPE ## NAME

#define SWAP(A, B, TYPE)\
    { \ 
        TYPE swapper = A;\
         A = B; \
        B = swapper; \
    }

int main(){
    int a = 1;
    int b = 5;

    SWAP(a, b, int);

    printf("%d\n", a);
    printf("%d\n", b);

    char c = 'b';
    char d = 'k';

    SWAP(c, d, char);

    printf("%c\n", c);
    printf("%c\n", d);
}