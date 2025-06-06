#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

static uint first_index = 0;

LinkedList init() {
  LinkedList newList = {
    .head = NULL,
    .size = 0
  };

  return newList;
}

void assertIndexInBounds(LinkedList * list, uint index) {
  if (list->size <= (index-first_index) || index < first_index) {
    printf("Index out of bounds\n");
    exit(1);
  }
}

static Node * createNode(ListType value) {
  Node * newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Error allocating memory \n");
    exit(1);
  }
  newNode->value = value;

  return newNode;
}

void pushFront(LinkedList * list, ListType value) {
  Node * newNode = createNode(value);

  newNode->next = list->head;
  list->head = newNode;
  list->size++;
}

Node * getNode(LinkedList * list, uint index) {
  assertIndexInBounds(list, index);
  Node * currentNode = list->head;
  for (int i = first_index; i < index; i++) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

ListType get(LinkedList * list, uint index) {
  Node * currentNode = getNode(list, index);
  return currentNode->value;
}

void push(LinkedList * list, uint index, ListType value) {
  if (index == first_index) {
    pushFront(list, value);
  } else {
    Node * prevNode = getNode(list, index - 1);
    Node * newNode = createNode(value);

    newNode->next = prevNode->next;
    prevNode->next = newNode;
    list->size++;
  }
  
}

void pushBack(LinkedList * list, ListType value) {
  uint last_index = list->size;
  if(first_index == 1){
    last_index++;
  }

  push(list, last_index, value);
}

ListType popFront(LinkedList * list) {
  Node * nodeToDelete = list->head;
  list->head = nodeToDelete->next;

  ListType result = nodeToDelete->value;
  free(nodeToDelete);
  list->size--;
  return result;
}

void set(LinkedList * list, uint index, ListType value) {
    Node * node = getNode(list, index);
    node->value = value;
}

ListType popBack(LinkedList * list) {
  return pop(list, list->size-1);
}

ListType pop(LinkedList * list, uint index) {
    uint result;
    if(index > first_index){
        Node * prevNode = getNode(list, index-1);
        Node * nodeToDelete = getNode(list, index);

        prevNode->next = nodeToDelete->next;
        result = nodeToDelete->value;
        
        free(nodeToDelete);
        list->size--;

    } else{
        result = popFront(list);
    }
    return result;
}

void release(LinkedList * list) {
    Node * node = NULL;
    for(uint i = first_index; i < list->size; i++){
        node = getNode(list, i);
        free(node);
    }
}