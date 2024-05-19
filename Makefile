# Source directory
SRC_DIR = src/

# Files to compile
SRCS = $(wildcard $(SRC_DIR)*.cpp)

# Object files directory
OBJ_DIR = build/

# Object files
OBJS = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))

# Compiler
CC = g++

# Compiler flags
COMPILER_FLAGS = -w # suppress all warnings

# Linker flags
LINKER_FLAGS = -lSDL2

# Path to build directory
BUILD_PATH = build/

# Name of executable
OBJ_NAME = out

# Target that compiles the executable
all: $(OBJ_NAME)

$(OBJ_NAME): $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BUILD_PATH)$(OBJ_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BUILD_PATH)$(OBJ_NAME)

.PHONY: all clean