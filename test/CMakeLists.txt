cmake_minimum_required(VERSION 3.14)
project(CPP00_Tests)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

string(ASCII 27 ESC)
set(CYAN    "${ESC}[36m")
set(GREEN   "${ESC}[32m")
set(YELLOW  "${ESC}[33m")
set(RED     "${ESC}[31m")
set(RESET   "${ESC}[0m")
set(BOLD    "${ESC}[1m")

message("")
message("${BOLD}CPP Module 00 - Test Suite${RESET}")
message("----------------------------------------")
message("")

set(GTEST_DIR "${CMAKE_SOURCE_DIR}/../googletest")

if(NOT EXISTS "${GTEST_DIR}/CMakeLists.txt")
    message("${YELLOW}Downloading GoogleTest...${RESET}")
    execute_process(
        COMMAND git clone https://github.com/google/googletest.git ${GTEST_DIR}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/..
        RESULT_VARIABLE GIT_RESULT
        OUTPUT_QUIET
        ERROR_QUIET
    )
    if(NOT GIT_RESULT EQUAL 0)
        message(FATAL_ERROR "${RED}Error: Failed to clone GoogleTest${RESET}")
    endif()
    message("${GREEN}GoogleTest downloaded successfully${RESET}")
endif()

add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/googletest EXCLUDE_FROM_ALL)

# Add test directories
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tester_ex00")
    add_subdirectory(tester_ex00)
    message("${GREEN}[+]${RESET} Exercise 00 tests configured")
else()
    message("${YELLOW}[!]${RESET} Exercise 00 not found - skipping")
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tester_ex01")
    add_subdirectory(tester_ex01)
    message("${GREEN}[+]${RESET} Exercise 01 tests configured")
else()
    message("${YELLOW}[!]${RESET} Exercise 01 not found - skipping")
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tester_ex02")
    add_subdirectory(tester_ex02)
    message("${GREEN}[+]${RESET} Exercise 02 tests configured (bonus)")
else()
    message("${YELLOW}[!]${RESET} Exercise 02 not found - skipping")
endif()

add_custom_target(run_all
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure --verbose
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS TESTER_EX00 TESTER_EX01 TESTER_EX02 megaphone
    COMMENT "Running test suite..."
)

message("")
message("Build complete. Run tests with:")
message("  ${CYAN}cmake --build build --target run_all${RESET}")
message("  ${CYAN}cd build && ctest --verbose${RESET}")
message("")