# CPP Module 00 - Test Suite

Automated testing framework for C++ Module 00 exercises using GoogleTest.

## Overview

This test suite provides comprehensive unit tests for the three exercises in CPP Module 00:
- Exercise 00: Megaphone
- Exercise 01: My Awesome PhoneBook
- Exercise 02: The Job Of Your Dreams (Bonus)

## Prerequisites

- CMake 3.14 or higher
- C++98 compatible compiler
- Git (for GoogleTest download)
- Make or Ninja build system

## Project Structure

```
tester/
├── CMakeLists.txt
├── README.md
├── test/
│   ├── CMakeLists.txt
│   ├── tester_ex00/
│   ├── tester_ex01/
│   └── tester_ex02/
└── googletest/ (auto-downloaded)
```

## Installation

Clone this repository into your CPP00 project directory:

```bash
git clone <repository-url> tester
cd tester
```

The GoogleTest framework will be automatically downloaded during the first build.

## Building

Create a build directory and compile:

```bash
cd test
mkdir build && cd build
cmake ..
make
```

## Running Tests

### Run all tests

```bash
make run_all
```

or

```bash
ctest --verbose
```

### Run specific exercise tests

```bash
./tester_ex00/TESTER_EX00
./tester_ex01/TESTER_EX01
./tester_ex02/TESTER_EX02
```

## Usage Example

Navigate to the test directory and view the structure:

```bash
cd test
ls
```

![Directory Structure](view-source:https://github.com/Mohahamdali/tester_cpp00/blob/main/images/Screenshot%20from%202026-01-11%2005-59-57.png)

Navigate to test directory:

```bash
cd test
```

![Navigate to test](Screenshot%20from%202026-01-11%2006-00-21.png)

View available test directories:

```bash
ls
```

![Test directories](Screenshot%20from%202026-01-11%2006-01-11.png)

Create build directory and configure with CMake:

```bash
mkdir build && cd build
cmake ..
```

![CMake Configuration](Screenshot%20from%202026-01-11%2006-01-26.png)

Build the project:

```bash
make run_all
```

![Build Process](Screenshot%20from%202026-01-11%2006-02-02.png)

Test execution results showing all test cases with pass/fail status:

![Test Execution Results](Screenshot%20from%202026-01-11%2006-04-24.png)

The output displays all test cases with pass/fail status and execution time for each test.

## Test Coverage

### Exercise 00: Megaphone
- Basic argument handling
- Multiple arguments concatenation
- Empty input behavior
- String transformation verification

### Exercise 01: PhoneBook
- Command validation (ADD, SEARCH, EXIT)
- Contact storage and retrieval
- Field validation (phone number, names)
- Oldest contact replacement
- Display formatting

### Exercise 02: Account (Bonus)
- Account creation and destruction
- Deposit and withdrawal operations
- Status display
- Static member functions
- Timestamp handling

## Configuration

The test suite uses C++98 standard as required by the subject. Color output is enabled by default for better readability.

To modify test behavior, edit the respective test files in each tester directory.

## Troubleshooting

### GoogleTest fails to download

Manually clone GoogleTest:

```bash
cd tester
git clone https://github.com/google/googletest.git googletest
```

### Compilation errors

Ensure your source files are in the correct location relative to the test directory. Check include paths in individual test CMakeLists.txt files.

### Tests fail unexpectedly

Verify your implementation matches the subject requirements. Run tests with verbose output:

```bash
ctest --output-on-failure --verbose
```

## Development

To add new tests:

1. Create test files in the appropriate `tester_exXX` directory
2. Update the corresponding CMakeLists.txt
3. Rebuild the project

Test files follow GoogleTest conventions. Refer to GoogleTest documentation for test writing guidelines.

## Notes

- Tests are designed to match subject requirements strictly
- C++98 standard is enforced during compilation
- All memory leaks should be checked separately with valgrind
- Tests focus on functional correctness, not code style

## License

This test suite is provided as-is for educational purposes.

## Author

Created for 42 School CPP Module evaluation.
