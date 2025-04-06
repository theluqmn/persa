// utility functions
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <sqlite3.h>
using namespace std;

void clear();
void error(string message);
void warn(string message);
void info(string message);
void print(string message);
void print_fmt(string message, string color, string background, string style);
string format(string message, string color = "", string background = "", string style = "");

sqlite3* init_main_db();

#endif