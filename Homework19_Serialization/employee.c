#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"

employee init(char * name, uint init_capacity){
    employee newEmployee = {
        .numberOfSubordinates = 0,
        .subordinates = NULL,
        .arrCapacity = init_capacity
    };

    if(init_capacity > 0){
        newEmployee.subordinates = (employee **)malloc(sizeof(employee*) * newEmployee.arrCapacity);
    }

    strcpy(newEmployee.name, name);

    return newEmployee;
};

employee add_subordinate(employee * higherEmployee, employee * subordinate){
    if(higherEmployee->subordinates == NULL){

        higherEmployee->subordinates = (employee **)malloc(sizeof(employee*));
        if(higherEmployee->subordinates == NULL){
            printf("Error in allocating memory");
            exit(1);
        }
        higherEmployee->numberOfSubordinates = 1;
        higherEmployee->arrCapacity = 1;

        higherEmployee->subordinates[0] = subordinate;
    } else {

        higherEmployee->numberOfSubordinates++;

        if(higherEmployee->numberOfSubordinates > higherEmployee->arrCapacity){
            higherEmployee->arrCapacity *= 2;
            employee ** temp = realloc(higherEmployee->subordinates, sizeof(employee) * higherEmployee->arrCapacity);
            if(temp == NULL){
                printf("Error in reallocating memory");
                exit(1);
            }

            higherEmployee->subordinates = temp;

        }

        higherEmployee->subordinates[higherEmployee->numberOfSubordinates-1] = subordinate;
    }

    return *(higherEmployee);
};

void release_hierarchy(employee *emp) {
    if (!emp) return;
    
    for (uint i = 0; i < emp->numberOfSubordinates; i++) {
        release_hierarchy(emp->subordinates[i]);
        free(emp->subordinates[i]);
    }
    
    free(emp->subordinates);
}

static void indentate(short indentLevel){
    for(short i = 0; i < indentLevel; i++){
        printf("    ");
    }
}

void printEmployee(employee * employeeToPrint, short indentLevel){
        
        indentate(indentLevel);
        printf("Hierchy of employee starting from %s\n", employeeToPrint->name);
        indentate(indentLevel);
        printf("name: %s\n", employeeToPrint->name);
        indentate(indentLevel);
        printf("ammount of subordinates: %u\n", employeeToPrint->numberOfSubordinates);

        if(employeeToPrint->numberOfSubordinates != 0){
            indentate(indentLevel);
            printf("subordinates of %s:\n", employeeToPrint->name);
            for(uint i = 0; i < employeeToPrint->numberOfSubordinates; i++){
                printEmployee(employeeToPrint->subordinates[i], indentLevel+1);
            }
        }
};
