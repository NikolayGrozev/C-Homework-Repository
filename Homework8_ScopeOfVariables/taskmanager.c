#include <stdio.h>
#include "processes.h"

int main(){

    while(1){
        char input[50];

        printf("\nTask manager");
        printf("\n1. Create a new Process");
        printf("\n2. List of processes...");
        printf("\n3. Stop a process...   ");
        printf("\n4. Close Task Manager  \n");
        printf("Select: ");
        scanf("%s", &input);

        if(input[1] == '\0'){
            
            switch (input[0]){
                case '1': 
                    {
                        char name[30];
                        printf("\n\n How would you like to name the new process? \n Name: ");
                        scanf("%s", name);
                        
                        if(processCount != 5){
                            int newProcessId = createnewprocess(name);
                            printf("\nThe id of your new process is %d\n", newProcessId);
                        }else{
                            printf("\nError: There is no space for a new process, to make space, you have to stop a process\n");
                        }
                        break;
                    }
                case '2':
                    {
                        printf("\n\n");
                        for(int i = 0; i < 5; i++){
                            printf("\nProcess id: %d | Process Name: %s \n", processes[i].id, processes[i].ProcessName);

                        }


                        break;
                    }
                case '3': 
                    {
                        int enteredId;
                        printf("\n\n");
                        printf("What process do you want to delete? \n Enter a Process's id here: ");
                        scanf("%d", &enteredId);

                        stopprocess(enteredId);

                        
                        break;
                    }
                case '4': return 0;
                default:
                    {
                        printf("\nInvalid Option, try again\n");
                        break;
                    }
            }
        }
        else{
            printf("\nInvalid Option, try again\n");
            continue;
        }
    } 


}