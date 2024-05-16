# files to compile
OBJS = 01_hello_SDL.cpp

# compiler
CC = g++

COMPILER_FLAGS = -w # suppress all warnings

LINKER_FLAGS = -lSDL2

# name of executable
OBJ_NAME = 01_hello_SDL

# target that compiles the executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
