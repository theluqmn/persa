#include <iostream>
#include "../utils/utils.h"

using namespace std;

void cli() {
    clear();
    bool exit = false;
    string action;

    while (!exit) {
        cout << "> ";
        cin >> action;

        if (action == "exit") { exit = true; }

        clear();
        cout << "Persa\n" << endl;
    }
}