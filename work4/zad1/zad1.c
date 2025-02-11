#include <stdio.h>

#define SQUAREOFSUM(A, B) ((A+B)*(A+B))

int main(){
    int a = 1;
    int b = 2;

    printf("%d", SQUAREOFSUM(a, b));

    return 0;
}