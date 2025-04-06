#include <iostream>
#include <sqlite3.h>
#include "../utils/utils.h"

using namespace std;

void cli() {
    clear();
    print(format("Persa", "red", "", "underline") + " - a simple CLI-based personal finance tracker");

    bool exit = false;
    string action;

    while (!exit) {
        cout << "> ";
        cin >> action;

        if (action == "exit") { exit = true; }
        else if (action == "add") {}

        clear();
        cout << "Persa\n" << endl;
    }
}