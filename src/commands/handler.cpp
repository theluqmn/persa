#include <iostream>
#include <sqlite3.h>
#include "../utils/utils.h"
#include "commands.h"

using namespace std;

void cli() {
    clear();
    print(format("PERSA\n", "green", "", "bold") + "a simple CLI-based personal finance tracker\n\n");
    print_fmt("https://github.com/theluqmn/persa\n", "blue", "", "underline");
    print_fmt("Type 'help' for a list of available commands, or 'exit' to quit.\n", "", "", "dim");

    bool exit = false;
    string action;

    while (!exit) {
        cout << "> ";
        cin >> action;

        if (action == "exit") {
            print(format("Exiting... bai bai\n", "blue", "", ""));
            exit = true;
        } else if (action == "add") {
            prompt_add();
        } else {
            print(format("Unknown command: '" + action + "'\n", "red", "", "bold"));
        }
    }
}