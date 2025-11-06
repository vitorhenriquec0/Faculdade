#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

typedef enum {
    INSERT,
    DELETE,
    REPLACE,
    JOIN,  
    SPLIT,
    APPEND
} Type;

typedef struct UndoAction {
    Type type;
    int position; // onde a ação ocorreu
    char* textSaved;
    int indexSaved;
} UndoAction;

typedef struct StackNode {
    UndoAction* action;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
    int size;
} Stack;

Stack* createStack();

void freeStack(Stack* stack);

void clearStack(Stack* stack);

int isStackEmpty(Stack* stack);

UndoAction* createAction(Type type, int position, const char* text, int index);
void freeAction(UndoAction* action);

void push(Stack* stack, UndoAction* action);
UndoAction* pop(Stack* stack);

#endif