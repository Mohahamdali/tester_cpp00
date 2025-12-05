
#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <cstdio>
#include <regex>
#include <iomanip>

class UIXPrinterEx00 : public ::testing::EmptyTestEventListener {
    void OnTestProgramStart(const ::testing::UnitTest& unit_test) override {
        std::cout << "\n\033[1;36m========== TEST RUN START (ex00) ==========\033[0m\n";
        std::cout << "Suites: " << unit_test.total_test_suite_count()
                  << " | Tests: " << unit_test.total_test_count() << "\n\n";
    }

    void OnTestSuiteStart(const ::testing::TestSuite& suite) override {
        std::cout << "\033[34m📂 Suite: " << suite.name() << "\033[0m\n";
    }

    void OnTestStart(const ::testing::TestInfo& info) override {
        std::cout << "   • " << std::setw(40) << std::left << info.name();
    }

    void OnTestEnd(const ::testing::TestInfo& info) override {
        auto elapsed = info.result()->elapsed_time();
        if (info.result()->Passed()) {
            std::cout << " ... \033[32m✅ PASSED\033[0m "
                      << "\033[90m(" << elapsed << " ms)\033[0m\n";
        } else {
            std::cout << " ... \033[31m❌ FAILED\033[0m "
                      << "\033[90m(" << elapsed << " ms)\033[0m\n";
        }
    }

    void OnTestProgramEnd(const ::testing::UnitTest& unit_test) override {
        std::cout << "\n\033[1;36m========== TEST RUN END (ex00) ==========\033[0m\n";
        std::cout << "Total run: " << unit_test.test_to_run_count()
                  << " | \033[32mPassed: " << unit_test.successful_test_count() << "\033[0m"
                  << " | \033[31mFailed: " << unit_test.failed_test_count() << "\033[0m\n";
        std::cout << "==================================\n";
    }
};

std::string RUN_PROGRAME(const std::string &cmd);
std::string remove_ansi(const std::string &s);
std::string RUN_AND_CLEAN(const std::string &cmd);

#endif
