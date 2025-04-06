#include <iostream>
#include <string>
#include <sqlite3.h>
#include "utils/utils.h"

using namespace std;

int main() {
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
