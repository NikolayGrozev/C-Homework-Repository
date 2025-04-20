#include <stdio.h>

typedef struct Node{
    char firstName[15];
    struct Node * father;
    struct Node * mother;
    struct Node * marriedto;
}node;

int main(){

    node Brother1 = {
        .firstName = "Petar"
    };
    node Brother2 = {
        .firstName = "Petko"
    };
    node Father = {
        .firstName = "Dimitar"
    };
    node Mother = {
        .firstName = "Iva"
    };
    node GrandMother = {
        .firstName = "Gergana"
    };
    node GrandMother2 = {
        .firstName = "Aleksandra"
    };
    node Grandfather = {
        .firstName = "Stoyan"
    };
    node Grandfather2 = {
        .firstName = "Cvetomir"
    };

    Brother1.marriedto = NULL;
    Brother2.marriedto = NULL;

    Father.marriedto = &Mother;
    Mother.marriedto = &Father;

    Grandfather.marriedto = &GrandMother;
    GrandMother.marriedto = &Grandfather;

    Grandfather2.marriedto = &GrandMother2;
    GrandMother2.marriedto = &Grandfather2;

    Brother1.father = &Father;
    Brother2.father = &Father;

    Brother1.mother = &Mother;
    Brother2.mother = &Mother;

    Father.mother = &GrandMother;
    Mother.mother = &GrandMother2;
    
    Father.father = &Grandfather;
    Mother.father = &Grandfather2;

    return 0;
}