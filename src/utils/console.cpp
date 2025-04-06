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

// custom formatted output functions
string format(string message, string color, string background, string style) {
    if (color == "black") color = BLACK;
    else if (color == "red") color = RED;
    else if (color == "green") color = GREEN;
    else if (color == "yellow") color = YELLOW;
    else if (color == "blue") color = BLUE;
    else if (color == "magenta") color = MAGENTA;
    else if (color == "cyan") color = CYAN;
    else if (color == "white") color = WHITE;

    if (background == "black") background = BG_BLACK;
    else if (background == "red") background = BG_RED;
    else if (background == "green") background = BG_GREEN;
    else if (background == "yellow") background = BG_YELLOW;
    else if (background == "blue") background = BG_BLUE;
    else if (background == "magenta") background = BG_MAGENTA;
    else if (background == "cyan") background = BG_CYAN;
    else if (background == "white") background = BG_WHITE;

    if (style == "bold") style = BOLD;
    else if (style == "dim") style = DIM;
    else if (style == "italic") style = ITALIC;
    else if (style == "underline") style = UNDERLINE;
    else if (style == "blink") style = BLINK;
    else if (style == "reverse") style = REVERSE;
    
    return color + background + style + message + RESET;
}

// text functions
void clear() { system("clear"); }
void error(string message) { cout << RED << BOLD    << "ERROR:      " << RESET << message << RESET << endl; }
void warn(string message) { cout << YELLOW << BOLD  << "WARNING:    " << RESET << message << RESET << endl; }
void info(string message) { cout << BLUE << BOLD    << "INFO:       " << RESET << message << RESET << endl; }
void print(string message) { cout << message << endl; }
void printfmt(string message, string color, string background, string style) {
    cout << format(message, color, background, style) << endl;
}