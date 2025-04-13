#include <stdio.h>

typedef enum week{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} weekDay;

int main(){
    short input = 0;
    do{
        printf("\nEnter a weekday 1-7: ");
        scanf("%hd", &input);
    }while(input < 1 || input > 7);

    weekDay day = input;

    switch (day){
        case MONDAY:
            printf("\nToday is Monday!");
            break;
        case TUESDAY:
            printf("\nToday is Tuesday!");
            break;
        case WEDNESDAY:
            printf("\nToday is Wednesday!");
            break;
        case THURSDAY:
            printf("\nToday is Thursday!");
            break;
        case FRIDAY:
            printf("\nToday is Friday!");
            break;
        case SATURDAY: 
            printf("\nToday is Saturday!");
            break;
        case SUNDAY:
            printf("\nToday is Sunday!");
            break;
        default: printf("invalid input");
    }

    return 0;
}