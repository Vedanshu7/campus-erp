#include "utils.h"
#include "constants.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

using namespace std;

void printHeader() {
    system("cls");
    cout << endl;
    cout << " \xC9";
    for (int i = 0; i < 100; i++) cout << "\xCD";
    cout << "\xBB" << endl;
    cout << " \xBA";
    cout << "                                       E governance System                                          ";
    cout << "\xBA" << endl;
    cout << " \xC8";
    for (int i = 0; i < 100; i++) cout << "\xCD";
    cout << "\xBC" << endl << endl;
}

string getCurrentTimestamp() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    char buf[32];
    sprintf(buf, "%02d:%02d:%02d  %02d/%02d/%04d",
            st.wHour, st.wMinute, st.wSecond,
            st.wDay, st.wMonth, st.wYear);
    return string(buf);
}

void logHistory(const string& username) {
    ofstream f(FILE_HISTORY, ios::app);
    if (!f.is_open()) {
        cerr << "Cannot open " << FILE_HISTORY << " for writing." << endl;
        return;
    }
    f << username << "     Time is: " << getCurrentTimestamp() << endl;
}

void printFileContents(const string& filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cerr << "Cannot open " << filename << "." << endl;
        return;
    }
    string line;
    while (getline(f, line)) {
        cout << "\t\t\t" << line << endl;
    }
}

bool isIdTaken(const string& id) {
    ifstream f(FILE_USERNAME);
    if (!f.is_open()) return false;
    string entry, pass;
    while (getline(f, entry) && getline(f, pass)) {
        if (entry == id) return true;
    }
    return false;
}

string promptDepartment() {
    cout << "\t\t\tDepartment?: ";
    string dept;
    cin >> dept;
    return dept;
}

void waitForEnter() {
    cout << "\t\t\tPress Enter to continue...";
    cin.ignore();
    cin.get();
}
