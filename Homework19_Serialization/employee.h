
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define EMPLOYEE_NAME_LENGTH 100
typedef unsigned int uint;

typedef struct Employee{
    char name[EMPLOYEE_NAME_LENGTH];
    uint numberOfSubordinates;
    uint arrCapacity;
    struct Employee ** subordinates;
} employee;


employee init(char * name, uint init_capacity);
employee add_subordinate(employee * higherEmployee, employee * subordinate);
void printEmployee(employee * employeeToPrint, short indentLevel);
void release_hierarchy(employee *emp);


#endif