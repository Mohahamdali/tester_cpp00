CXX      := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Wno-error=deprecated-declarations

GTEST_DIR := ../googletest
INCLUDE   := -I $(GTEST_DIR)/googletest/include
LIBS      := -L $(GTEST_DIR)/build/lib -lgtest -lgtest_main

EX02_DIR := ../../cpp00/ex02
EX02_BIN := $(EX02_DIR)/account_exec

# Auto-detect all .cpp files in ex02 directory
EX02_SRC := $(wildcard $(EX02_DIR)/*.cpp)

# Correct test source files (test_uti.cpp not test_utils.cpp)
TEST_SRC := main.cpp test_uti.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_BIN := TESTER_EX02

.PHONY: all test clean fclean re debug

all: check_sources $(EX02_BIN) $(TEST_BIN)

check_sources:
	@if [ -z "$(EX02_SRC)" ]; then \
		echo "ERROR: No source files found in $(EX02_DIR)"; \
		exit 1; \
	fi

$(EX02_BIN): $(EX02_SRC)
	@echo "Building ex02 with: $(notdir $(EX02_SRC))"
	@$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_BIN): $(TEST_OBJ)
	@echo "Building tester..."
	@$(CXX) -std=c++17 -pthread $(INCLUDE) $(TEST_OBJ) $(LIBS) -o $@

%.o: %.cpp
	@$(CXX) -std=c++17 -pthread $(INCLUDE) -c $< -o $@

test: all
	@echo "Running tests..."
	@./$(TEST_BIN)

clean:
	@echo "Cleaning object files..."
	@rm -f $(TEST_OBJ)

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(TEST_BIN) $(EX02_BIN)

re: fclean all

debug:
	@echo "Exercise directory: $(EX02_DIR)"
	@echo "Test sources: $(TEST_SRC)"
	@echo "Test objects: $(TEST_OBJ)"
	@echo "Detected ex02 files: $(notdir $(EX02_SRC))"