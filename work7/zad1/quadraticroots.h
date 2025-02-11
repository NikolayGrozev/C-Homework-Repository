#ifndef QUADRATICROOTS_H_
#define QUADRATICROOTS_H_

    struct QuadraticRootsResult{
        double x1;
        double x2;
        char noRealRoots;
    };

    struct QuadraticRootsResult findroots(double a, double b, double c);

#endif