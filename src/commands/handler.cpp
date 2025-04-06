#include <iostream>
#include <sqlite3.h>
#include "../utils/utils.h"

using namespace std;

void cli() {
    clear();
    print(format("PERSA\n", "green", "", "bold") + "a simple CLI-based personal finance tracker\n");
    printfmt("https://github.com/theluqmn/persa", "blue", "", "underline");
    printfmt("Type 'help' for a list of available commands, or 'exit' to quit.", "", "", "dim");

    bool exit = false;
    string action;

    while (!exit) {
        cout << "> ";
        cin >> action;

        if (action == "exit") {
            print(format("Exiting... bai bai", "blue", "", ""));
            exit = true;
        } else {
            print(format("Unknown command: '" + action + "'", "red", "", "bold"));
        }
    }
}