#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"
#include "stack.h"

static LineNode* createLineNode(const char* text) {

    LineNode* newNode = (LineNode*) malloc(sizeof(LineNode));
    if (newNode == NULL) {
        printf("Erro ao alocar memoria para o no da linha.\n");
        return NULL;
    }

    newNode->text = (char*) malloc(strlen(text) + 1);
    if (newNode->text == NULL) {
        printf("Erro ao alocar memoria para o texto da linha.\n");
        free(newNode);
        return NULL;
    }

    strcpy(newNode->text, text);

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

static void printRecursive(LineNode* currentLine, int lineNumber) {

    // caso base, pois chegou ao fim da lista
    if (currentLine == NULL) {
        return; // a recursão para aqui
    }

    printf("%2d | %s\n", lineNumber, currentLine->text);

    printRecursive(currentLine->next, lineNumber + 1);
}

static void saveRecursive(LineNode* currentLine, FILE* file_ptr, int lineNumber) {

    if (currentLine == NULL) return; // Caso base, a recursão para aqui

    fprintf(file_ptr, "%2d | %s\n", lineNumber, currentLine->text);

    saveRecursive(currentLine->next, file_ptr, lineNumber + 1);
}

static void saveRecursiveBin(LineNode* currentLine, FILE* file_ptr) {
    if (currentLine == NULL) return; // caso base, a recursão para por aqui

    int len = strlen(currentLine->text) + 1;
    fwrite(&len, sizeof(int), 1, file_ptr);
    fwrite(currentLine->text, sizeof(char), len, file_ptr);

    saveRecursiveBin(currentLine->next, file_ptr);
}

void loadRecursiveBin(Document* document, FILE* file_ptr, int totalLines) {
    if (totalLines <= 0) return;

    int len;
    if (fread(&len, sizeof(int), 1, file_ptr) != 1) {
        printf("-> Erro ao ler comprimento da linha (arquivo corrompido).\n");
        return;
    }

    if (len <= 0 || len > 10000) {
        printf("-> Erro: tamanho de linha invalido (%d).\n", len); // evita leitura absurda
        return;
    }

    char* lineContent = (char*) malloc(len);
    if (lineContent == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }

    size_t readCount = fread(lineContent, sizeof(char), len, file_ptr);
    if (readCount != (size_t)len) {
        printf("-> Erro: nao foi possivel ler todos os caracteres da linha.\n");
        free(lineContent);
        return;
    }
    insertLine(document, document->lineCount + 1, lineContent, NULL, NULL, 0);

    free(lineContent);

    loadRecursiveBin(document, file_ptr, totalLines - 1);
}

static void clearDocument(Document* document) {

    if (document == NULL) return;

    LineNode* currentLine = document->head;
    LineNode* nextLine;

    while (currentLine != NULL) {
        nextLine = currentLine->next;
        free(currentLine->text);
        free(currentLine);
        currentLine = nextLine;
    }

    document->head = NULL;
    document->tail = NULL;
    document->lineCount = 0;
}

LineNode* getLineNode(Document* document, int position) {

    if (document == NULL || position < 1 || position > document->lineCount) {
        return NULL;
    }

    LineNode* current;

    if (position <= document->lineCount / 2) { // complexidade O(n/2) ao inves de O(n)
        current = document->head;
        for (int i = 1; i < position; i++) {
        if (current == NULL) {
            return NULL; // por segurança
        }
        current = current->next;
        }
    } else {
        current = document->tail;
        for (int i = document->lineCount; i > position; i--) {
            if (current == NULL) {
                return NULL; // por segurança
            }
            current = current->prev;
        }
    }
    return current;
}

Document* createDocument() {

    Document* document = (Document*) malloc(sizeof(Document));

    if (document == NULL) {
        printf("Erro ao alocar memoria para o documento.\n");
        return NULL;
    }

    document->head = NULL;
    document->tail = NULL;
    document->lineCount = 0;
    document->mode = MODE_TXT; // padrão pra inicializar

    return document;
}

void freeDocument(Document* document) {

    if (document == NULL) return; // pois se o ponteiro for nulo, não há nada a fazer

    LineNode* currentLine = document->head;
    LineNode* nextLine;

    while (currentLine != NULL) {

        nextLine = currentLine->next; // salvar o end da prox linha antes de apagar a atual

        free(currentLine->text);
        free(currentLine);

        currentLine = nextLine; // move p linha que guardamos
    }

    free(document);
}

void insertLine(Document* document, int position, const char* text, Stack* undoStack, Stack* redoStack, int quiet) {

    if (document == NULL) return;

    int recordUndo = (undoStack != NULL && redoStack != NULL);

    LineNode* newNode = createLineNode(text);
    if(newNode == NULL) return; // falha ao criar o nó

    int actualPos = 1;

    if (document-> head == NULL) {
        document->head = newNode;
        document->tail = newNode;
        actualPos = 1;
    } else if (position <= 1) {
        newNode->next = document->head;
        document->head->prev = newNode;
        document->head = newNode;
        actualPos = 1;
    } else if (position > document->lineCount) {
        newNode->prev = document->tail;
        document->tail->next = newNode;
        document->tail = newNode;
        actualPos = document->lineCount + 1;
    } else {
        // insere no meio, colocar o newNode na posição 'position'
        LineNode* current = document->head;

        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        actualPos = position;
    }

    document->lineCount++;

    if (recordUndo) {
        // usar actualPos como parametro, caso o usuario digite um position > document->lineCount (posição inexistente)
        UndoAction* action = createAction(DELETE, actualPos, NULL, 0);
        push(undoStack, action);

        clearStack(redoStack);
    }

    if (!quiet && undoStack != NULL && redoStack != NULL) printf("-> Linha inserida na pos %d.\n", position);
}

void printDocument(Document* document) {
    if (document == NULL || document->head == NULL) {
        printf("-- Documento vazio --\n");
        return;
    }
    printRecursive(document->head, 1);
}

void saveDocument(Document* document, const char* fileName) {

    if (document == NULL) {
        printf("-> Erro: Documento invalido.\n");
        return;
    }

    FILE* file_ptr = fopen(fileName, "w");

    if (file_ptr == NULL) {
        perror("-> Erro ao abrir o arquivo.\n");
        return;
    }

    saveRecursive(document->head, file_ptr, 1);

    fclose(file_ptr);

    printf("-> Documento salvo em '%s'!\n", fileName);
}

void saveDocumentBin(Document* document, const char* fileName) {

    if (document == NULL) {
        printf("-> Erro: Documento invalido.\n");
        return;
    }

    FILE* file_ptr = fopen(fileName, "wb");
    if (file_ptr == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }

    int count = 0;
    for (LineNode* currentLine = document->head; currentLine; currentLine = currentLine->next) count++;
    fwrite(&count, sizeof(int), 1, file_ptr);

    saveRecursiveBin(document->head, file_ptr);

    fclose(file_ptr);
    printf("-> Documento salvo em formato binario.\n");
}

void loadDocument(Document* document, const char* fileName, Stack* undoStack, Stack* redoStack) {

    if (document == NULL) return;

    FILE* file_ptr = fopen(fileName, "r");

    if (file_ptr == NULL) {

        file_ptr = fopen(fileName, "w");
        if (file_ptr == NULL) {
            perror("-> Erro ao criar novo arquivo.\n");
            return;
        }
        fclose(file_ptr);
        printf("-> Arquivo '%s' criado e aberto", fileName);
        clearDocument(document);
        clearStack(undoStack);
        clearStack(redoStack);
        return;
    }

    clearStack(undoStack);
    clearStack(redoStack);
    clearDocument(document);

    char lineBuffer[2048];

    while (fgets(lineBuffer, sizeof(lineBuffer), file_ptr) != NULL) {

        lineBuffer[strcspn(lineBuffer, "\n")] = 0;

        // (lineCount + 1) sempre insere no final
        insertLine(document, document->lineCount + 1, lineBuffer, NULL, NULL, 0);
    }

    fclose(file_ptr);

    printf("-> Documento '%s' carregado.\n", fileName);
}

void loadDocumentBin(Document* document, const char* fileName, Stack* undoStack, Stack* redoStack) {

    if (document == NULL) return;

    FILE* file_ptr = fopen(fileName, "rb");

    if (file_ptr == NULL) {
        file_ptr = fopen(fileName, "wb");
        if (file_ptr == NULL) {
            perror("-> Erro ao criar novo arquivo binario.\n");
            return;
        }
        fclose(file_ptr);
        printf("-> Arquivo binario '%s' criado e aberto.\n", fileName);
        clearDocument(document);
        clearStack(undoStack);
        clearStack(redoStack);
        return;
    }

    clearStack(undoStack);
    clearStack(redoStack);
    clearDocument(document);

    int totalLines = 0;
    fread(&totalLines, sizeof(int), 1, file_ptr);

    if (totalLines > 0) loadRecursiveBin(document, file_ptr, totalLines);

    fclose(file_ptr);
    printf("-> Documento '%s' carregado (binario).\n", fileName);
}

void deleteLine(Document* document, int position, Stack* undoStack, Stack* redoStack, int quiet) {
    
    int recordUndo = (undoStack != NULL && redoStack != NULL);
    char* textToSave = NULL;

    LineNode* nodeToDelete = getLineNode(document, position);
    if (nodeToDelete == NULL) {
        printf("-> Erro: Linha %d invalida.\n", position);
        return;
    }

    if (recordUndo) {
        textToSave = (char*) malloc(strlen(nodeToDelete->text) + 1);
        if (textToSave != NULL) {
            strcpy(textToSave, nodeToDelete->text);
        } else {
            perror("-> Erro ao salvar texto para undo (delete).\n");
            recordUndo = 0; // Cancela o undo
        }
    }

    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    } else {
        document->head = nodeToDelete->next;
    }

    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    } else {
        document->tail = nodeToDelete->prev;
    }

    free(nodeToDelete->text);
    free(nodeToDelete);

    document->lineCount--;

    if (recordUndo) {
        UndoAction* action = createAction(INSERT, position, textToSave, 0);
        push(undoStack, action);
        clearStack(redoStack);

        free(textToSave);
    }

    if (!quiet) printf("-> Linha %d removida.\n", position);
}

void replaceLine(Document* document, int position, const char* newText, Stack* undoStack, Stack* redoStack, int quiet) {
    
    int recordUndo = (undoStack != NULL && redoStack != NULL);
    char* textToSave = NULL;

    LineNode* nodeToReplace = getLineNode(document, position);
    if (nodeToReplace == NULL) {
        printf("-> Erro: Linha %d invalida.\n", position);
        return;
    }

    if (recordUndo) {
        textToSave = (char*) malloc(strlen(nodeToReplace->text) + 1);
        if (textToSave != NULL) {
            strcpy(textToSave, nodeToReplace->text);
        } else {
            perror("-> Erro ao salvar texto para undo (replace).\n");
            recordUndo = 0; // Cancela o undo
        }
    }

    free(nodeToReplace->text);

    // Alocação de memória, incluindo o '\0'
    nodeToReplace->text = (char*) malloc(strlen(newText) + 1);

    if (nodeToReplace->text == NULL) {
        perror("-> Erro ao alocar memoria para o novo text.\n");

        // Colocando um texto vazio para evitar uma quebra
        nodeToReplace->text = (char*) malloc(1);
        nodeToReplace->text[0] = '\0';

        if (textToSave != NULL) free(textToSave);

        return;
    }

    strcpy(nodeToReplace->text, newText);

    if (recordUndo) {
        UndoAction* action = createAction(REPLACE, position, textToSave, 0);
        push(undoStack, action);
        clearStack(redoStack);

        free(textToSave);
    }

    if (!quiet) printf("-> Linha %d substituida.\n", position);
}

void appendLine(Document* document, int position, const char* suffix, Stack* undoStack, Stack* redoStack, int quiet) {

    int recordUndo = (undoStack != NULL && redoStack != NULL);
    char* textToSave = NULL;

    LineNode* nodeToAppend = getLineNode(document, position);
    if (nodeToAppend == NULL) {
        printf("-> Erro: Linha %d invalida.\n", position);
        return;
    }

    if (recordUndo) {
        textToSave = (char*) malloc(strlen(nodeToAppend->text) + 1);
        if (textToSave != NULL) {
            strcpy(textToSave, nodeToAppend->text);
        } else {
            perror("-> Erro ao salvar texto para undo (append).\n");
            recordUndo = 0; // Cancela o undo
        }
    }

    size_t originalLen = strlen(nodeToAppend->text);
    size_t suffixLen = strlen(suffix);

    size_t newLen = originalLen + suffixLen + 1;

    char* newTextPtr = (char*) realloc(nodeToAppend->text, newLen);

    if (newTextPtr == NULL) {
        perror("-> Erro ao realocar memoria para o sufixo.\n");

        // Se undo foi cancelado, libera o textToSave
        if (textToSave != NULL) free(textToSave);

        return;
    }

    nodeToAppend->text = newTextPtr;

    strcat(nodeToAppend->text, suffix);

    if (recordUndo) {
        UndoAction* action = createAction(APPEND, position, textToSave, 0);
        push(undoStack, action);
        clearStack(redoStack);

        free(textToSave);
    }

    if (!quiet) printf("-> Sufixo anexado a linha %d.\n", position);
}

void splitLine(Document* document, int position, int index, Stack* undoStack, Stack* redoStack, int quiet) {

    int recordUndo = (undoStack != NULL && redoStack != NULL);

    LineNode* nodeToSplit = getLineNode(document, position);
    if (nodeToSplit == NULL) {
        printf("-> Erro: Linha %d invalida.\n", position);
        return;
    }

    int len = strlen(nodeToSplit->text);

    if (index < 0 || index > len) {
        printf("-> Erro: Indice %d invalido. Deve estar entre 0 e %d.\n", index, len);
        return;
    }

    char* secondHalf = nodeToSplit->text + index;

    insertLine(document, position + 1, secondHalf, NULL, NULL, quiet);

    nodeToSplit->text[index] = '\0';

    char* newTextPtr = (char*) realloc(nodeToSplit->text, index + 1);
    if (newTextPtr == NULL) {
        perror("-> Erro ao alocar memoria apos slit.\n");
    } else {
        nodeToSplit->text = newTextPtr;
    }

    if (recordUndo) {
        UndoAction* action = createAction(JOIN, position, NULL, index);
        push(undoStack, action);
        clearStack(redoStack);
    }

    if (!quiet) printf("-> Linha %d dividida no indice %d.\n", position, index);
}

void joinLines(Document* document, int position, Stack* undoStack, Stack* redoStack, int quiet) {
    
    int recordUndo = (undoStack != NULL && redoStack != NULL);
    int indexToSave = 0;

    LineNode* firstNode = getLineNode(document, position);
    if (firstNode == NULL) {
        printf("-> Erro: Linha %d invalida.\n", position);
        return;
    }

    LineNode* secondNode = firstNode->next;
    if (secondNode == NULL) {
        printf("-> Erro: Nao ha linha seguinte para unir.\n");
        return;
    }

    if (recordUndo) {
        indexToSave = strlen(firstNode->text);
    }

    size_t firstLen = strlen(firstNode->text);
    size_t secondLen = strlen(secondNode->text);
    size_t newLen = firstLen + secondLen + 1; // +1 para o '\0'

    char* newTextPtr = (char*) realloc(firstNode->text, newLen);
    if (newTextPtr == NULL) {
        perror("-> Erro ao alocar memoria para a juncao das linhas.\n");
        return;
    }

    firstNode->text = newTextPtr;
    strcat(firstNode->text, secondNode->text);

    deleteLine(document, position + 1, NULL, NULL, quiet);

    if (recordUndo) {
        UndoAction* action = createAction(SPLIT, position, NULL, indexToSave);
        push(undoStack, action);
        clearStack(redoStack);
    }

    if (!quiet) printf("-> Linha %d unida com a linha %d.\n", position, position + 1);
}

void trimQuotes(char* str) {
    size_t len = strlen(str);

    if (len >= 2 && str[0] == '"' && str[len - 1] == '"') {
        if (len > 2)
            memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
    }
}