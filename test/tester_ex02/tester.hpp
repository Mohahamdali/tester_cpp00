#ifndef TESTER_HPP
#define TESTER_HPP


#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <gtest/gtest.h>
#include <cstdio>
#include <regex>
#include <algorithm>
#include <iomanip>
#include <fstream>

#ifndef LOG_FILE_PATH
#define LOG_FILE_PATH "dummy_path_for_ide"
#endif
class UIXPrinterEx02 : public ::testing::EmptyTestEventListener {
public:
    void OnTestProgramStart(const ::testing::UnitTest& unit_test) override {
        printSeparator('=');
        std::cout << "\033[1;36mTEST EXECUTION STARTED (ex02)\033[0m\n";
        printSeparator('-');
        std::cout << std::left << std::setw(20) << "Test Suites:" 
                  << unit_test.total_test_suite_count() << "\n";
        std::cout << std::left << std::setw(20) << "Total Tests:" 
                  << unit_test.total_test_count() << "\n";
        printSeparator('=');
        std::cout << "\n";
    }

    void OnTestSuiteStart(const ::testing::TestSuite& suite) override {
        std::cout << "\033[1;34m┌─ Test Suite: " << suite.name() << "\033[0m\n";
    }

    void OnTestStart(const ::testing::TestInfo& info) override {
        std::cout << "\033[34m│\033[0m  " << std::setw(50) << std::left 
                  << info.name() << std::flush;
    }

    void OnTestEnd(const ::testing::TestInfo& info) override {
        const auto* result = info.result();
        const auto elapsed = result->elapsed_time();
        
        if (result->Passed()) {
            std::cout << "\033[32m✓ PASS\033[0m  "
                      << "\033[90m[" << std::setw(5) << std::right 
                      << elapsed << " ms]\033[0m\n";
        } else {
            std::cout << "\033[31m✗ FAIL\033[0m  "
                      << "\033[90m[" << std::setw(5) << std::right 
                      << elapsed << " ms]\033[0m\n";
            
            for (int i = 0; i < result->total_part_count(); ++i) {
                const auto& part = result->GetTestPartResult(i);
                if (part.failed()) {
                    std::cout << "\033[34m│\033[0m    \033[31m→ " 
                              << part.file_name() << ":" << part.line_number() 
                              << "\033[0m\n";
                    std::cout << "\033[34m│\033[0m      " 
                              << part.summary() << "\n";
                }
            }
        }
    }

    void OnTestSuiteEnd(const ::testing::TestSuite& suite) override {
        std::cout << "\033[34m└─\033[0m \033[90mCompleted " << suite.name() 
                  << " (" << suite.successful_test_count() << "/" 
                  << suite.total_test_count() << " passed)\033[0m\n\n";
    }

    void OnTestProgramEnd(const ::testing::UnitTest& unit_test) override {
        std::cout << "\n";
        printSeparator('=');
        std::cout << "\033[1;36mTEST EXECUTION COMPLETED (ex02)\033[0m\n";
        printSeparator('-');
        
        const int total = unit_test.test_to_run_count();
        const int passed = unit_test.successful_test_count();
        const int failed = unit_test.failed_test_count();
        const double pass_rate = total > 0 ? (100.0 * passed / total) : 0.0;
        
        std::cout << std::left << std::setw(20) << "Total Tests:" << total << "\n";
        std::cout << std::left << std::setw(20) << "Passed:" 
                  << "\033[32m" << passed << "\033[0m\n";
        std::cout << std::left << std::setw(20) << "Failed:" 
                  << "\033[31m" << failed << "\033[0m\n";
        std::cout << std::left << std::setw(20) << "Pass Rate:" 
                  << std::fixed << std::setprecision(1) << pass_rate << "%\n";
        
        printSeparator('=');
        
        if (failed == 0) {
            std::cout << "\033[1;32m✓ All tests passed successfully!\033[0m\n";
        } else {
            std::cout << "\033[1;31m✗ Some tests failed. Please review.\033[0m\n";
        }
        std::cout << "\n";
    }

private:
    void printSeparator(char ch, int width = 70) const {
        std::cout << std::string(width, ch) << "\n";
    }
};

std::string RUN_PROGRAME(const std::string &cmd);
std::string  file_log ();
void clean_date (std::string &output_date);
#endif