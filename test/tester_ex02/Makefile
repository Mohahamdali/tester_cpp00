# -------------------------
# Compiler and flags
# -------------------------
CXX      := c++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -pthread

# -------------------------
# GoogleTest paths
# -------------------------
GTEST_DIR := ../../googletest
INCLUDE   := -I $(GTEST_DIR)/googletest/include
LIBS      := -L $(GTEST_DIR)/build/lib -lgtest -lgtest_main

# -------------------------
# Paths and files
# -------------------------
EX02_DIR := ../../cpp00/ex02
EX02_SRC := $(EX02_DIR)/Account.cpp
EX02_OBJ := $(EX02_SRC:.cpp=.o)

TEST_SRC := main.cpp test_uti.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_BIN := TESTER_EX02

# -------------------------
# Default target
# -------------------------
all: $(TEST_BIN)

# -------------------------
# Compile the tester (links with Account.o)
# -------------------------
$(TEST_BIN): $(TEST_OBJ) $(EX02_OBJ)
	@echo "Compiling tester for ex02..."
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

# -------------------------
# Compile .cpp -> .o
# -------------------------
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# -------------------------
# Run the tester
# -------------------------
test: all
	@echo "Running tests..."
	./$(TEST_BIN)

# -------------------------
# Clean object files
# -------------------------
clean:
	@echo "Cleaning object files..."
	rm -f $(TEST_OBJ) $(EX02_OBJ)

# -------------------------
# Clean everything
# -------------------------
fclean: clean
	@echo "Cleaning binaries..."
	rm -f $(TEST_BIN)
