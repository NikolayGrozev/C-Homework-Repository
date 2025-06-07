#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "citizen.h"

typedef enum{
    LIST = 1,
    NEW_PERSON,
    DELETE_PERSON,
    EXIT_FILE
}options;

bool does_bin_file_exist(char * filename){
    FILE * file = fopen(filename, "rb");
    if(file == NULL){
        return false;
    }
    fclose(file);
    return true;
}

bool is_filename_valid(char * filename){
    short size = 0;

    for(int i = 0; filename[i] != '\0'; i++){
        size++;
    }

    if(size > 5 && (filename[size-4] == '.' && filename[size-3] == 'b' && filename[size-2] == 'i' && filename[size-1] == 'n')){
        return true;
    }

    return false;
}

citizen read_citizen(char * filename, FILE * file){

    citizen currCitizen;

    fread(&(currCitizen.EGN), sizeof(long), 1, file);
    fread(&(currCitizen.nameLength), sizeof(short), 1, file);
    fread(&(currCitizen.name), sizeof(char), currCitizen.nameLength, file);
    fread(&(currCitizen.age), sizeof(short), 1, file);
    fread(&(currCitizen.education), sizeof(Education), 1, file);
    fread(&(currCitizen.workingStatus), sizeof(WorkingStatus), 1, file);
    fread(&(currCitizen.marriageStatus), sizeof(Marriage), 1, file);

    return currCitizen;
};

int calculate_ammount_of_citizens(char * filename){
    FILE * file = fopen(filename, "rb");
    if(file == NULL){
        printf("\nError in opening file");
    }

    int ammountOfCitizens = 0;
    citizen c;
    
    while (1) {
        if (fread(&c.EGN, sizeof(long), 1, file) != 1) break;
        if (fread(&c.nameLength, sizeof(short), 1, file) != 1) break;
        if (fread(c.name, sizeof(char), c.nameLength, file) != c.nameLength) break;
        if (fread(&c.age, sizeof(short), 1, file) != 1) break;
        if (fread(&c.education, sizeof(Education), 1, file) != 1) break;
        if (fread(&c.workingStatus, sizeof(WorkingStatus), 1, file) != 1) break;
        if (fread(&c.marriageStatus, sizeof(Marriage), 1, file) != 1) break;

        ammountOfCitizens++;
    }

    fclose(file);

    return ammountOfCitizens;
};

void list(char * filename){
    int ammountOfCitizens = calculate_ammount_of_citizens(filename);
    citizen c;    

    FILE * file = fopen(filename, "rb");
    if(file == NULL){
        printf("\nError in opening file");
    }


    if(ammountOfCitizens){
    
        printf("\n List of poeple ");
        printf("\n|%-15s|%-50s|%-3s|%-12s|%-12s|%-12s|", "EGN", "Full Name", "age", "Education", "is Working", "is Married");
        for(long i = 0; i < ammountOfCitizens; i++){
            c = read_citizen(filename, file);

            printf("\n|%-15ld|%-50s|%-3hd|", c.EGN, c.name, c.age);
            
            if(c.education == NONE){
                printf("%-12s|", "None");
            } else if(c.education == PRIMARY_EDUCATION){
                printf("%-12s|", "Primary");
            } else if(c.education == SECONDARY_EDUCATION){
                printf("%-12s|", "Secondary");
            } else {
                printf("%-12s|", "High");
            }
    
            if(c.workingStatus == NOT_WORKING){
                printf("%-12s|", "no");
            } else{
                printf("%-12s|", "yes");
            }
    
            if(c.marriageStatus == UNMARRIED){
                printf("%-12s|", "no");
            } else {
                printf("%-12s|", "yes");
            }
        }
    } else {
        printf("\n Currently, no citizens are recorded in %s, consider adding some", filename);
    }
    
    fclose(file);
};

void new_person(char * filename){
    short input;
    citizen newPerson;

    printf("\n Enter the new person's EGN: ");
    scanf("%ld", &(newPerson.EGN));
    getchar();

    printf("\n Enter the new person's full name: ");
    fgets(newPerson.name, 255, stdin);
    for(short i = 0; newPerson.name[i] != '\0'; i++){
        if(newPerson.name[i] == '\n') {
            newPerson.name[i] = '\0';
            break;
        }
    }

    printf("\n Enter the new person's age: ");
    scanf("%hd", &(newPerson.age));
    getchar();

    while(1){
        printf("\nEnter the new person's education");
        printf("\n1. None");
        printf("\n2. Primary");
        printf("\n3. Secondary");
        printf("\n4. High");
        printf("\n Input: ");
        scanf("%hd", &input);
        getchar();

        if(input < 1 || input > 4){
            printf("\nInvalid Input, try 1-4");
        } else {
            break;
        }
    }
    newPerson.education = (Education)input;

    while(1){
        printf("\nIs the person currently working?");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nInput: ");
        scanf("%hd", &input);
        getchar();

        if(input < 1 || input > 2){
            printf("\nInvalid Input, try 1-2");
        } else {
            break;
        }
    }

    newPerson.workingStatus = (WorkingStatus)input;

    while(1){
        printf("\nIs the person currently married?");
        printf("\n1. Yes");
        printf("\n2. No");
        printf("\nInput: ");
        scanf("%hd", &input);
        getchar();

        if(input < 1 || input > 2){
            printf("\nInvalid Input, try 1-2");
        } else {
            break;
        }
    }

    newPerson.marriageStatus = (Marriage)input;

    FILE * file = fopen(filename, "ab");
    if(file == NULL){
        printf("\nError in opening file");
        exit(1);
    }

    short nameSize = 0;
    for(short i = 0; newPerson.name[i] != '\0'; i++){
        nameSize++;
    }

    newPerson.nameLength = nameSize+1;

    fwrite(&(newPerson.EGN), sizeof(long), 1, file);
    fwrite(&(newPerson.nameLength), sizeof(short), 1, file);
    fwrite(&(newPerson.name), sizeof(char), newPerson.nameLength, file);
    fwrite(&(newPerson.age), sizeof(short), 1, file);
    fwrite(&(newPerson.education), sizeof(Education), 1, file);
    fwrite(&(newPerson.workingStatus), sizeof(WorkingStatus), 1, file);
    fwrite(&(newPerson.marriageStatus), sizeof(Marriage), 1, file);



    fclose(file);
}

void delete_person(char * filename){
    long EGN_to_delete;
    citizen currCitizen;
    bool deleted = false;
    int ammountOfCitizens = calculate_ammount_of_citizens(filename);

    if(ammountOfCitizens == 0){
        printf("\n There are currently no citizens to delete from the list, consider adding some");
    } else {

        printf("\nEnter the EGN of the person you want to remove from the list: ");
        scanf("%ld", &EGN_to_delete);
        getchar();
    
        FILE * file = fopen(filename, "rb");
        if(file == NULL){
            printf("\nError in opening file");
            exit(1);
        }
    
        citizen * citizens = malloc(sizeof(citizen)*ammountOfCitizens);
    
        int kept = 0;

        for(int i = 0; i < ammountOfCitizens; i++) {
            if(fread(&currCitizen.EGN, sizeof(long), 1, file) != 1) break;
            if(fread(&currCitizen.nameLength, sizeof(short), 1, file) != 1) break;
            if(fread(currCitizen.name, sizeof(char), currCitizen.nameLength, file) != currCitizen.nameLength) break;
            if(fread(&currCitizen.age, sizeof(short), 1, file) != 1) break;
            if(fread(&currCitizen.education, sizeof(Education), 1, file) != 1) break;
            if(fread(&currCitizen.workingStatus, sizeof(WorkingStatus), 1, file) != 1) break;
            if(fread(&currCitizen.marriageStatus, sizeof(Marriage), 1, file) != 1) break;

            if(currCitizen.EGN != EGN_to_delete) {
                citizens[kept] = currCitizen;
                kept++;
            } else {
                deleted = true;
            }
        }
    
        fclose(file);
    
        if(deleted == true){
            FILE * newFile = fopen(filename, "wb");
            if(newFile == NULL){
                printf("\nError in opening file");
                exit(1);
            }
    
            for(int i = 0; i < kept; i++){
                fwrite(&(citizens[i].EGN), sizeof(long), 1, newFile);
                fwrite(&(citizens[i].nameLength), sizeof(short), 1, newFile);
                fwrite(&(citizens[i].name), sizeof(char), citizens[i].nameLength, newFile);
                fwrite(&(citizens[i].age), sizeof(short), 1, newFile);
                fwrite(&(citizens[i].education), sizeof(Education), 1, newFile);
                fwrite(&(citizens[i].workingStatus), sizeof(WorkingStatus), 1, newFile);
                fwrite(&(citizens[i].marriageStatus), sizeof(Marriage), 1, newFile);
            }
    
            fclose(newFile);
            printf("Successfuly delted the person with the EGN: %ld", EGN_to_delete);
        } else {
            printf("There is no such person with the EGN: %ld", EGN_to_delete);
        }
    
        free(citizens);
    }
}

int main(){
    bool ProgramIsRunning = true;
    bool isInFirstMenu = true;
    bool isWorkingWithFile = false;

    char filename[31];
    short first_input;
    short input;

    

    while(ProgramIsRunning){
        isInFirstMenu = true;

        while(isInFirstMenu){

            while(1){
                printf("\n1. Open Binary File");
                printf("\n2. Exit");
                printf("\nInput: ");
                scanf("%hd", &first_input);
                getchar();

                if(first_input < 1 || first_input > 2){
                    printf("\nInvalid Input, try 1-2");
                } else {
                    break;
                }
            }
    
            switch(first_input){
                case 1:
                    isInFirstMenu = false;
                    break;
                case 2:
                    exit(1);
                default:
                    printf("\nInvalid first_input");
                    break;
            }
        }
        
        while(1){
            printf("\nOpen Binary File('<filename>.bin'): ");
            scanf("%30s", filename);
            getchar();
    
            if(is_filename_valid(filename)){
                break;
            } else{
                printf("\nInvalid filename, try again");
            }
        }
    
    
        if(does_bin_file_exist(filename)){
            printf("\nFile exists, Opening now...");
        } else {
            printf("\nFile doesn't exist, creating a new one...");
            FILE * file = fopen(filename, "wb");
            if(file == NULL){
                printf("\nError in creating file");
            }
            fclose(file);
        }
        
        isWorkingWithFile = true;
    
        while(isWorkingWithFile){

            while(1){
                printf("\nCurrently opened: %s", filename);
                printf("\n1. List");
                printf("\n2. New Person");
                printf("\n3. Delete Person");
                printf("\n4. Exit Current File");
                printf("\nInput: ");
                scanf("%hd", &input);
                getchar();
    
                if(input < 1 || input > 4){
                    printf("\nInvalid input, try again. Valid inputs are 1-4");
                } else{
                    break;
                }
            }
    
            options answer = input;
    
    
            switch(answer){
    
                case LIST:
                    list(filename);
                    break;
    
                case NEW_PERSON:
                    new_person(filename);
                    break;
    
                case DELETE_PERSON:
                    delete_person(filename);
                    break;
    
                case EXIT_FILE:
                    isWorkingWithFile = false;
                    break;
    
                default:
                    printf("Invalid Answer");
                    break;
            }
        }
    }


    return 0;
}