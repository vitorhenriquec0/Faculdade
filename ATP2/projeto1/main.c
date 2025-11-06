#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor.h"
#include "stack.h"
#include "undo.h"

int main() {
    char commandLine[1024];
    Document* document = createDocument();

    Stack* undoStack = createStack();
    Stack* redoStack = createStack();

    printf("\nBem-vindo ao mEditor!\n\n");

    while (1) {

        printf("mtext> ");

        if (fgets(commandLine, sizeof(commandLine), stdin) == NULL) {
            break; 
        }

        commandLine[strcspn(commandLine, "\n")] = 0; // Remove o '\n' do final, substituindo por 0
        //  Pois, por exemplo, "print\n" é diferente de "print"
        // o 0 é considerado um caractere nulo "\0", marcando o fim da string.


        if (strncmp(commandLine, "i ", 2) == 0) {
            int pos;
            char textBuffer[1000];

            if (sscanf(commandLine, "i %d %999[^\n]", &pos, textBuffer) == 2) { // [...] == 2 se o usuario digitou a posição e o texto
                insertLine(document, pos, textBuffer, undoStack, redoStack, 0);
            } else {
                printf("-> Erro: Formato invalido. Use: i <pos> <texto>\n");
            }
        }
        else if (strcmp(commandLine, "print") == 0)
            printDocument(document);
        else if (strncmp(commandLine, "save ", 5) == 0) {
            char fileNameBuffer[256];

            if (sscanf(commandLine, "save %255s", fileNameBuffer) == 1) {
                saveDocument(document, fileNameBuffer);
            } else {
                printf("-> Erro: Formato invalido. Use: save <arquivo>.\n");
            }
        }
        else if (strncmp(commandLine, "savebin ", 8) == 0) {
            char fileNameBuffer[256];

            if (sscanf(commandLine, "savebin %255s", fileNameBuffer) == 1) {
                saveDocumentBin(document, fileNameBuffer);
            } else {
                printf("-> Erro: Formato invalido. Use: savebin <arquivo>.\n");
            }
        }
        else if (strncmp(commandLine, "open ", 5) == 0) {
            char fileNameBuffer[256];

            if (sscanf(commandLine, "open %255s", fileNameBuffer) == 1) {
                loadDocument(document, fileNameBuffer, undoStack, redoStack);
                document->mode = MODE_TXT;
            } else {
                printf("-> Erro: Formato invalido. Use: open <arquivo>.\n");
            }
        }
        else if (strncmp(commandLine, "openbin ", 8) == 0) {
            char fileNameBuffer[256];

            if (sscanf(commandLine, "openbin %255s", fileNameBuffer) == 1) {
                loadDocumentBin(document, fileNameBuffer, undoStack, redoStack);
            } else {
                printf("-> Erro: Formato invalido. Use: openbin <arquivo>.\n");
            }
        }
        else if (strncmp(commandLine, "d ", 2) == 0) {
            int position;
            
            if (sscanf(commandLine, "d %d", &position) == 1) {
                deleteLine(document, position, undoStack, redoStack, 0);
            } else {
                printf("-> Erro> Formato invalido. Use: d <pos>.\n");
            }
        }
        else if (strncmp(commandLine, "r ", 2) == 0) {
            int position;
            char textBuffer[1000];

            if(sscanf(commandLine, "r %d %999[^\n]", &position, textBuffer) == 2) {
                replaceLine(document, position, textBuffer, undoStack, redoStack, 0);
            } else {
                printf("-> Erro: Formato invalido. Use: r <posicao> <novo texto>.\n");
            }
        }
        else if (strncmp(commandLine, "a ", 2) == 0) {
            int position;
            char textBuffer[1000];

            if(sscanf(commandLine, "a %d %999[^\n]", &position, textBuffer) == 2) {
                trimQuotes(textBuffer);
                appendLine(document, position, textBuffer, undoStack, redoStack, 0);
            } else {
                printf("-> Erro: Formato invalido. Use: a <posicao> <sufixo>.\n");
            }
        }
        else if (strncmp(commandLine, "split ", 6) == 0) {
            int position, index;

            if (sscanf(commandLine, "split %d %d", &position, &index) == 2) {
                splitLine(document, position, index, undoStack, redoStack, 0);
            } else {
                printf("-> Erro: Formato invalido. Use: split <posicao> <index>.\n");
            }
        }
        else if (strncmp(commandLine, "join ", 5) == 0) {
            int position;

            if (sscanf(commandLine, "join %d", &position) == 1) {
                joinLines(document, position, undoStack, redoStack, 0);
            } else {
                printf("-> Erro: Formato invalido. Use: join <posicao>.\n");
            }
        }
        else if (strcmp(commandLine, "undo") == 0) {
            executeUndo(document, undoStack, redoStack);
        }
        else if (strcmp(commandLine, "redo") == 0) {
            executeRedo(document, undoStack, redoStack);
        }
        else if (strcmp(commandLine, "quit") == 0) {
            break;
        }
        else {
            if(strlen(commandLine) > 0) { // Evita msg para entrada vazia
                printf("-> Comando '%s' desconhecido.\n", commandLine);
            }
        }
    }

    freeDocument(document);

    freeStack(undoStack);
    freeStack(redoStack);

    printf("\nEncerrando o mEditor.\n");
    return 0;
}


