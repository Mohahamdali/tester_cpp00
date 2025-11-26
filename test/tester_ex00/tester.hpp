
#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <cstdio>
#include <regex>

std::string RUN_PROGRAME(const std::string &cmd);
std::string remove_ansi(const std::string &s);
std::string RUN_AND_CLEAN(const std::string &cmd);

#endif
