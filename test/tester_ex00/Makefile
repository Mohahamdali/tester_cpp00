
CXX      := c++
CXXFLAGS := -std=c++17  -pthread


GTEST_DIR := ../googletest
INCLUDE   := -I $(GTEST_DIR)/googletest/include
LIBS      := -L $(GTEST_DIR)/build/lib -lgtest -lgtest_main


EX00_DIR := ../../cpp00/ex00
EX00_SRC := $(EX00_DIR)/megaphone.cpp
EX00_BIN := $(EX00_DIR)/megaphone

TEST_SRC := main.cpp tester_utils.cpp
TEST_OBJ := $(TEST_SRC:.cpp=.o)
TEST_BIN := TESTER_EX00


all: $(EX00_BIN) $(TEST_BIN)


$(EX00_BIN): $(EX00_SRC)
	@echo "Compiling ex00 program..."
	$(CXX) $(CXXFLAGS) $< -o $@


$(TEST_BIN): $(TEST_OBJ)
	@echo "Compiling tester..."
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(TEST_OBJ) $(LIBS) -o $@


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


test: all
	@echo "Running tests..."
	./$(TEST_BIN)


clean:
	@echo "Cleaning object files..."
	rm -f $(TEST_OBJ)


fclean: clean
	@echo "Cleaning binaries..."
	rm -f $(TEST_BIN) $(EX00_BIN)

# -------------------------

