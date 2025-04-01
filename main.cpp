#include <iostream>

using namespace std;

int main() {
    cout << "the start of something i guess" << endl;

    string* name = new string;

    cout << "what is your name?" << endl;
    cin >> *name;
    cout << "hello " << *name << endl;
    delete name;

    return 0;
}