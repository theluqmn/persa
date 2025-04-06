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
void printfmt(string message, string color, string background, string style);
string format(string message, string color = "", string background = "", string style = "");

sqlite3* initDatabase(const char* database);

#endif