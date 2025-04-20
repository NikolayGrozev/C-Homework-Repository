#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

typedef enum{
    CREATE_NEW_CAUSE = 1,
    PRINT_CAUSES = 2,
    EXIT = 3
} inputAnswers;

typedef struct{
    short hour;
    short minute;
    short seccond;
}Time;

typedef struct {
    char firstName[15];
    char secondName[15];
    char lastName[15];
    char email[30];
    long phoneNumber;
} Participant;

typedef struct{
    bool isParticipating;
    Participant participant;
}ParticipantAnswer;

typedef struct{
    char title[50];
    char description[200];
    struct{
        short year;
        short month;
        short day;
        Time time;
    }date;
    short ammountOfParticipants;
    ParticipantAnswer answersOfParticipants[100];
}Cause;

void printParticipantsAnswers(ParticipantAnswer * answers, short * ammountOfParticipants){

    printf("\nTable of participants");
    printf("\n|%-47s|%-16s|%-30s|%-15s|", "Participant", "IsParticipating", "Email", "Phone Number");
    for(int i = 0; i < (*ammountOfParticipants); i++){
        printf("\n|%-15s %-15s %-15s|%-16d|%-30s|%-15ld|",
            (*(answers + i)).participant.firstName,
            (*(answers + i)).participant.secondName,
            (*(answers + i)).participant.lastName,
            (*(answers + i)).isParticipating,
            (*(answers + i)).participant.email,
            (*(answers + i)).participant.phoneNumber
        );
    }
    printf("\n");

}

void PrintCauseInfo(Cause * cause){

    printf("\nTitle: %-50s", (*cause).title);
    printf("\nDescription: %-200s", (*cause).description);
    printf("\nDate: %-2hd/%-2hd/%-4hd ", (*cause).date.day, (*cause).date.month, (*cause).date.year );
    printf("\nTime: %-2hd:%-2hd:%-2hd", (*cause).date.time.hour, (*cause).date.time.minute, (*cause).date.time.seccond);
    printParticipantsAnswers((*cause).answersOfParticipants, &((*cause).ammountOfParticipants));

}

Cause * CreateNewCause(Cause * causes, short * amountOfCouses){
    (*amountOfCouses)++;
    causes = realloc(causes, sizeof(Cause) * (*amountOfCouses));
    if(causes == NULL){
        printf("\nError in Reallocating Memory");
        exit(1);
    }

    Cause newCause;

    printf("\n Create a new Cause");
    printf("\n Enter the title of the new Cause: ");
    scanf("%s", &(newCause.title));
    printf("\n Enter the description of the new Cause: ");
    scanf("%s", &(newCause.description));
    getchar();

    printf("\n Now enter the date and time of the new cause");
    printf("\n Year: ");
    scanf("%hd", &(newCause.date.year));
    printf("\n Month: ");
    scanf("%hd", &(newCause.date.month));
    printf("\n Day: ");
    scanf("%hd", &(newCause.date.day));
    printf("\n Hour: ");
    scanf("%hd", &(newCause.date.time.hour));
    printf("\n Minute: ");
    scanf("%hd", &(newCause.date.time.minute));
    printf("\n Seccond: ");
    scanf("%hd", &(newCause.date.time.seccond));

    printf("\nHow many Volunteers will participate?");
    printf("\n amount: ");
    scanf("%hd", &(newCause.ammountOfParticipants));

    for(short i = 0; i < newCause.ammountOfParticipants; i++){
        printf("\nEnter the details of participant %hd out of the %hd", (i+1), newCause.ammountOfParticipants);
        printf("\nFirst Name: ");
        scanf("%s", &(newCause.answersOfParticipants[i].participant.firstName));
        getchar();  
        printf("\nSecond Name: ");
        scanf("%s", &(newCause.answersOfParticipants[i].participant.secondName));
        getchar();
        printf("\nLast Name: ");
        scanf("%s", &(newCause.answersOfParticipants[i].participant.lastName));
        getchar();
        printf("\nEmail: ");
        scanf("%s", &(newCause.answersOfParticipants[i].participant.email));
        getchar();
        printf("\nPhone Number: ");
        scanf("%ld", &(newCause.answersOfParticipants[i].participant.phoneNumber));
    }

    short input = -1;
    for(short i = 0; i < newCause.ammountOfParticipants; i++){
        do{
            printf("\nWill '%s %s %s' participate in the Cause: '%s'?",
                newCause.answersOfParticipants[i].participant.firstName,
                newCause.answersOfParticipants[i].participant.secondName,
                newCause.answersOfParticipants[i].participant.lastName,
                newCause.title
            );
            printf("\nAnswer with 0 for False and 1 for True");
            printf("\nAnswer: ");
            scanf("%hd", &input);
        }while(input < 0 || input > 1);

        newCause.answersOfParticipants[i].isParticipating = false;
        if(input){
            newCause.answersOfParticipants[i].isParticipating = true;
        }
    }

    causes[(*amountOfCouses)-1] = newCause;

    return causes;
}

int main(){
    
    Cause cause1 = {
        "SAVE MICE",
        .description = "This cause is about saving the endangered mice species",
        .answersOfParticipants = {
            {
                .isParticipating = true,
                .participant = {
                    .firstName = "Petko",
                    .secondName = "Ivanov",
                    .lastName = "Geshev",
                    .email = "pIvanov@abv.bg",
                    .phoneNumber = 815623342,
                }
            },
            {
                .isParticipating = false,
                .participant = {
                    .firstName = "Rayko",
                    .secondName = "Aleksandrov",
                    .lastName = "Petrov",
                    .email = "rPetrov@gmail.com",
                    .phoneNumber = 875323449,
                }
            }
        },
        .date = {
            .day = 4,
            .month = 7,
            .year = 2014,
            .time = {
                .hour = 8,
                .minute = 43,
                .seccond = 9
            }
        },
        .ammountOfParticipants = 2
    };

    Cause cause2 = {
        "SAVE MEN FROM WAR",
        .description = "This cause is about saving the troops from the war that's about to end",
        .answersOfParticipants = {
            {
                .isParticipating = true,
                .participant = {
                    .firstName = "Ivana",
                    .secondName = "Rumenova",
                    .lastName = "Peycheva",
                    .email = "iPeycheva@abv.bg",
                    .phoneNumber = 815553342,
                }
            },
            {
                .isParticipating = false,
                .participant = {
                    .firstName = "Martin",
                    .secondName = "Zhelqzkov",
                    .lastName = "Hadzhipetkov",
                    .email = "mHPetkov@gmail.com",
                    .phoneNumber = 813773449,
                }
            }
        },
        .date = {
            .day = 29,
            .month = 4,
            .year = 2019,
            .time = {
                .hour = 15,
                .minute = 20,
                .seccond = 0
            }
        },
        .ammountOfParticipants = 2
    };

    short amountOfCauses = 2;

    Cause * causes = (Cause *)malloc(sizeof(Cause) * amountOfCauses);
    if(causes == NULL){
        printf("\nError in allocating memory");
        exit(1);
    }

    causes[0] = cause1;
    causes[1] = cause2;

    short input = 0;
    char isProgramRunning = 1;
    
    while(isProgramRunning){
        do{
            printf("\n1. Create a new cause");
            printf("\n2. List of Causes (currently %hd causes)", amountOfCauses);
            printf("\n3. Exit");
            printf("\nInput 1-3: ");
            scanf("%hd", &input);
    
            if(input < 1 || input > 3){
                printf("Input can't be anything other than 1, 2 or 3");
            }
        }while(input < 1 || input > 3);
        inputAnswers answer = input;

        switch(answer){
            case CREATE_NEW_CAUSE:
                causes = CreateNewCause(causes, &amountOfCauses);
                break;
            case PRINT_CAUSES:
                for(int i = 0; i < amountOfCauses; i++){
                    printf("--------------------------------------------------------------------------------------------------------");
                    printf("\nCAUSE NO %hd", i + 1);
                    PrintCauseInfo(&causes[i]);
                }
                break;
            case EXIT:
                isProgramRunning = 0;
                break;
            default: printf("\nInvalid Input in switch(answer)");
        }
    }

    free(causes);

    return 0;
}