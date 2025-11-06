#include "stack.h"
#include <stdio.h>

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        perror("-> Erro ao alocar memoria para a pilha.\n");
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

UndoAction* createAction(Type type, int position, const char* text, int index) {
    UndoAction* action = (UndoAction*) malloc(sizeof(UndoAction));
    if (action == NULL) {
        perror("-> Erro ao alocar memoria para a acao.\n");
        return NULL;
    }

    action->type = type;
    action->position = position;
    action->indexSaved = index;

    if (text != NULL) {
        action->textSaved = (char*) malloc(strlen(text) + 1);
        if (action->textSaved != NULL) {
            strcpy(action->textSaved, text);
        } else {
            perror("-> Erro ao alocar memoria para o texto da açao.\n");
            action->textSaved = NULL;
        }
    } else {
        action->textSaved = NULL;
    }

    return action;
}

int isStackEmpty(Stack* stack) {
    if (stack == NULL) return 1;
    return stack->size == 0;
}

void push(Stack* stack, UndoAction* action) {
    if (stack == NULL || action == NULL) return;

    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode == NULL) {
        perror("-> Erro ao alocar memoria para o no da pilha.\n");
        return;
    }

    newNode->action = action;
    newNode->next = stack->top;

    stack->top = newNode;
    stack->size++;
}

UndoAction* pop(Stack* stack) {
    if (isStackEmpty(stack)) return NULL;

    StackNode* nodeToPop = stack->top;
    UndoAction* actionToReturn = nodeToPop->action;

    stack->top = nodeToPop->next;
    
    free(nodeToPop);

    stack->size--;
    return actionToReturn;
}

void freeAction(UndoAction* action) {
    if (action == NULL) return;

    if (action->textSaved != NULL) {
        free(action->textSaved);
    }

    free(action);
}

void clearStack(Stack* stack) {
    if (stack == NULL) return;

    while (!isStackEmpty(stack)) {
        UndoAction* action = pop(stack);
        freeAction(action);
    }
}

void freeStack(Stack* stack) {
    if (stack == NULL) return;

    clearStack(stack);

    free(stack);
}