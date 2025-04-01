#include <iostream>

using namespace std;

int main() {
    cout << "the start of something i guess" << endl;

    string* action = new string;
    bool exit = false;

    // main program loop
    while (!exit) {
        cout << "> ";
        cin >> *action;

        if (*action == "exit") {
            exit = true;
        }
    }

    // cleanup
    delete action;
    return 0;
}