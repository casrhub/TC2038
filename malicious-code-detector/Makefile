# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = main

# Source files
SRCS = main.cpp KMPMatcher.cpp Manacher.cpp LCS.cpp

# Default target: Build the program
all: $(TARGET)

# Link the source files directly to create the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean up the target (optional)
clean:
	rm -f $(TARGET)
