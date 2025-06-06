#include <stdio.h>
#include "LinkedList.h"

void print_task_completion(Task * task){
    if(task->taskState == NEW){
        printf(" New ");
    } else if (task->taskState == IN_PROGRESS) {
        printf(" In_Progress ");
    } else{
        printf(" Finished ");
    }
};

void print_tasks(Tasks * tasks){
    if(tasks->size > 0){
        printf("\nTasks: {");
        printf("\nPriority: Task /Completion");
        Task * currentTask = NULL;
        for(uint i = 1; i <= tasks->size; i++){
            currentTask = get_task(tasks, i);
            printf("\n %d: %s /", i, currentTask->description);
            print_task_completion(currentTask);
        }
        printf("\n}");
    } else{
        printf("\nThere are currently no tasks :)");
    }
};


void add_task(Tasks * tasks){
    char description[50];
    uint priority;

    printf("\nNew task");
    printf("\nWrite the descsription of your new task: ");

    getchar();
    fgets(description, 50, stdin);


    int index;
    for(int i = 0; description[i] != '\n'; i++){
        index = i;
    }
    description[index+1] = '\0';

    if(tasks->size == 0){
        pushFront(tasks, description);
    } else {
        printf("\nEnter the priority you want your task to hold: ");
        scanf("%u", &priority);

        if(priority > tasks->size){
            pushBack(tasks, description);
        } else{
            push(tasks, priority, description);
        }
    }
}

void change_task_priority(Tasks * tasks){
    print_tasks(tasks);
    if(tasks->size == 0){
        return;
    }

    uint currentTaskPriority, newTaskPriority;

    printf("\nTo change the priority of a task, you need to first select it via it's priority and assign it a new priority.");
    printf("\n Enter the priority of the task you want to select: ");
    scanf("%u", &currentTaskPriority);
    printf("\n Enter the it's new priority: ");
    scanf("%u", &newTaskPriority);

    set_task_priority(tasks, currentTaskPriority, newTaskPriority);

    printf("\nHere's the updated list: ");
    print_tasks(tasks);
};

void change_task_description(Tasks * tasks){
    print_tasks(tasks);
    if(tasks->size == 0){
        return;
    }

    uint priority;
    char description[50];


    printf("\nTo change a task's description you need to select it via it's priority and assign it a new description.");
    printf("\n Enter the priority of the task you want to select: ");
    scanf("%u", &priority);
    printf("\n Enter the it's new description: ");

    getchar();
    fgets(description, 50, stdin);
    getchar();

    int index;
    for(int i = 0; description[i] != '\n'; i++){
        index = i;
    }
    description[index+1] = '\0';

    set_task_description(tasks, priority, description);

    printf("\nHere's the updated list: ");
    print_tasks(tasks);
};

void delete_task(Tasks * tasks){
    print_tasks(tasks);
    if(tasks->size == 0){
        return;
    }

    uint priority;
    
    getchar();

    printf("\nTo delete a task, you need to select it via it's priority");
    printf("\n Enter the priority of the task you want to select: ");
    scanf("%u", &priority);

    pop(tasks, priority);
};

void change_task_completion(Tasks * tasks){
    print_tasks(tasks);
    if(tasks->size == 0){
        return;
    }

    uint priority;
    
    printf("\nTo change a task's completion level you need to select it via it's priority");
    printf("\n Enter the priority of the task you want to select: ");
    scanf("%u", &priority);

    Task * task = get_task(tasks, priority);
    
    short input;
    do{
        printf("\nTo which completion level do you want to change the task: %s", task->description);
        printf("\n1. New");
        printf("\n2. In Progress");
        printf("\n3. Finished");
        printf("\n4. No change");
        printf("\nInput: ");
        scanf("%hd", &input);
        if(input >= 1 && input <= 4){
            break;
        }else{
            printf("\nInvalid Input, use 1-4");
        }
    }while(1);
    
    if(input == 4){
        return;
    }else{
        task->taskState = input;
    }

}

typedef enum {
    ADD_TASK = 1,
    CHECK_TASKS,
    CHANGE_TASK_PRIORITY,
    CHANGE_TASK_DESCRIPTION,
    CHANGE_TASK_COMPLETION,
    DELETE_A_TASK,
    EXIT
} inputAnswer;

int main(){
    Tasks tasks = init();
    short programIsRunning = 1;
    short input;

    while(programIsRunning){
        do{
            printf("\n Menu");
            printf("\n1. Add a task");
            printf("\n2. Check tasks");
            printf("\n3. Change a task's priority in the list");
            printf("\n4. Modify a task's description");
            printf("\n5. Modify a task's level of completion");
            printf("\n6. Delete a task");
            printf("\n7. Exit");
            printf("\nInput: ");
            scanf("%hd", &input);
            if(input >= 1 && input <= 7){
                break;
            }else{
                printf("\nInvalid Input, use 1-7");
            }
        }while(1);
    
        inputAnswer answer = input;
    
        switch(answer){
            case ADD_TASK:
                add_task(&tasks);
                break;
    
            case CHECK_TASKS:
                print_tasks(&tasks);
                break;
    
            case CHANGE_TASK_PRIORITY:
                change_task_priority(&tasks);
                break;
    
            case CHANGE_TASK_DESCRIPTION:
                change_task_description(&tasks);
                break;
    
            case CHANGE_TASK_COMPLETION:
                change_task_completion(&tasks);
                break;

            case DELETE_A_TASK:
                delete_task(&tasks);
                break;

            case EXIT:
                programIsRunning = 0;
                break;
    
            default: printf("\nInvalid answer");
        }
    }

    return 0;
}