#include <stdio.h>
#include <stdlib.h>

float average(float * arr, int size){
    float sum = 0;
    float result = 0;

    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    result = sum / size;

    return result;
}

void printGrades(float * arr, int size){
    printf("\nGrades: ");

    for(int i = 0; i < size; i++){
        printf("grade %d: [ %.2f ] ", i+1, arr[i]);
    }

    printf("\n");
}

float * deleteGrade(float * arr, int * size){
    if(size == 0){
        printf("\nThere are no grades to delete");
        return arr;
    }

    (*size)--;

    arr = (float *)realloc(arr, sizeof(float) * (*size));
    if(arr == NULL){
        printf("\nError in Reallocating memory(deleteGrade)");
        exit(1);
    }

    return arr;
}

float * addGrade(float * arr, int * size){
    float newGrade = 0;

    (*size)++;

    do{
        printf("\nEnter the new grade: ");
        scanf("%f", &newGrade);
        if(newGrade < 2 || newGrade > 6){
            printf("\nGrade must be between 2 and 6, try again");
        }
    }while(newGrade < 2 || newGrade > 6);

    arr = (float *)realloc(arr, sizeof(float) * (*size));
    if(arr == NULL){
        printf("\nError in Reallocating memory(addGrade)");
        exit(1);
    }

    arr[(*size)-1] = newGrade;

    return arr;
}




int main(){
    int gradesCount = 0;
    int input = 0;

    do{
        printf("Enter the ammount of grades:");
        scanf("%d", &gradesCount);
        printf("\n");
        if(gradesCount < 0){
            printf("\nInvalid Value, please try again (The ammount of grades can't be negative)");
        }
    }while(gradesCount < 0);
    getchar();

    float * grades = (float *)malloc( sizeof(float) * gradesCount );
    if(grades == NULL){
        printf("\nError in allocating memory for the grades");
        exit(1);
    }

    for(int i = 0; i < gradesCount; i++){
        printf("\nEnter grade %d: ", i+1);
        scanf("%f", grades + i);
        if(grades[i] < 2 || grades[i] > 6){
            printf("Grade must be between 2 and 6, try again");
            i--;
            continue;
        }
    }

    do{

        printf("\nUse 1-4 and enter to navigate trough the interface");
        printf("\n1. Average");
        printf("\n2. Add grade");
        printf("\n3. Delete last grade");
        printf("\n4. Exit");
        printf("\nInput: ");
        scanf("%d", &input);
        printf("\n");

        switch(input){
            case 1: 
                printf("\nThe average grade is: %.2f", average(grades, gradesCount));
                printGrades(grades, gradesCount);
                break;
            case 2:
                printf("\nGrades before addition:");
                printGrades(grades, gradesCount);
                
                grades = addGrade(grades, &gradesCount);

                printf("\nGrades after addition:");
                printGrades(grades, gradesCount);

                break;
            case 3:
                printf("\nGrades before deletion:");
                printGrades(grades, gradesCount);
                
                grades = deleteGrade(grades, &gradesCount);

                printf("\nGrades after deletion:");
                printGrades(grades, gradesCount);

                break;
            default: break;
        }


    } while(input != 4);


    free(grades);


    return 0;
}