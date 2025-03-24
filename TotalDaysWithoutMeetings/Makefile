# Compiler
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -O2

# Output executable name
TARGET = run

# Source files
SRCS = driver.cpp solution.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
