#include <iostream>
#include <sqlite3.h>
#include "../utils/utils.h"

using namespace std;

// add the transaction to the database
int execute(bool inflow, string note, string date, float amount) {
    if (!inflow) {
        amount = -amount;
    }

    sqlite3 *db = init_main_db();
    string sql = "INSERT INTO transactions (amount, date, note) VALUES (" + to_string(amount) + ", '" + date + "', '" + note + "');";
    int res = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    if (res != SQLITE_OK) {
        error("Error executing SQL statement: " + string(sqlite3_errmsg(db)));
        return 0;
    }

    sqlite3_close(db);
    return 1;
}

// prompt the user for the transaction details
void prompt_add() {
    bool inflow = true;
    string date, note;
    float amount;

    print_fmt("Enter the transaction details:\n\n", "blue", "", "bold");
    print_fmt("Enter 1 for inflow, 0 for outflow: ", "", "", "bold");
    cin >> inflow;
    print_fmt("Date " + format("(dd/mm/yyyy)", "", "", "dim") + ": ", "", "", "bold");
    cin >> date;
    print_fmt("Amount: ", "", "", "bold");
    cin >> amount;
    print_fmt("Note " + format("(optional)", "", "", "dim") + ": ", "", "", "bold");
    cin >> note;

    int status = execute(inflow, note, date, amount);
    if (!status) {
        print_fmt("\nError adding transaction!\n", "red", "", "bold");
        return;
    }

    print_fmt("\nTransaction added successfully!\n", "green", "", "bold");
}