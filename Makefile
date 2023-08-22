# Directories
SRC_DIR := .\src
INCLUDE_DIR := -I.\include -I.\libs\include
BIN_DIR := .\bin
LIBS_DIR := .\libs
GLFWFLAG := -lglfw3 -lopengl32 -lgdi32
GDBFLAG := -Wno-unused-parameter

# Compiler and flags for cross-compiling to Windows
CXX := g++
CXXFLAGS := -g -std=c++2a -Wall -Wextra $(GDBFLAG) $(INCLUDE_DIR) -L$(LIBS_DIR)

# Find all .cpp files in src directory and its subdirectories
CPP_SRCS := $(shell dir /b /s $(SRC_DIR)\*.cpp)

# Generate corresponding .o file names in build directory for .cpp files
CPP_OBJS := $(foreach src,$(CPP_SRCS),$(patsubst $(SRC_DIR)\%.cpp,$(BIN_DIR)\%.o,$(src)))

# Find all .c files in src directory and its subdirectories
C_SRCS := $(shell dir /b /s $(SRC_DIR)\*.c)

# Generate corresponding .o file names in build directory for .c files
C_OBJS := $(foreach src,$(C_SRCS),$(patsubst $(SRC_DIR)\%.c,$(BIN_DIR)\%.o,$(src)))

# Output binary name and location
TARGET := $(BIN_DIR)\amethyst.exe

# DLL files to be copied
DLL_FILES := $(wildcard *.dll)

# Default target
all: copy_dlls $(TARGET)

# Linking rule
$(TARGET): $(CPP_OBJS) $(C_OBJS)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GLFWFLAG)

# Compilation rule for .cpp files
$(BIN_DIR)\%.o: $(SRC_DIR)\%.cpp $(SRC_DIR)\%.c
	@if not exist $(dir $@) mkdir $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to copy DLL files
copy_dlls: $(DLL_FILES)
	@if not exist $(BIN_DIR) (mkdir $(BIN_DIR) && @for %%i in ($(DLL_FILES)) do copy /Y "%%i" "$(BIN_DIR)")

# Clean rule
clean:
	@if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)

.PHONY: all debug clean copy_dlls
