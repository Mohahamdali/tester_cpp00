CXX      := c++
CXXFLAGS := -std=c++17 -pthread

GTEST_DIR := ../googletest
INCLUDE   := -I $(GTEST_DIR)/googletest/include
LIBS      := -L $(GTEST_DIR)/build/lib -lgtest -lgtest_main

EX00_DIR := ../../cpp00/ex00
EX00_BIN := $(EX00_DIR)/megaphone

# Auto-detect all .cpp files in ex00 directory
EX00_SRC := $(wildcard $(EX00_DIR)/*.cpp)

TEST_SRC := main.cpp tester_utils.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_BIN := TESTER_EX00

.PHONY: all test clean fclean re debug

all: check_sources $(EX00_BIN) $(TEST_BIN)

check_sources:
	@if [ -z "$(EX00_SRC)" ]; then \
		echo "ERROR: No source files found in $(EX00_DIR)"; \
		exit 1; \
	fi

$(EX00_BIN): $(EX00_SRC)
	@echo "Building ex00 with: $(notdir $(EX00_SRC))"
	@$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_BIN): $(TEST_OBJ)
	@echo "Building tester..."
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $(TEST_OBJ) $(LIBS) -o $@

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

test: all
	@echo "Running tests..."
	@./$(TEST_BIN)

clean:
	@echo "Cleaning object files..."
	@rm -f $(TEST_OBJ)

fclean: clean
	@echo "Cleaning binaries..."
	@rm -f $(TEST_BIN) $(EX00_BIN)

re: fclean all

debug:
	@echo "Exercise directory: $(EX00_DIR)"
	@echo "Detected files: $(notdir $(EX00_SRC))"