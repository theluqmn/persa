// utility functions
#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

void clear();
void error(string message);
void warn(string message);
void info(string message);
void format(string message, string color = "", string background = "", string style = "");

#endif UTILS_H