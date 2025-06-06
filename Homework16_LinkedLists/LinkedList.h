#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef unsigned int uint;

typedef enum {
    NEW,
    IN_PROGRESS,
    FINISHED
} state;

typedef struct task{
    state taskState;
    char * description;
    struct task * nextTask;
}Task;

typedef struct {
    uint size;
    Task * head;
} Tasks;

Tasks init();

void push(Tasks * tasks, uint priority, char * newDescription);
void pushBack(Tasks * tasks, char * newDescription);
void pushFront(Tasks * tasks, char * newDescription);

void pop(Tasks * tasks, uint priority);
void popBack(Tasks * tasks);
void popFront(Tasks * tasks);

Task * get_task(Tasks * tasks, uint priority);
char * get_task_description(Tasks * tasks, uint priority);

void set_task_description(Tasks * tasks, uint priority, char * newDescription);
void set_task_priority(Tasks * tasks, uint currentPriority, uint newPriority);

void release(Tasks * tasks);

#endif