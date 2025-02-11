#ifndef SAFEINT_H_
#define SAFEINT_H_

    struct SafeResult{
        int value;
        int error;
    };
    struct SafeResult safeadd();
    struct SafeResult safesubtract();
    struct SafeResult safemultiply();
    struct SafeResult safedivide();
    struct SafeResult safestrtoint();

#endif