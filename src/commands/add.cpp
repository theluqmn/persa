#include <iostream>
#include <sqlite3.h>
#include "../utils/utils.h"

using namespace std;

// add the transaction to the database
void execute(string note, string date, float amount) {}

// prompt the user for the transaction details
void promptAdd() {
    string date, note;
    bool inflow = true;
    float amount;

    printfmt("Enter the transaction details:\n", "blue", "", "bold");
    printfmt("Enter 1 for inflow, 0 for outflow: ", "", "", "bold");
    cin >> inflow;
    printfmt("Date " + format("(dd/mm/yyyy)", "", "", "dim") + ": ", "", "", "bold");
    cin >> date;
    printfmt("Amount: ", "", "", "bold");
    cin >> amount;
    printfmt("Note " + format("(optional)", "", "", "dim") + ": ", "", "", "bold");
    cin >> note;
    printfmt("\nTransaction added successfully!", "green", "", "bold");
}