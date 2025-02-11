#include <stdio.h>

#define FUNCTION_MARCO(A, B) (A < B) ? (B) : (A)

int main(){
    int a = 1;
    int b = 2;

    int max = FUNCTION_MARCO(a, b);

    printf("%d", max);

    return 0;
}