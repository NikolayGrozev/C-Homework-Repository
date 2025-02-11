#include <stdio.h>
#include "schoolclass.h"
#include "schoolRoom.h"

struct School{
    struct SchoolClass Classes[20];
    struct SchoolRoom Rooms[10];
};

int main(){
    struct School School1;

    return 0;
}