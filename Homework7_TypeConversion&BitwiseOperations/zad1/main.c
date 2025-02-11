#include <stdio.h>
#include "quadraticroots.h"
#include <math.h>

int main(){
    int a = 3;
    int b = 2;
    int c = -2;

    float a2 = 6.6;
    float b2 = 8;
    float c2 = 9.3;

    double a3 = 6.73;
    double b3 = 8.55;
    double c3 = 9.3457;

    struct QuadraticRootsResult Result1 = findroots((double)a, (double)b, (double)c);
    struct QuadraticRootsResult Result2 = findroots((double)a2, (double)b2, (double)c2);
    struct QuadraticRootsResult Result3 = findroots((double)a3, (double)b3, (double)c3);

    printf("\nResult1: X1 = %lf, X2 = %lf, noRealRoots = %d\n", Result1.x1, Result1.x2, Result1.noRealRoots);
    printf("Result2: X1 = %lf, X2 = %lf, noRealRoots = %d\n", Result2.x1, Result2.x2, Result2.noRealRoots);
    printf("Result3: X1 = %lf, X2 = %lf, noRealRoots = %d\n", Result3.x1, Result3.x2, Result3.noRealRoots);

    // double test = 4;

    // printf("%f", sqrt(test));

    return 0;
}