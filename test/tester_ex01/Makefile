CXX      := c++
CXXFLAGS := -std=c++17 -pthread

GTEST_DIR := ../googletest
INCLUDE   := -I $(GTEST_DIR)/googletest/include
LIBS      := -L $(GTEST_DIR)/build/lib -lgtest -lgtest_main

EX01_DIR := ../../cpp00/ex01
EX01_BIN := $(EX01_DIR)/phonebook

EX01_SRC := $(wildcard $(EX01_DIR)/*.cpp)


ifeq ($(EX01_SRC),)
    EX01_SRC := $(wildcard $(EX01_DIR)/*.cpp $(EX01_DIR)/*/*.cpp)
endif

TEST_SRC := main.cpp test_utils.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_BIN := TESTER_EX01

all: $(EX01_BIN) $(TEST_BIN)

$(EX01_BIN): $(EX01_SRC)
	@echo "Compiling ex01 program with files:"
	@echo "  $(notdir $(EX01_SRC))"
	@$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_BIN): $(TEST_OBJ)
	@echo "Compiling tester..."
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
	@rm -f $(TEST_BIN) $(EX01_BIN)

re: fclean all

debug:
	@echo "Exercise directory: $(EX01_DIR)"
	@echo "Detected source files:"
	@echo "$(EX01_SRC)"

.PHONY: all test clean fclean re debug