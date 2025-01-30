CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = simplemain.o stack.o
TARGET = stack_test

# Default target
all: $(TARGET)


run: $(TARGET)
	./$(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


# Compile main.c to main.o
simplemain.o: simplemain.c stack.h
	$(CC) $(CFLAGS) -c main.c

# Compile stack.c to stack.o
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

# Compile stack.c to stack.o
#stack.o: stack_ll.c stack.h
#	$(CC) $(CFLAGS) -c stack_ll.c

# Clean the build
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild the project
rebuild: clean all
