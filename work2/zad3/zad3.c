#include <stdio.h>

#define DEBBUGER(X) \
printf("\nName of Variable: " #X);\
printf("\nValue of Variable: %d", X);\
printf("\nUsed in file: %s", __FILE__);\
printf("\nLine: %d", __LINE__);

int main(){
    int SOMETHING = 1;

    DEBBUGER(SOMETHING);
}