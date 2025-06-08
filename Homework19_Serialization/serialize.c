#include <stdio.h>
#include <stdlib.h>

#include "employee.h"

void write_up_hiearchy(employee * CEO ,FILE * file){
    /*
        1. name
        2. numberOfSubordinates
        3. arrCapacity
        4. subordinates{
            employee1 { 
            1. name
            2. numberOfSubordinates
            3. arrCapacity
            4. subordinates ...
            }
            employee2 { 
            1. name
            2. numberOfSubordinates
            3. arrCapacity
            4. subordinates ...
            }
            employee3 { 
            1. name
            2. numberOfSubordinates
            3. arrCapacity
            4. subordinates ...
            }
        }
    
    */

    fwrite(CEO->name, sizeof(char), EMPLOYEE_NAME_LENGTH, file);
    fwrite(&(CEO->numberOfSubordinates), sizeof(uint), 1, file);
    fwrite(&(CEO->arrCapacity), sizeof(uint), 1, file);
    for(uint i = 0; i < CEO->numberOfSubordinates; i++){
        write_up_hiearchy(CEO->subordinates[i], file);
    }
};

int main(){

    employee director = init("Charlie", 0);

    employee manager1 = init("Victor", 0);
    employee manager2 = init("Hector", 0);

    employee worker11 = init("Niki", 0);
    employee worker12 = init("Alex", 0);
    employee worker13 = init("Alexa", 0);

    employee worker21 = init("Hristo", 0);
    employee worker22 = init("Yonko", 0);
    employee worker23 = init("Zlati", 0);

    director = add_subordinate(&(director), &(manager1));
    director = add_subordinate(&(director), &(manager2));

    manager1 = add_subordinate(&(manager1), &(worker11));
    manager1 = add_subordinate(&(manager1), &(worker12));
    manager1 = add_subordinate(&(manager1), &(worker13));

    manager2 = add_subordinate(&(manager2), &(worker21));
    manager2 = add_subordinate(&(manager2), &(worker22));
    manager2 = add_subordinate(&(manager2), &(worker23));

    FILE * file = fopen("employees.bin", "wb");
    if(file == NULL){
        printf("Error in opening file");
        exit(1);
    }

    write_up_hiearchy(&(director), file);

    fclose(file);
    
    release_hierarchy(&director);

    return 0;
}