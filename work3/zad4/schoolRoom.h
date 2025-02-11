#ifndef SCHOOLROOM_H_
#define SCHOOLROOM_H_

#include "person.h"

struct SchoolRoom{
    int roomNumber;
    struct Person currentPeopleInside[50];
};

#endif