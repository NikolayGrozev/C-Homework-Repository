#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

struct Transformation{
    long int result;
    char error[100];
};

struct Transformation TransformerFunction(char *arr, int size);

#endif