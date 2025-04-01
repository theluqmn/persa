#include <iostream>

using namespace std;

void clear() {
    system("cls");
}

void initDatabase() {
    
}

int main() {
    clear();
    cout << "the start of something i guess" << endl;

    string* action = new string;
    bool exit = false;

    // main program loop
    while (!exit) {
        cout << "> ";
        cin >> *action;

        if (*action == "add") {

        }

        if (*action == "exit") {
            exit = true;
        }
    }

    // cleanup
    delete action;
    return 0;
}
