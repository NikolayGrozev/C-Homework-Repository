#include <stdlib.h>
#ifndef CITIZEN_H_
#define CITIZEN_H_

typedef enum {
    NONE = 1,
    PRIMARY_EDUCATION,
    SECONDARY_EDUCATION,
    HIGH_EDUCATION
} Education;

typedef enum{
    WORKING = 1,
    NOT_WORKING
} WorkingStatus;

typedef enum{
    MARRIED = 1,
    UNMARRIED
} Marriage;

typedef struct {
    long EGN;
    short nameLength;
    char name[255];
    short age;
    Education education;
    WorkingStatus workingStatus;
    Marriage marriageStatus;
} citizen;



#endif