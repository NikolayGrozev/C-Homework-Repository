#include <stdio.h>

int main() {
    double x1;
    double x2;

    printf("\nEnter the First Variable's Value: ");
    scanf("%lf", &x1);

    printf("\nEnter the Second Variable's Value: ");
    scanf("%lf", &x2);

    double * pointer1 = &x1;
    double * pointer2 = &x2;

    printf("\nThe Adress that pointer1 holds is: %p and the value it points to is: %lf", pointer1, *pointer1);
    printf("\nThe Adress that pointer2 holds is: %p and the value it points to is: %lf", pointer2, *pointer2);

}