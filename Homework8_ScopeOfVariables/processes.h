#ifndef PROCESSES_H_
#define PROCESSES_H_

struct Process{
    unsigned int id;
    char ProcessName[30];
};

int Counter;

unsigned int processCount;

struct Process processes[5];

static unsigned int nextprocessid();
int createnewprocess(char *processName);
void stopprocess(unsigned int id);

#endif