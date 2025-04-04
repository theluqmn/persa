#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <sqlite3.h>

using namespace std;

void addTransaction(sqlite3* db, string name, string date, float amount, string description);

#endif