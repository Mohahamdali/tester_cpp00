if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.14)
    project(CPP00_EX00_Test)
    set(CMAKE_CXX_STANDARD 98)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    enable_testing()
    set(GTEST_DIR "${CMAKE_SOURCE_DIR}/../googletest")
    if(EXISTS "${GTEST_DIR}/CMakeLists.txt")
        add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/googletest EXCLUDE_FROM_ALL)
    else()
        message(FATAL_ERROR "GoogleTest not found. Clone it: git clone https://github.com/google/googletest.git ../googletest")
    endif()
    set(EX00_DIR "${CMAKE_SOURCE_DIR}/../../cpp00/ex00")
    set(STANDALONE_BUILD ON)
    message(STATUS "=====================================")
    message(STATUS "STANDALONE BUILD MODE")
    message(STATUS "=====================================")
else()
    set(EX00_DIR "${CMAKE_SOURCE_DIR}/../cpp00/ex00")
    set(STANDALONE_BUILD OFF)
    message(STATUS "  [EX00] Parent build mode")
endif()

message(STATUS "  [EX00] Exercise directory: ${EX00_DIR}")

if(NOT EXISTS ${EX00_DIR})
    message(WARNING "  [EX00] Directory not found: ${EX00_DIR}")
    message(WARNING "  [EX00] Skipping...")
    return()
endif()

file(GLOB EX00_SOURCES "${EX00_DIR}/*.cpp")
if(NOT EX00_SOURCES)
    message(WARNING "  [EX00] No .cpp files in ${EX00_DIR}")
    message(WARNING "  [EX00] Skipping...")
    return()
endif()

message(STATUS "  [EX00] ✓ Found sources: ${EX00_SOURCES}")

file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(megaphone ${EX00_SOURCES})

if(STANDALONE_BUILD)
    set_target_properties(megaphone PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${EX00_DIR}
    )
    add_custom_command(TARGET megaphone POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:megaphone>
            ${EX00_DIR}/megaphone
        COMMAND chmod +x ${EX00_DIR}/megaphone
        COMMENT "  [EX00] Installing megaphone to ${EX00_DIR}"
    )
    get_filename_component(MEGAPHONE_BINARY "${EX00_DIR}/megaphone" ABSOLUTE)
else()
    set_target_properties(megaphone PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
    get_filename_component(MEGAPHONE_BINARY "${CMAKE_CURRENT_BINARY_DIR}/megaphone" ABSOLUTE)
endif()

add_executable(TESTER_EX00 ${TEST_SOURCES})
target_compile_definitions(TESTER_EX00 PRIVATE
    MEGAPHONE_PATH="${MEGAPHONE_BINARY}"
)
target_link_libraries(TESTER_EX00
    gtest
    gtest_main
    pthread
)

add_test(NAME TESTER_EX00 COMMAND TESTER_EX00)
set_tests_properties(TESTER_EX00 PROPERTIES
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

message(STATUS "  [EX00] ✓ Configuration complete")