#include <stdio.h>
#include <stdlib.h>
#include "undo.h"
#include "editor.h"
#include "stack.h"

void executeUndo(Document* document, Stack* undoStack, Stack* redoStack) {
    UndoAction* actionToExecute = pop(undoStack);

    if (actionToExecute == NULL) {
        printf("-> Nada a desfazer.\n");
    } else {
        UndoAction* actionToRedo = NULL;

        switch (actionToExecute->type) {
            case DELETE:
            {
                LineNode* node = getLineNode(document, actionToExecute->position);
                if (node == NULL) {
                    printf("-> Erro ao desfazer: linha nao encontrada.\n");
                    break;
                }

                char* textToRedo = (char*) malloc(strlen(node->text) + 1);
                strcpy(textToRedo, node->text);

                deleteLine(document, actionToExecute->position, NULL, NULL, 1);

                actionToRedo = createAction(INSERT, actionToExecute->position, textToRedo, 0);
                push(redoStack, actionToRedo);

                free(textToRedo);
                printf("-> Acao 'delete' desfeita.\n");
                break;
            }
            case INSERT:
            {
                insertLine(document, actionToExecute->position, actionToExecute->textSaved, NULL, NULL, 1);

                actionToRedo = createAction(DELETE, actionToExecute->position, NULL, 0);
                push(redoStack, actionToRedo);

                printf("-> Acao 'insert' desfeita.\n");
                break;
            }
            case REPLACE:
            {
                LineNode* node = getLineNode(document, actionToExecute->position);
                if (node == NULL) {
                    printf("-> Erro ao desfazer: linha nao encontrada.\n");
                    break;
                }

                char* textToRedo = (char*) malloc(strlen(node->text) + 1);
                strcpy(textToRedo, node->text);

                replaceLine(document, actionToExecute->position, actionToExecute->textSaved, NULL, NULL, 1);

                actionToRedo = createAction(REPLACE, actionToExecute->position, textToRedo, 0);
                push(redoStack, actionToRedo);

                free(textToRedo);
                printf("-> Acao 'replace' desfeita.\n");
                break;
            }
            case JOIN:
            {
                joinLines(document, actionToExecute->position, NULL, NULL, 1);

                actionToRedo = createAction(SPLIT, actionToExecute->position, NULL, actionToExecute->indexSaved);
                push(redoStack, actionToRedo);

                printf("-> Acao 'split' desfeita.\n");
                break;
            }
            case SPLIT:
            {
                splitLine(document, actionToExecute->position, actionToExecute->indexSaved, NULL, NULL, 1);

                actionToRedo = createAction(JOIN, actionToExecute->position, NULL, actionToExecute->indexSaved);
                push(redoStack, actionToRedo);

                printf("-> Acao 'join' desfeita.\n");
                break;
            }
            case APPEND:
            {
                LineNode* node = getLineNode(document, actionToExecute->position);
                if (node == NULL) {
                    printf("-> Erro ao desfazer append: linha nao encontrada.\n");
                    break;
                }

                char* textToRedo = (char*) malloc(strlen(node->text) + 1);
                if (textToRedo == NULL) {
                    perror("-> Erro ao alocar memoria para redo (append).\n");
                    break;
                }
                strcpy(textToRedo, node->text);

                replaceLine(document, actionToExecute->position, actionToExecute->textSaved, NULL, NULL, 1);
                
                actionToRedo = createAction(APPEND, actionToExecute->position, textToRedo, 0);
                push(redoStack, actionToRedo);

                free(textToRedo);
                printf("-> Acao 'append' desfeita.\n");
                break;
            }
        default:
            break;
        }

        freeAction(actionToExecute);
    }
}

void executeRedo(Document* document, Stack* undoStack, Stack* redoStack) {
    UndoAction* actionToExecute = pop(redoStack);

    if (actionToExecute == NULL) {
        printf("-> Nada a refazer.\n");
    } else {
        UndoAction* actionToUndo = NULL;

        switch (actionToExecute->type) {
        case INSERT:
        {
            insertLine(document, actionToExecute->position, actionToExecute->textSaved, NULL, NULL, 1);

            actionToUndo = createAction(DELETE, actionToExecute->position, NULL, 0);
            push(undoStack, actionToUndo);

            printf("-> Acao 'insert' refeita.\n");
            break;
        }
        case DELETE:
        {
            LineNode* node = getLineNode(document, actionToExecute->position);
            if (node == NULL) {
                printf("-> Erro ao refazer: linha nao encontrada.\n");
                break;
            }

            char* textToUndo = (char*) malloc(strlen(node->text) + 1);
            strcpy(textToUndo, node->text);

            deleteLine(document, actionToExecute->position, NULL, NULL, 1);

            actionToUndo = createAction(INSERT, actionToExecute->position, textToUndo, 0);
            push(undoStack, actionToUndo);

            free(textToUndo);
            printf("-> Acao 'delete' refeita.\n");
            break;
        }
        case REPLACE:
        {
            LineNode* node = getLineNode(document, actionToExecute->position);
            if (node == NULL) {
                printf("Erro ao refazer: linha nao encontrada.\n");
                break;
            }

            char* textToUndo = (char*) malloc(strlen(node->text) + 1);
            strcpy(textToUndo, node->text);

            replaceLine(document, actionToExecute->position, actionToExecute->textSaved, NULL, NULL, 1);

            actionToUndo = createAction(REPLACE, actionToExecute->position, textToUndo, 0);
            push(undoStack, actionToUndo);

            free(textToUndo);
            printf("-> Acao 'replace' refeita.\n");
            break;
        }
        case SPLIT:
        {
            splitLine(document, actionToExecute->position, actionToExecute->indexSaved, NULL, NULL, 1);

            actionToUndo = createAction(JOIN, actionToExecute->position, NULL, actionToExecute->indexSaved);
            push(undoStack, actionToUndo);
            
            printf("-> Acao 'split' refeita.\n");
            break;
        }
        case JOIN:
        {
            joinLines(document, actionToExecute->position, NULL, NULL, 1);

            actionToUndo = createAction(SPLIT, actionToExecute->position, NULL, actionToExecute->indexSaved);
            push(undoStack, actionToUndo);

            printf("-> Acao 'join' refeita.\n");
            break;
        }
        case APPEND:
        {
            LineNode* node = getLineNode(document, actionToExecute->position);
            if (node == NULL) {
                printf("-> Erro ao desfazer append: linha nao encontrada.\n");
                break;
            }

            char* textToUndo = (char*) malloc(strlen(node->text) +1);
            if (textToUndo == NULL) {
                perror("-> Erro ao alocar memoria para redo (append).\n");
                break;
            }
            strcpy(textToUndo, node->text);

            replaceLine(document, actionToExecute->position, actionToExecute->textSaved, NULL, NULL, 1);

            actionToUndo = createAction(APPEND, actionToExecute->position, textToUndo, 0);
            push(undoStack, actionToUndo);

            free(textToUndo);
            printf("-> Acao 'append' refeita.\n");
            break;
        }
        default:
            break;
        }

        freeAction(actionToExecute);
    }
}

