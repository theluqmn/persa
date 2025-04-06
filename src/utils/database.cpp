#include <iostream>
#include <sqlite3.h>
#include "utils.h"

using namespace std;

sqlite3* init_main_db() {
    sqlite3* db;
    int rc = sqlite3_open("main.db", &db);
    if (rc) {
        error("opening database: " + string(sqlite3_errmsg(db)));
        return NULL;
    }

    string transactions = "CREATE TABLE IF NOT EXISTS transactions (id INTEGER PRIMARY KEY, amount FLOAT, date TEXT, note TEXT)";
    rc = sqlite3_exec(db, transactions.c_str(), NULL, NULL, NULL);
    if (rc) {
        error("creating transactions table: " + string(sqlite3_errmsg(db)));
        return NULL;
    }

    // // create tables
    // if (database == "statistics.db") {
    //     string events = "CREATE TABLE IF NOT EXISTS events (id INTEGER PRIMARY KEY, type TEXT, time INTEGER, event TEXT)";
    //     rc = sqlite3_exec(db, events.c_str(), NULL, NULL, NULL);
    //     if (rc) {
    //         error("creating events table: " + string(sqlite3_errmsg(db)));
    //         return NULL;
    //     }

    // } else if (database == "main.db") {
    //     string transactions = "CREATE TABLE IF NOT EXISTS transactions (id INTEGER PRIMARY KEY, amount FLOAT, date TEXT, note TEXT)";
    //     rc = sqlite3_exec(db, transactions.c_str(), NULL, NULL, NULL);
    //     if (rc) {
    //         error("creating transactions table: " + string(sqlite3_errmsg(db)));
    //         return NULL;
    //     }
    // }

    return db;
}