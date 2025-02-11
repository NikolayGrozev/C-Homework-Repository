#include <stdio.h>
#include "transformation.h"

int main(){
    char mishka[6] = "-54472";
    char mishka2[3] = "--1";

    struct Transformation b = TransformerFunction(mishka2, 3);
    struct Transformation a = TransformerFunction(mishka, 6);

    printf("\nresult a: %d", a.result);
    printf("\nerror a: %s", a.error);

    printf("\nresult b: %d", b.result);
    printf("\nerror b: %s", b.error);


    return 0;
}