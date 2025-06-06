#include <stdio.h>
#include "LinkedList.h"

void print_tasks(Tasks * tasks){
    printf("\nTasks: {");
    Task * currentTask = NULL;
    for(uint i = 1; i <= tasks->size; i++){
        currentTask = get_task(tasks, i);
        printf("\n %d: %s ", i, currentTask->description);
    }
    printf("\n}");
};

int main(){

    Tasks tasks = init();

    printf("\nPushing Front mishka, mishka2 and mishka 3");
    pushFront(&tasks, "mishka");
    pushFront(&tasks, "mishka2");
    pushFront(&tasks, "mishka3");
    print_tasks(&tasks);

    printf("\n\ntasks.size: %u", tasks.size);

    printf("\n\nPushing Back mishka 4");
    pushBack(&tasks, "mishka4");
    print_tasks(&tasks);

    printf("\nPushing mishka5 on 1st Priority");
    push(&tasks, 1, "mishka5" );
    print_tasks(&tasks);

    printf("\nPushing mishka6 on 4th Priority");
    push(&tasks, 4, "mishka6" );
    print_tasks(&tasks);

    printf("\nPopback 1 time");
    popBack(&tasks);
    print_tasks(&tasks);

    printf("\nPopFront 1 time");
    popFront(&tasks);
    print_tasks(&tasks);

    printf("\nPop priority 2");
    pop(&tasks, 2);
    print_tasks(&tasks);


    printf("\nPushing Front guska, mishka2");
    pushFront(&tasks, "guska");
    pushFront(&tasks, "mishka2");
    print_tasks(&tasks);


    printf("\nChanged priority 1's description to 'Mechka'");
    set_task_description(&tasks, 1, "Mechka");
    print_tasks(&tasks);

    printf("\nMoved the priority of task 3 to priority 1");
    set_task_priority(&tasks, 3, 1);
    print_tasks(&tasks);

    printf("\nMoved the priority of task 2 to priority 4");
    set_task_priority(&tasks, 2, 4);
    print_tasks(&tasks);

    printf("\nMoved the priority of task 4 to priority 5");
    set_task_priority(&tasks, 4, 5);
    print_tasks(&tasks);

    printf("\nMoved the priority of task 1 to priority 5");
    set_task_priority(&tasks, 1, 5);
    print_tasks(&tasks);

    release(&tasks);

    return 0;
}