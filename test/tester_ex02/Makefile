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
EX02_SRC := $(EX02_DIR)/Account.cpp $(EX02_DIR)/tests.cpp
EX02_BIN := $(EX02_DIR)/account_exec

TEST_SRC := main.cpp test_uti.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_BIN := TESTER_EX02

# -------------------------
# Default target
# -------------------------
all: $(EX02_BIN) $(TEST_BIN)

# -------------------------
# Compile ex02 program (student's)
# -------------------------
$(EX02_BIN): $(EX02_SRC)
	@echo "Compiling ex02 program..."
	$(CXX) $(CXXFLAGS) $^ -o $@

# -------------------------
# Compile tester
# -------------------------
$(TEST_BIN): $(TEST_OBJ)
	@echo "Compiling tester..."
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TEST_OBJ) $(LIBS) -o $@

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
	rm -f $(TEST_OBJ)

# -------------------------
# Clean everything
# -------------------------
fclean: clean
	@echo "Cleaning binaries..."
	rm -f $(TEST_BIN) $(EX02_BIN)

# -------------------------
# Rebuild
# -------------------------
re: fclean all
