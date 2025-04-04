#include <iostream>
#include <string>

using namespace std;

// text colors
const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string RESET = "\033[0m";

// background colors
const string BG_BLACK = "\033[40m";
const string BG_RED = "\033[41m";
const string BG_GREEN = "\033[42m";
const string BG_YELLOW = "\033[43m";
const string BG_BLUE = "\033[44m";
const string BG_MAGENTA = "\033[45m";
const string BG_CYAN = "\033[46m";
const string BG_WHITE = "\033[47m";

// text styles
const string BOLD = "\033[1m";
const string DIM = "\033[2m";
const string ITALIC = "\033[3m";
const string UNDERLINE = "\033[4m";
const string BLINK = "\033[5m";
const string REVERSE = "\033[7m";

// text functions
void clear() { system("clear"); }
void error(string message) { cout << RED << BOLD    << "ERROR:      " << RESET << message << RESET << endl; }
void warn(string message) { cout << YELLOW << BOLD  << "WARNING:    " << RESET << message << RESET << endl; }
void info(string message) { cout << BLUE << BOLD    << "INFO:       " << RESET << message << RESET << endl; }

// custom formatted output functions
void format(string message, string color = "", string background = "", string style = "") {
    cout << color << background << style << message << RESET << endl;
}

// testing use only
int main() {
    clear();
    error("This is an error message.");
    warn("This is a warning message.");
    info("This is an info message.");
    format("This is a formatted message.", BLACK, BG_WHITE);
    return 0;
}
