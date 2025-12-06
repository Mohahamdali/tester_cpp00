CXX      := c++
CXXFLAGS := -std=c++17 -pthread

GTEST_DIR := ../googletest
INCLUDE   := -I $(GTEST_DIR)/googletest/include
LIBS      := -L $(GTEST_DIR)/build/lib -lgtest -lgtest_main

EX01_DIR := ../../cpp00/ex01
EX01_BIN := $(EX01_DIR)/phonebook


EX01_SRC := $(filter-out %test.cpp %Test.cpp, $(wildcard $(EX01_DIR)/*.cpp))

ifeq ($(EX01_SRC),)
    EX01_SRC := $(filter-out %test.cpp %Test.cpp, $(wildcard $(EX01_DIR)/**/*.cpp))
endif

TEST_SRC := main.cpp test_utils.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_BIN := TESTER_EX01

.PHONY: all test clean fclean re debug

all: check_sources $(EX01_BIN) $(TEST_BIN)

check_sources:
	@if [ -z "$(EX01_SRC)" ]; then \
		echo "ERROR: No source files found in $(EX01_DIR)"; \
		exit 1; \
	fi

$(EX01_BIN): $(EX01_SRC)
	@echo "Building ex01 with: $(notdir $(EX01_SRC))"
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
	@rm -f $(TEST_OBJ)

fclean: clean
	@rm -f $(TEST_BIN) $(EX01_BIN)

re: fclean all

debug:
	@echo "Exercise directory: $(EX01_DIR)"
	@echo "Detected files: $(notdir $(EX01_SRC))"
	@echo "Full paths:"
	@echo "$(EX01_SRC)" | tr ' ' '\n'