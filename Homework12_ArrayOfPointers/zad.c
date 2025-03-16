#include <stdio.h>
#include<stdlib.h>

char * readLine() {
    char currentChar = '\0';
    char * line = NULL;
    int size = 0;


    do {
        currentChar = getchar();
        size++;
        
        char * curLine = realloc(line, size * sizeof(char));
        if (curLine == NULL) {
            printf("\nError allocating memory(readLine)");
            exit(1);
        }
        line = curLine;
        line[size-1] = currentChar;
    } while(currentChar != '\n' && size != 16);

        line[size-1] = '\0';

    return line;
}



char ** newStudent(char ** classBook, char ** nameBook, float ** yearGradesBook, int * ammountOfStudents){

    printf("\nEnter the student's name(max 15 characters): ");
    char * newName = readLine();
    (*ammountOfStudents)++;
    

    if (nameBook == NULL) {
        nameBook = (char **)malloc(sizeof(char *) * (*ammountOfStudents));
    }else{
        nameBook = (char **)realloc(nameBook, sizeof(char *) * (*ammountOfStudents));
    }

    if (nameBook == NULL) {
        printf("\nError allocating memory");
        exit(1);
    }
    nameBook[(*ammountOfStudents) - 1] = newName;
    

    return nameBook;
};

float ** newGrade(char ** classBook, char ** nameBook, float ** yearGradesBook, int * ammountOfStudents, int * ammountOfSubjects){

    if (yearGradesBook == NULL) {
        yearGradesBook = (float **)malloc(sizeof(float *) * (*ammountOfStudents));
    }else{
        yearGradesBook = (float **)realloc(yearGradesBook, sizeof(float *) * (*ammountOfStudents));
    }

    if (yearGradesBook == NULL) {
        printf("\nError allocating memory");
        exit(1);
    }


    yearGradesBook[(*ammountOfStudents) - 1] = (float *)malloc(sizeof(float)*(*ammountOfSubjects));
    if(yearGradesBook[(*ammountOfStudents) - 1] == NULL){
        printf("Error in Reallocating memory(newGrade)");
        exit(1);
    }

    for(int i = 0; i < (*ammountOfSubjects); i++){
        printf("Enter the yearly grade of %s for the subject '%s': ", nameBook[(*ammountOfStudents) - 1], classBook[i]);
        scanf("%f", &yearGradesBook[(*ammountOfStudents) - 1][i]);
    }

    return yearGradesBook;
};

void printClassBook(char ** classBook, char ** nameBook, float ** yearGradesBook, int * ammountOfStudents, int * ammountOfSubjects){
    printf("\n|%-15s|", "Students");
    for(int i = 0; i < (*ammountOfSubjects); i++){
        printf("%-15s|", classBook[i]);
    }

  
    for(int i = 0; i < (*ammountOfStudents); i++){
        printf("\n|%-15s|", nameBook[i]);
        for(int j = 0; j < (*ammountOfSubjects); j++){
            printf("%-15.2f|", yearGradesBook[i][j]);
        }
    }

}




int main(){
    int ammountOfSubjects = 0;
    int input = 0;
    int ammountOfStudents = 0;


    do{
        printf("\nEnter the ammount of classes: ");
        scanf("%d", &ammountOfSubjects);
        getchar();

        if(ammountOfSubjects<=0){
            printf("\n The ammount of classes must be above 0, try again");
        }
    }while(ammountOfSubjects <=0);

    char **classBook = (char **)malloc(sizeof(char*)*ammountOfSubjects);
    if(classBook == NULL){
        printf("\nError in allocating memory(main)");
        exit(1);
    }
    
    for(int i = 0; i < ammountOfSubjects; i++){
        printf("Enter a subject's name(max 15 characters): ");
        classBook[i] = readLine();
    }

    char **nameBook = NULL;

    float **yearGradeBook = NULL;

    do{

        printf("\nuse 1-3 to navigate trough the interface");
        printf("\n1. New student");
        printf("\n2. Classbook");
        printf("\n3. Exit");
        printf("\nInput: ");
        scanf("%d", &input);
        getchar();

        switch(input){

        case 1:
            nameBook = newStudent(classBook, nameBook, yearGradeBook, &ammountOfStudents);
            yearGradeBook = newGrade(classBook, nameBook, yearGradeBook, &ammountOfStudents, &ammountOfSubjects);
            break;
  
        case 2:
            printClassBook(classBook, nameBook, yearGradeBook, &ammountOfStudents, &ammountOfSubjects);
            break;

        case 3:
            break;

        default:
            printf("\n Invalid Input");
            exit(1);
            break;
        }
        
    }while(input != 3);


    for(int i = 0; i < ammountOfSubjects; i++){
        free(classBook[i]);
    }
    free(classBook);

    for(int i = 0; i < ammountOfStudents; i++){
        free(nameBook[i]);
    }
    free(nameBook);

    for(int i = 0; i < ammountOfStudents; i++){
        free(yearGradeBook[i]);
    }
    free(yearGradeBook);


    return 0;
}