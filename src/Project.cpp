/**
 * @file Project.cpp
 * @brief Application entry point for the Campus E-Governance System.
 */

#include "constants.h"
#include "utils.h"
#include "records.h"
#include "menus.h"
#include <iostream>

using namespace std;

/**
 * @brief Login loop that authenticates the user and dispatches to the correct role menu.
 * @return 0 on clean exit.
 */
int main() {
    while (true) {
        printHeader();
        string username, password;
        cout << "\t\t\tUser Name: ";
        cin >> username;
        cout << "\t\t\tPassword: ";
        cin >> password;
        if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
            logHistory(username);
            runAdminMenu();
            continue;
        }
        string name, department;
        if (tryLoginRole(FILE_HOD, username, password, name, department)) {
            printHeader();
            cout << "\t\t\tWelcome: " << name << endl;
            cout << "\t\t\tHOD of Department: " << department << endl;
            waitForEnter();
            logHistory(username);
            runHodMenu(username, password, department);
            continue;
        }
        if (tryLoginRole(FILE_TEACHER, username, password, name, department)) {
            printHeader();
            cout << "\t\t\tWelcome: " << name << endl;
            cout << "\t\t\tTeacher of Department: " << department << endl;
            waitForEnter();
            logHistory(username);
            runTeacherMenu(username, password, department);
            continue;
        }
        if (tryLoginRole(FILE_STUDENT, username, password, name, department)) {
            printHeader();
            cout << "\t\t\tWelcome: " << name << endl;
            cout << "\t\t\tStudent of Department: " << department << endl;
            waitForEnter();
            logHistory(username);
            runStudentMenu(username, password, department);
            continue;
        }
        while (true) {
            printHeader();
            cout << "Error: wrong ID or password. Press 1 to try again or 0 to exit: ";
            int opt;
            cin >> opt;
            if (opt == 1) break;
            if (opt == 0) return 0;
            cout << "\t\t\tYou Enter Wrong" << endl;
        }
    }
}
