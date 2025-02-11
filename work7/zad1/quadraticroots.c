#include "quadraticroots.h"
#include <math.h>


struct QuadraticRootsResult findroots(double a, double b, double c){
    struct QuadraticRootsResult Result = {0, 0, 0};

    double Discriminant = b*b - (4*a*c);

    if(Discriminant < 0 || a == 0){
        Result.noRealRoots = 1;
    } else {
        Result.x1 =(-b + sqrt(Discriminant))/2*a;
        Result.x2 =(-b - sqrt(Discriminant))/2*a;
    }

    return Result;
};