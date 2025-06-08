#include <stdio.h>
#include <stdlib.h>

#include "employee.h"

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

employee read_hiearchy(employee * CEO, FILE * file){
    
    fread(CEO->name, sizeof(char), EMPLOYEE_NAME_LENGTH, file);
    fread(&(CEO->numberOfSubordinates), sizeof(uint), 1, file);
    fread(&(CEO->arrCapacity), sizeof(uint), 1, file);

    if(CEO->numberOfSubordinates > 0){
        CEO->subordinates = (employee **)malloc(sizeof(employee*) * CEO->arrCapacity);
        if(CEO->subordinates == NULL){
            printf("\nError in allocating memory");
            exit(1);
        }

        for (uint i = 0; i < CEO->numberOfSubordinates; i++) {
                CEO->subordinates[i] = (employee *)malloc(sizeof(employee));
                if (!CEO->subordinates[i]) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                *(CEO->subordinates[i]) = read_hiearchy(CEO->subordinates[i], file);
        }
    } else {
            CEO->subordinates = NULL;
    }



    return *(CEO);

}

int main(){
    FILE * file = fopen("employees.bin", "rb");
    if(file == NULL){
        printf("\nError in opening file");
        exit(1);
    }
    
    employee director;

    director = read_hiearchy(&director, file);

    fclose(file);

    printEmployee(&director, 0);

    release_hierarchy(&director);

    return 0;
}