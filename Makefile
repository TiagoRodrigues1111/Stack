CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = simplemain.o stack.o
OBJ_ll = simplemain.o stack_ll.o
TARGET = stack_test

# Default target
all: $(TARGET)

run: $(TARGET)
	./$(TARGET)



$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


stack_ll: $(OBJ_ll)
	$(CC) $(OBJ_ll) -o $(TARGET)






simplemain.o: simplemain.c stack.h
	$(CC) $(CFLAGS) -c simplemain.c





stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c


stack_ll.o: stack_ll.c stack.h
	$(CC) $(CFLAGS) -c stack_ll.c






clean:
	rm -f $(OBJ) $(OBJ_ll) $(TARGET)



rebuild: clean all
