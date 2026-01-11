if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.14)
    project(CPP00_EX02_Test)
    set(CMAKE_CXX_STANDARD 98)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    enable_testing()
    
    set(GTEST_DIR "${CMAKE_SOURCE_DIR}/../googletest")
    if(EXISTS "${GTEST_DIR}/CMakeLists.txt")
        add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/googletest EXCLUDE_FROM_ALL)
    else()
        message(FATAL_ERROR "GoogleTest not found. Clone it: git clone https://github.com/google/googletest.git ../googletest")
    endif()
    
    set(EX02_DIR "${CMAKE_SOURCE_DIR}/../../cpp00/ex02")
    set(STANDALONE_BUILD ON)
    message(STATUS "=====================================")
    message(STATUS "STANDALONE BUILD MODE")
    message(STATUS "=====================================")
else()
    set(EX02_DIR "${CMAKE_SOURCE_DIR}/../cpp00/ex02")
    set(STANDALONE_BUILD OFF)
    message(STATUS "  [EX02] Parent build mode")
endif()

message(STATUS "  [EX02] Exercise directory: ${EX02_DIR}")

if(NOT EXISTS ${EX02_DIR})
    message(WARNING "  [EX02] Directory not found: ${EX02_DIR}")
    message(WARNING "  [EX02] Skipping...")
    return()
endif()

file(GLOB EX02_SOURCES "${EX02_DIR}/*.cpp")

if(NOT EX02_SOURCES)
    message(WARNING "  [EX02] No .cpp files in ${EX02_DIR}")
    message(WARNING "  [EX02] Skipping...")
    return()
endif()

message(STATUS "  [EX02] ✓ Found sources:")
foreach(src ${EX02_SOURCES})
    message(STATUS "    - ${src}")
endforeach()

file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set(ACCOUNT_SOURCE "")
set(TESTS_MAIN "")

foreach(SOURCE ${EX02_SOURCES})
    get_filename_component(FILENAME ${SOURCE} NAME)
    if(FILENAME STREQUAL "Account.cpp")
        set(ACCOUNT_SOURCE ${SOURCE})
    elseif(FILENAME STREQUAL "tests.cpp")
        set(TESTS_MAIN ${SOURCE})
    endif()
endforeach()

if(ACCOUNT_SOURCE AND TESTS_MAIN)
    add_executable(ex02_program ${ACCOUNT_SOURCE} ${TESTS_MAIN})
    
    set_target_properties(ex02_program PROPERTIES
        CXX_STANDARD 98
        CXX_STANDARD_REQUIRED ON
    )
    
    if(STANDALONE_BUILD)
        set_target_properties(ex02_program PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${EX02_DIR}
        )
        set(EX02_BINARY "${EX02_DIR}/ex02_program")
    else()
        set_target_properties(ex02_program PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${EX02_DIR}
        )
        set(EX02_BINARY "${EX02_DIR}/ex02_program")
    endif()
    
    add_custom_command(TARGET ex02_program POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ex02_program> ${EX02_DIR}/ex02_program
        COMMAND chmod +x ${EX02_DIR}/ex02_program
        COMMENT "Installing ex02_program to ${EX02_DIR}"
    )
    
    foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
        set_target_properties(ex02_program PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${EX02_DIR}
        )
    endforeach()
    
    get_filename_component(EX02_BINARY "${EX02_DIR}/ex02_program" ABSOLUTE)
else()
    message(WARNING "  [EX02] Could not find Account.cpp or tests.cpp")
    return()
endif()

add_executable(TESTER_EX02 ${TEST_SOURCES})

set_target_properties(TESTER_EX02 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set_target_properties(TESTER_EX02 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

get_filename_component(LOG_FILE_PATH 
    "${CMAKE_CURRENT_SOURCE_DIR}/19920104_091532.log" 
    ABSOLUTE
)

target_compile_definitions(TESTER_EX02 PRIVATE
    EX02_BINARY_PATH="${EX02_BINARY}"
    LOG_FILE_PATH="${LOG_FILE_PATH}"
)

target_link_libraries(TESTER_EX02
    gtest
    gtest_main
    pthread
)

add_test(NAME TESTER_EX02 COMMAND TESTER_EX02)
set_tests_properties(TESTER_EX02 PROPERTIES
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

message(STATUS "  [EX02] ✓ Configuration complete")