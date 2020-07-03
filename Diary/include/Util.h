#if !defined(UTIL_H)
#define UTIL_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

std::string format_current_date(const std::string &format);

std::string get_current_date();

std::string get_current_time();

#endif