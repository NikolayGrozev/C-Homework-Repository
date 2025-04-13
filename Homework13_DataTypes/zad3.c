#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum MenuOptions{
    ADD_NEW_STUDENT = 1,
    LIST_OF_STUDENTS,
    EXIT_PROGRAM
} menuOptions;

typedef struct StudentStructure{
    char name[15];
    short classNumber;
    double averageGrade;
} Student;

short getNameSize(char * name){
    short size = 0;

    for(int i = 0; name[i] != '\0'; i++){
        size++;
    }

    return size;
}

Student CreateNewStudent(){
    char name[15];
    short classNumber;
    double averageGrade;


    printf("\nEnter the new student's name(max 15 characters): ");
    scanf("%s", name);

    printf("\nEnter the new student's classNumber: ");
    scanf("%hd", &classNumber);

    printf("\nEnter the new student's average grade: ");
    scanf("%lf", &averageGrade);

    Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.classNumber = classNumber;
    newStudent.averageGrade = averageGrade;

    return newStudent;
}

Student * addNewStudent(Student * studentsList, short * ammountOfStudents){

    if(*ammountOfStudents == 0){
        studentsList = (Student*)malloc(sizeof(Student));
        if(studentsList == NULL){
            printf("\nError in allocating memory");
            exit(1);
        }
        (*ammountOfStudents)++;
    }else{
        (*ammountOfStudents)++;
        studentsList = realloc(studentsList, sizeof(Student) * (*ammountOfStudents));
        if(studentsList == NULL){
            printf("\nError in reallocating memory");
            exit(1);
        }
    }

    studentsList[*ammountOfStudents - 1] = CreateNewStudent();

    return studentsList;
}

void printStudents(Student * studentsList, short ammountOfStudents){
    if(studentsList == NULL){
        printf("\nThere are no students yet, create some to see them sorted in a table ");
    }else{
        printf("\n|%-15s|%-15s|%-15s|", "Name", "Class Number" ,"Average Grade");
        for(int i = 0; i < ammountOfStudents; i++){
            printf("\n|%-15s|%-15hd|%-15.2lf|", studentsList[i].name, studentsList[i].classNumber, studentsList[i].averageGrade);
        }
    }
}

int main(){
    short input = 0;

    Student * studentsList = NULL;
    short ammountOfStudents = 0;

    menuOptions options;

    char programIsRunning = 1;

    while(programIsRunning){

        do{
            printf("\n1. Add a new student");
            printf("\n2. List of students");
            printf("\n3. Exit");
            printf("\nInput: ");
            scanf("%hd", &input);
            if(input < 1 || input > 3){
                printf("\nInvalid input");
                continue;
            }
        }while(input < 1 || input > 3);
        
        options = input;
    
        switch(options){
            case ADD_NEW_STUDENT:
                studentsList = addNewStudent(studentsList, &ammountOfStudents);
                break;
            case LIST_OF_STUDENTS:
                printStudents(studentsList, ammountOfStudents);
                break;
            case EXIT_PROGRAM:
                programIsRunning = 0;
                break;
            default:
                printf("\ninvalid input in switch(options)");
        }
    }
    
    free(studentsList);

    return 0;
}