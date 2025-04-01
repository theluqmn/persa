#include <iostream>
#include <string>
#include <sqlite3.h>

using namespace std;

void clear() {
    system("clear");
}

sqlite3* initDatabase() {
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

        if (action == "add") {
            string date;
            float amount;
            string description;
            
            clear();
            cout << "ADD A NEW TRANSACTION\n" << endl;
            cout << "Amount:            "; cin >> amount;
            cout << "Date (DD/MM/YYYY): "; cin >> date;
            cout << "Description:       "; cin >> description;

            string addTrans = "INSERT INTO transactions (date, amount, description) VALUES ('" + date + "', " + to_string(amount) + ", '" + description + "')";
            char *errMsg = nullptr;
            int rc = sqlite3_exec(db, addTrans.c_str(), nullptr, nullptr, &errMsg);
            if (rc != SQLITE_OK) {
                cout << "Error adding transaction: " << errMsg << endl;
                sqlite3_free(errMsg);
            } else {
                cout << "Transaction added" << endl;
            }
        }

        if (action == "exit") {
            exit = true;
        }

        clear();
        cout << "Persa\n" << endl;
    }

    return 0;
}
