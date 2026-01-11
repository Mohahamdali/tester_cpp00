if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.14)
    project(CPP00_EX01_Test)
    set(CMAKE_CXX_STANDARD 98)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    enable_testing()
    set(GTEST_DIR "${CMAKE_SOURCE_DIR}/../googletest")
    if(EXISTS "${GTEST_DIR}/CMakeLists.txt")
        add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/googletest EXCLUDE_FROM_ALL)
    else()
        message(FATAL_ERROR "GoogleTest not found. Clone it: git clone https://github.com/google/googletest.git ../googletest")
    endif()
    set(EX01_DIR "${CMAKE_SOURCE_DIR}/../../cpp00/ex01")
    set(STANDALONE_BUILD ON)
    message(STATUS "=====================================")
    message(STATUS "STANDALONE BUILD MODE")
    message(STATUS "=====================================")
else()
    set(EX01_DIR "${CMAKE_SOURCE_DIR}/../cpp00/ex01")
    set(STANDALONE_BUILD OFF)
    message(STATUS "  [EX01] Parent build mode")
endif()

message(STATUS "  [EX01] Exercise directory: ${EX01_DIR}")

if(NOT EXISTS ${EX01_DIR})
    message(WARNING "  [EX01] Directory not found: ${EX01_DIR}")
    message(WARNING "  [EX01] Skipping...")
    return()
endif()

file(GLOB EX01_SOURCES "${EX01_DIR}/*.cpp")

if(NOT EX01_SOURCES)
    message(WARNING "  [EX01] No .cpp files in ${EX01_DIR}")
    message(WARNING "  [EX01] Skipping...")
    return()
endif()

message(STATUS "  [EX01] ✓ Found sources:")
foreach(src ${EX01_SOURCES})
    message(STATUS "    - ${src}")
endforeach()

file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(phonebook ${EX01_SOURCES})

if(STANDALONE_BUILD)
    set_target_properties(phonebook PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${EX01_DIR}
    )
    set(EX01_BINARY "${EX01_DIR}/phonebook")
else()
    set_target_properties(phonebook PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${EX01_DIR}
    )
    set(EX01_BINARY "${EX01_DIR}/phonebook")
endif()

add_custom_command(TARGET phonebook POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:phonebook> ${EX01_DIR}/phonebook
    COMMAND chmod +x ${EX01_DIR}/phonebook
    COMMENT "Installing phonebook to ${EX01_DIR}"
)

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set_target_properties(phonebook PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

add_executable(TESTER_EX01 ${TEST_SOURCES})

set_target_properties(TESTER_EX01 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set_target_properties(TESTER_EX01 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

target_compile_definitions(TESTER_EX01 PRIVATE
    EX01_BINARY_PATH="${EX01_BINARY}"
)

target_link_libraries(TESTER_EX01
    gtest
    gtest_main
    pthread
)

add_test(NAME TESTER_EX01 COMMAND TESTER_EX01)
set_tests_properties(TESTER_EX01 PROPERTIES
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

message(STATUS "  [EX01] ✓ Configuration complete")