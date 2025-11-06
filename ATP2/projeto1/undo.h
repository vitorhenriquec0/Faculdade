#ifndef UNDO_H
#define UNDO_H

#include "stack.h"
#include "editor.h"

void executeUndo(Document* document, Stack* undoStack, Stack* redoStack);

void executeRedo(Document* document, Stack* undoStack, Stack* redoStack);

#endif