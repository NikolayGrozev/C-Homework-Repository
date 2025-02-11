#include "processes.h"
#include <limits.h>

struct Process processes[5];
int Counter = 0;
unsigned int processCount = 0;


static unsigned int nextprocessid(){

    if(Counter == UINT_MAX){
        return 0;
    }
    else{
        return (Counter+1);
    }    
};

int createnewprocess(char *processName){
    struct Process newProcess = {nextprocessid(), ""};

    for(int i = 0; processName[i] != '\0' ; i++){
        newProcess.ProcessName[i] = processName[i];
    }

    if(processCount <= 4 && newProcess.id != 0){
        processes[processCount] = newProcess;
        Counter++;
        processCount++;
    }

    return newProcess.id;
};

void stopprocess(unsigned int id){
    int idIsValid = (id > 0 && id <=5) ? 1 : 0;
    struct Process deletedProcess = {'\0', '\0'};

    if(idIsValid){
        for(int i = id-1; i < 5; i++){
            if(i+1 != 5){
                processes[i] = processes[i+1];
                processes[i+1] = deletedProcess;
            }
        }
        processCount--;
    }

};
