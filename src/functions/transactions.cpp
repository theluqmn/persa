#include <iostream>
#include <sqlite3.h>

using namespace std;

void addTransaction(sqlite3* db, string name, string date, float amount, string description) {
    string insert = "INSERT INTO transactions (name, date, amount, description) VALUES ('" + name + "', '" + date + "', " + to_string(amount) + ", '" + description + "')";
    char *errMsg = nullptr;

    int rc = sqlite3_exec(db, insert.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cout << "Error adding transaction: " << errMsg << endl;
        sqlite3_free(errMsg);
    } else {
        cout << "Transaction added successfully." << endl;
    }
}
