# files to compile
OBJS = main.cpp

# compiler
CC = g++

COMPILER_FLAGS = -w # suppress all warnings

LINKER_FLAGS = -lSDL2

# path to build directory
BUILD_PATH = build/

# name of executable
OBJ_NAME = out

# target that compiles the executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BUILD_PATH)$(OBJ_NAME)
