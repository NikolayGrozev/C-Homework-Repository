#ifndef SCHOOLCLASS_H_
#define SCHOOLCLASS_H_

#include "person.h"

struct SchoolClass{
    char classChar;
    int classNumber;
    struct Person HeadTeacher;
    struct Person Students[26];
};

#endif

