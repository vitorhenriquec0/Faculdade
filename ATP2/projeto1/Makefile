CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o editor.o stack.o undo.o
TARGET = mEditor

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
ifeq ($(OS),Windows_NT)
	del /Q $(OBJ) $(TARGET)
else
	rm -f $(OBJ) $(TARGET)
endif