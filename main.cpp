#include <iostream>
#include <sqlite3.h>

using namespace std;

void clear() {
    system("clear");
}

void initDatabase() {
    sqlite3* db;
    char *errMsg = nullptr;
    
    int rc = sqlite3_open("./finances.db", &db);
    if (rc) {
        cout << "Error opening database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        exit(1);
    }

    string transactionTable = "CREATE TABLE IF NOT EXISTS transactions (id INTEGER PRIMARY KEY, date TEXT, amount FLOAT, description TEXT)";
    rc = sqlite3_exec(db, transactionTable.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Error creating table: " << errMsg << endl;
        sqlite3_free(errMsg);
        sqlite3_close(db);
        exit(1);
    }

    sqlite3_close(db);
}

int main() {
    clear();
    cout << "the start of something i guess" << endl;

    initDatabase();

    string action;
    bool exit = false;

    // main program loop
    while (!exit) {
        cout << "> ";
        cin >> action;

        if (action == "add") {

        }

        if (action == "exit") {
            exit = true;
        }
    }

    return 0;
}
