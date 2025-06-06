#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Tasks init(){
    Tasks tasks = {
        .head = NULL,
        .size = 0
    };

    return tasks;
};

Task * create_task(){
    Task * newTask = (Task *)malloc(sizeof(Task));
    if(newTask == NULL){
        printf("Error in allocating memory");
        exit(1);
    }
    newTask->nextTask = NULL;
    newTask->taskState = NEW;

    newTask->description = (char *)malloc(sizeof(char));
    if(newTask->description == NULL){
        printf("Error in allocating memory");
        exit(1);
    }
    /* във assign_description memory reallocation проверката ще мине ако дефинирам началния description, като NULL,
    затова му давам някаква произволна стойност */
    newTask->description[0] = '\0';

    return newTask;
};

char * assign_description(Task * task, char * newDescription){
    uint desc_size = 1;

    for(uint i = 0; newDescription[i] != '\0'; i++){
        desc_size++;
    }

    task->description = (char *)realloc(task->description, sizeof(char) * desc_size);
    if(task->description == NULL){
        printf("Error in reallocating memory");
        exit(1);
    }

    for(int i = 0; i < desc_size; i++){
        task->description[i] = newDescription[i];
    }

    return task->description;
};

static void is_priority_valid_CHECK(Tasks * tasks, uint priority){
    if(priority > tasks->size || priority < 1){
        printf("Invalid priority value");
        exit(1);
    }
};

char * get_task_description(Tasks * tasks, uint priority){
    Task * task = get_task(tasks, priority);
    return task->description;
};

void set_task_description(Tasks * tasks, uint priority, char * newDescription){
    Task * task = get_task(tasks, priority);
    task->description = assign_description(task, newDescription);
};

void pushFront(Tasks * tasks, char * newDescription){
    Task * newTask = create_task();
    newTask->description = assign_description(newTask, newDescription);
    if(tasks->size == 0){
        tasks->head = newTask;
    }else {
        newTask->nextTask = tasks->head;
        tasks->head = newTask;
    }
        tasks->size++;

};

void push(Tasks * tasks, uint priority, char * newDescription){
    if(priority == 1){
        pushFront(tasks, newDescription);
    } else {
        Task * newTask = create_task();
        Task * previousTask = get_task(tasks, priority-1);
        newTask->description = assign_description(newTask, newDescription);
        newTask->nextTask = previousTask->nextTask;
        previousTask->nextTask = newTask;
        tasks->size++;
    }
};
void pushBack(Tasks * tasks, char * newDescription){
    push(tasks, tasks->size +1, newDescription);
};

void popFront(Tasks * tasks){
    Task * frontTask = get_task(tasks, 1);
    free(frontTask->description);
    tasks->head = frontTask->nextTask;
    free(frontTask);
    tasks->size--;
};
void pop(Tasks * tasks, uint priority){
    if(priority == 1){
        popFront(tasks);
    } else {
        Task * taskToDelete = get_task(tasks, priority);
        Task * previousTask = get_task(tasks, priority-1);
        previousTask->nextTask = taskToDelete->nextTask;
        free(taskToDelete->description);
        free(taskToDelete);
        tasks->size--;
    }
};

void popBack(Tasks * tasks){
    pop(tasks, tasks->size);
};

Task * get_task(Tasks * tasks, uint priority){
    is_priority_valid_CHECK(tasks, priority);
    Task * task = tasks->head;
    for(uint i = 1; i < priority; i++){
        task = task->nextTask;
    };

    return task;
};


void set_task_priority(Tasks * tasks, uint currentPriority, uint newPriority){
    is_priority_valid_CHECK(tasks, currentPriority);
    is_priority_valid_CHECK(tasks, newPriority);

    if(currentPriority == newPriority){
        return;
    }

    Task * taskToChange = get_task(tasks, currentPriority);
    
    if(currentPriority > 1){
        Task * previousTask = get_task(tasks, currentPriority-1);

        if(newPriority == 1){
            previousTask->nextTask = taskToChange->nextTask;
            taskToChange->nextTask = tasks->head;
            tasks->head = taskToChange;

        } else {
            Task * tasktoBeMoved = get_task(tasks, newPriority);

            previousTask->nextTask = taskToChange->nextTask;
            taskToChange->nextTask = tasktoBeMoved->nextTask;
            tasktoBeMoved->nextTask = taskToChange;

        }
    } else if (currentPriority == 1){
        Task * taskToBeMoved = get_task(tasks, newPriority);

        tasks->head = taskToChange->nextTask;
        taskToChange->nextTask = taskToBeMoved->nextTask;
        taskToBeMoved->nextTask = taskToChange;

    }

};

void release(Tasks * tasks){
    while(tasks->head != NULL){
        popFront(tasks);
    }

    tasks->head = NULL;
    tasks->size = 0;
};