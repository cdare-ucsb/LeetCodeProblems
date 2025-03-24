# Compiler settings
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -O2

# Detect all subdirectories with both driver.cpp and solution.cpp
DIRS := $(shell find . -mindepth 1 -maxdepth 1 -type d \
         -exec test -f "{}/driver.cpp" -a -f "{}/solution.cpp" \; -print | sed 's|^\./||')

# Output directory for built executables
BIN_DIR := bin
TARGETS := $(addprefix $(BIN_DIR)/, $(DIRS))

.PHONY: all clean $(DIRS)

all: $(BIN_DIR) $(TARGETS)

# Build each executable: bin/ClimbingStairs, etc.
$(BIN_DIR)/%: %/driver.cpp %/solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(BIN_DIR)
