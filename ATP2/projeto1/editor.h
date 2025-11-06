#ifndef EDITOR_H
#define EDITOR_H

#include "stack.h"

typedef struct LineNode {
    char* text;
    struct LineNode* prev;
    struct LineNode* next;
} LineNode;

typedef enum {
    MODE_BIN,
    MODE_TXT
} FileMode;

typedef struct Document {
    LineNode* head;
    LineNode* tail;
    int lineCount;
    FileMode mode;
} Document;

LineNode* getLineNode(Document* document, int position);

Document* createDocument();

void freeDocument(Document* document);

void insertLine(Document* document, int position, const char* text, Stack* undoStack, Stack* redoStack, int quiet);

void printDocument(Document* document);

void saveDocument(Document* document, const char* fileName);

void saveDocumentBin(Document* document, const char* fileName);

void loadDocument(Document* document, const char* fileName, Stack* undoStack, Stack* redoStack);

void loadDocumentBin(Document* document, const char* fileName, Stack* undoStack, Stack* redoStack);

void deleteLine(Document* document, int position, Stack* undoStack, Stack* redoStack, int quiet);

void replaceLine(Document* document, int position, const char* newText, Stack* undoStack, Stack* redoStack, int quiet);

void appendLine(Document* document, int position, const char* suffix, Stack* undoStack, Stack* redoStack, int quiet);

void splitLine(Document* document, int position, int index, Stack* undoStack, Stack* redoStack, int quiet);

void joinLines(Document* document, int position, Stack* undoStack, Stack* redoStack, int quiet);

void trimQuotes(char* str);

#endif