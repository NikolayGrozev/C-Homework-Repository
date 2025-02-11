// #include <stdio.h>

// #define CREATE_NAME(PREDICATE, NAME) PREDICATE ## NAME
// #define DEBUG_INT(X) printf("The value of " #X " is %d\n", X);

// int main(void) {

//   int infoLog = 5;
//   DEBUG_INT(CREATE_NAME(info, Log));

//   return 0;
// }

#include <stdio.h>

#define COMMAND(NAME, TYPE) TYPE ## _ ## NAME ##_##command
#define DEFINE_COMMAND(NAME, TYPE)\
    void COMMAND(NAME, TYPE)(void){\
        printf("\nThis is the command with the name " #NAME " and type " #TYPE);  \
    }


    DEFINE_COMMAND(quit, internal);
    DEFINE_COMMAND(quit, external);

int main(){
    internal_quit_command();
    external_quit_command();
}