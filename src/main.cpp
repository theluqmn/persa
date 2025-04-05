#include <iostream>
#include <string>
#include <sqlite3.h>
#include "utils/utils.h"

using namespace std;

sqlite3* initDatabase() {
    sqlite3* db;
    char *errMsg = nullptr;
    
    int rc = sqlite3_open("./finances.db", &db);
    if (rc) {
        error("Error opening database: " + string(sqlite3_errmsg(db)));
        sqlite3_close(db);
        exit(1);
    }

    string transactionTable = "CREATE TABLE IF NOT EXISTS transactions (id INTEGER PRIMARY KEY, date TEXT, amount FLOAT, description TEXT)";
    rc = sqlite3_exec(db, transactionTable.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        error("Error creating transactions table in database: " + string(errMsg));
        sqlite3_free(errMsg);
        sqlite3_close(db);
        exit(1);
    }

    return db;
}

int main() {
    sqlite3* db = initDatabase();

    clear();
    cout << "Welcome to Persa\n" << endl;
    cout << "'help' for a list of commands, 'exit' to quit." << endl;

    string action;
    bool exit = false;

    // main program loop
    while (!exit) {
        cout << "> ";
        cin >> action;

        if (action == "exit") { exit = true; }

        clear();
        cout << "Persa\n" << endl;
    }

    return 0;
}
