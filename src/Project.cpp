/**
 * @file Project.cpp
 * @brief Campus E-Governance System — manages HOD, Teacher, and Student records.
 *
 * Data files (one record = 6 lines: id, password, fullName, department, mobile, salary/result):
 *   HODdata.txt, Teacherdata.txt, Studentdata.txt
 * Username registry (one entry = 2 lines: id, password):
 *   Username.txt
 * Audit and reporting files:
 *   History.txt, HODattendance.txt, Teacherattendance.txt, Studentattendance.txt, Feedback.txt
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

using namespace std;

// ============================================================
// Constants.
// ============================================================

const string ADMIN_USERNAME   = "Admin";
const string ADMIN_PASSWORD   = "pw";
const string FILE_HOD         = "HODdata.txt";
const string FILE_TEACHER     = "Teacherdata.txt";
const string FILE_STUDENT     = "Studentdata.txt";
const string FILE_USERNAME    = "Username.txt";
const string FILE_HISTORY     = "History.txt";
const string FILE_HOD_ATT     = "HODattendance.txt";
const string FILE_TEACHER_ATT = "Teacherattendance.txt";
const string FILE_STUDENT_ATT = "Studentattendance.txt";
const string FILE_FEEDBACK    = "Feedback.txt";

// ============================================================
// Data structures.
// ============================================================

/** Person fields shared by every role. */
struct Person {
    string id;
    string password;
    string fullName;
    string department;
    string mobile;
};

/** Student extends Person with an exam result field. */
struct Student : Person {
    string result;
};

/** Teacher extends Person with a salary field. */
struct Teacher : Person {
    string salary;
};

/** Hod extends Person with a salary field. */
struct Hod : Person {
    string salary;
};

// ============================================================
// Utility functions.
// ============================================================

/**
 * @brief Clear the screen and draw the application title banner.
 */
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

/**
 * @brief Get the current local date and time as a formatted string.
 * @return String in the format "HH:MM:SS  DD/MM/YYYY".
 */
string getCurrentTimestamp() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    char buf[32];
    sprintf(buf, "%02d:%02d:%02d  %02d/%02d/%04d",
            st.wHour, st.wMinute, st.wSecond,
            st.wDay, st.wMonth, st.wYear);
    return string(buf);
}

/**
 * @brief Append a login event to History.txt.
 * @param username The ID of the user who just logged in.
 */
void logHistory(const string& username) {
    ofstream f(FILE_HISTORY, ios::app);
    if (!f.is_open()) {
        cerr << "Cannot open " << FILE_HISTORY << " for writing." << endl;
        return;
    }
    f << username << "     Time is: " << getCurrentTimestamp() << endl;
}

/**
 * @brief Print every line of a file to stdout with tab indentation.
 * @param filename Path to the file to display.
 */
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

/**
 * @brief Check whether a user ID already exists in Username.txt.
 * @param id The candidate ID to look up.
 * @return true if the ID is already registered, false if it is available.
 */
bool isIdTaken(const string& id) {
    ifstream f(FILE_USERNAME);
    if (!f.is_open()) return false;
    string entry, pass;
    while (getline(f, entry) && getline(f, pass)) {
        if (entry == id) return true;
    }
    return false;
}

/**
 * @brief Prompt the user to type a department name and return it.
 * @return The department string entered by the user.
 */
string promptDepartment() {
    cout << "\t\t\tDepartment?: ";
    string dept;
    cin >> dept;
    return dept;
}

/**
 * @brief Flush the input buffer and block until the user presses Enter.
 */
void waitForEnter() {
    cout << "\t\t\tPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// ============================================================
// Profile display.
// ============================================================

/**
 * @brief Search a data file for a matching id/password and print that record.
 * @param dataFile Path to the data file (HODdata.txt, Teacherdata.txt, or Studentdata.txt).
 * @param id       The user ID to search for.
 * @param pass     The password to match alongside the ID.
 * @param label    Label for the last field, either "Salary" or "Result".
 * @return true if a matching record was found and printed, false otherwise.
 */
bool showProfile(const string& dataFile, const string& id,
                 const string& pass, const string& label) {
    ifstream f(dataFile);
    if (!f.is_open()) {
        cerr << "Cannot open " << dataFile << "." << endl;
        return false;
    }
    string fId, fPass, fName, fDept, fMobile, fExtra;
    while (getline(f, fId) && getline(f, fPass)) {
        getline(f, fName);
        getline(f, fDept);
        getline(f, fMobile);
        getline(f, fExtra);
        if (fId != id || fPass != pass) continue;
        printHeader();
        cout << "\n";
        cout << "\t\tYour Name is: "      << fName   << endl;
        cout << "\t\tYour Id NO is: "      << fId     << endl;
        cout << "\t\tYour Department is: " << fDept   << endl;
        cout << "\t\tYour Phone no is: "   << fMobile << endl;
        cout << "\t\tYour " << label << " is: " << fExtra << endl;
        return true;
    }
    return false;
}

// ============================================================
// Role-specific login helper.
// ============================================================

/**
 * @brief Search a data file for a matching id/password and extract name and department.
 * @param dataFile   Path to the data file to search.
 * @param id         User ID to look up.
 * @param pass       Password to match.
 * @param outName    Receives the full name of the matched record.
 * @param outDept    Receives the department of the matched record.
 * @return true if a matching record was found, false otherwise.
 */
bool tryLoginRole(const string& dataFile, const string& id, const string& pass,
                  string& outName, string& outDept) {
    ifstream f(dataFile);
    if (!f.is_open()) return false;
    string fId, fPass, fName, fDept, fMobile, fExtra;
    while (getline(f, fId) && getline(f, fPass)) {
        getline(f, fName);
        getline(f, fDept);
        getline(f, fMobile);
        getline(f, fExtra);
        if (fId != id || fPass != pass) continue;
        outName = fName;
        outDept = fDept;
        return true;
    }
    return false;
}

// ============================================================
// Record I/O.
// ============================================================

/**
 * @brief Prompt for HOD details and append a new record to HODdata.txt and Username.txt.
 */
void addHod() {
    printHeader();
    string fname, lname, id, birthDate, department, mobile, salary;
    cout << "\t\t\tEnter HOD's first Name: ";
    cin >> fname;
    cout << "\t\t\tEnter HOD's Last Name: ";
    cin >> lname;
    while (true) {
        cout << "\t\t\tEnter HOD's Id no: ";
        cin >> id;
        if (!isIdTaken(id)) break;
        cout << "\t\t\tId Number already exists. Enter Again." << endl;
    }
    cout << "\t\t\tEnter HOD's Birthday in the form of dd/mm/yyyy: ";
    cin >> birthDate;
    cout << "\t\t\tEnter Department of HOD: ";
    cin >> department;
    cout << "\t\t\tEnter the mobile number of HOD: ";
    cin >> mobile;
    cout << "\t\t\tEnter Salary of HOD: ";
    cin >> salary;
    ofstream fData(FILE_HOD, ios::app);
    if (!fData.is_open()) {
        cerr << "Cannot open " << FILE_HOD << " for writing." << endl;
        return;
    }
    ofstream fUser(FILE_USERNAME, ios::app);
    if (!fUser.is_open()) {
        cerr << "Cannot open " << FILE_USERNAME << " for writing." << endl;
        return;
    }
    fData << id                   << endl;
    fData << birthDate            << endl;
    fData << fname << " " << lname << endl;
    fData << department           << endl;
    fData << mobile               << endl;
    fData << salary               << endl;
    fUser << id                   << endl;
    fUser << birthDate            << endl;
    cout << "\t\t\tThe Password is: " << birthDate << endl;
}

/**
 * @brief Prompt for Teacher details and append a new record to Teacherdata.txt and Username.txt.
 */
void addTeacher() {
    printHeader();
    string fname, lname, id, birthDate, department, mobile, salary;
    cout << "\t\t\tEnter Teacher's first Name: ";
    cin >> fname;
    cout << "\t\t\tEnter Teacher's Last Name: ";
    cin >> lname;
    while (true) {
        cout << "\t\t\tEnter Teacher's Id no: ";
        cin >> id;
        if (!isIdTaken(id)) break;
        cout << "\t\t\tId Number already exists. Enter Again." << endl;
    }
    cout << "\t\t\tEnter Teacher's Birthday in the form of dd/mm/yyyy: ";
    cin >> birthDate;
    cout << "\t\t\tEnter Department of Teacher: ";
    cin >> department;
    cout << "\t\t\tEnter the mobile number of Teacher: ";
    cin >> mobile;
    cout << "\t\t\tEnter Salary of Teacher: ";
    cin >> salary;
    ofstream fData(FILE_TEACHER, ios::app);
    if (!fData.is_open()) {
        cerr << "Cannot open " << FILE_TEACHER << " for writing." << endl;
        return;
    }
    ofstream fUser(FILE_USERNAME, ios::app);
    if (!fUser.is_open()) {
        cerr << "Cannot open " << FILE_USERNAME << " for writing." << endl;
        return;
    }
    fData << id                   << endl;
    fData << birthDate            << endl;
    fData << fname << " " << lname << endl;
    fData << department           << endl;
    fData << mobile               << endl;
    fData << salary               << endl;
    fUser << id                   << endl;
    fUser << birthDate            << endl;
    cout << "\t\t\tThe Password is: " << birthDate << endl;
}

/**
 * @brief Prompt for Student details and append a new record to Studentdata.txt and Username.txt.
 */
void addStudent() {
    printHeader();
    string fname, lname, id, birthDate, department, mobile, result;
    cout << "\t\t\tEnter Student's first Name: ";
    cin >> fname;
    cout << "\t\t\tEnter Student's Last Name: ";
    cin >> lname;
    while (true) {
        cout << "\t\t\tEnter Student's Id no: ";
        cin >> id;
        if (!isIdTaken(id)) break;
        cout << "\t\t\tId Number already exists. Enter Again." << endl;
    }
    cout << "\t\t\tEnter Student's Birthday in the form of dd/mm/yyyy: ";
    cin >> birthDate;
    cout << "\t\t\tEnter Department of Student: ";
    cin >> department;
    cout << "\t\t\tEnter the mobile number of Student: ";
    cin >> mobile;
    cout << "\t\t\tEnter Result of Student: ";
    cin >> result;
    ofstream fData(FILE_STUDENT, ios::app);
    if (!fData.is_open()) {
        cerr << "Cannot open " << FILE_STUDENT << " for writing." << endl;
        return;
    }
    ofstream fUser(FILE_USERNAME, ios::app);
    if (!fUser.is_open()) {
        cerr << "Cannot open " << FILE_USERNAME << " for writing." << endl;
        return;
    }
    fData << id                   << endl;
    fData << birthDate            << endl;
    fData << fname << " " << lname << endl;
    fData << department           << endl;
    fData << mobile               << endl;
    fData << result               << endl;
    fUser << id                   << endl;
    fUser << birthDate            << endl;
    cout << "\t\t\tThe Password is: " << birthDate << endl;
}

/**
 * @brief Record attendance for every person in a given department.
 * @param dataFile   Path to the role data file to iterate (e.g. HODdata.txt).
 * @param attFile    Path to the attendance output file.
 * @param department Only records whose department matches this value are processed.
 */
void recordAttendance(const string& dataFile, const string& attFile,
                      const string& department) {
    ifstream fData(dataFile);
    if (!fData.is_open()) {
        cerr << "Cannot open " << dataFile << "." << endl;
        return;
    }
    ofstream fAtt(attFile, ios::app);
    if (!fAtt.is_open()) {
        cerr << "Cannot open " << attFile << " for writing." << endl;
        return;
    }
    SYSTEMTIME st;
    GetLocalTime(&st);
    char dateBuf[16];
    sprintf(dateBuf, "%02d/%02d/%04d", st.wDay, st.wMonth, st.wYear);
    cout << "\t\t\tUserName\tDepartment\tAttendance" << endl;
    string fId, fPass, fName, fDept, fMobile, fExtra;
    while (getline(fData, fId) && getline(fData, fPass)) {
        getline(fData, fName);
        getline(fData, fDept);
        getline(fData, fMobile);
        getline(fData, fExtra);
        if (fDept != department) continue;
        string status;
        do {
            cout << "\t\t\t" << fId << "\t\t" << department << "\t\t";
            cin >> status;
        } while (status != "P" && status != "NT" && status != "A");
        fAtt << fId << "\t\t" << department << "\tDate is: " << dateBuf << "\t" << status << endl;
    }
}

/**
 * @brief Let a student submit a feedback rating for each teacher in their department.
 * @param department The student's department; only teachers in this department are listed.
 */
void giveFeedback(const string& department) {
    ifstream fTeacher(FILE_TEACHER);
    if (!fTeacher.is_open()) {
        cerr << "Cannot open " << FILE_TEACHER << "." << endl;
        return;
    }
    ofstream fFeedback(FILE_FEEDBACK, ios::app);
    if (!fFeedback.is_open()) {
        cerr << "Cannot open " << FILE_FEEDBACK << " for writing." << endl;
        return;
    }
    cout << "\t\t\tName\t\tdepartment\t\tFeedback" << endl;
    string fId, fPass, fName, fDept, fMobile, fSalary;
    while (getline(fTeacher, fId) && getline(fTeacher, fPass)) {
        getline(fTeacher, fName);
        getline(fTeacher, fDept);
        getline(fTeacher, fMobile);
        getline(fTeacher, fSalary);
        if (fDept != department) continue;
        string choice;
        do {
            cout << "\t\t\t" << fName << "\t\t" << department << "\t\t";
            cin >> choice;
        } while (choice != "1" && choice != "2" && choice != "3" && choice != "4");
        string rating;
        if      (choice == "1") rating = "Excellent";
        else if (choice == "2") rating = "Good";
        else if (choice == "3") rating = "Bad";
        else                    rating = "Very Bad";
        fFeedback << fName << "\t\t" << department << "\t\t" << rating << endl;
    }
}

// ============================================================
// Menu loops.
// ============================================================

/**
 * @brief Run the Admin menu until the user chooses to log out.
 */
void runAdminMenu() {
    while (true) {
        printHeader();
        cout << "\t\t****Choose You Entry****" << endl;
        cout << "\t\t\t1->Add HOD Data" << endl;
        cout << "\t\t\t2->See the History" << endl;
        cout << "\t\t\t3->Add Attendance of HOD" << endl;
        cout << "\t\t\t4->See the Attendance of HOD" << endl;
        cout << "\t\t\t5->See the Attendance of Teacher" << endl;
        cout << "\t\t\t6->See Feedback of Teachers" << endl;
        cout << "\t\t\t7->Log Out" << endl;
        cout << "\t\t\tEnter your Entry Here: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int n;
            cout << "\t\t\tEnter How many HOD detail you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) addHod();
            waitForEnter();
        } else if (choice == 2) {
            printHeader();
            cout << "\t\t\tHistory" << endl;
            printFileContents(FILE_HISTORY);
            waitForEnter();
        } else if (choice == 3) {
            printHeader();
            recordAttendance(FILE_HOD, FILE_HOD_ATT, promptDepartment());
            waitForEnter();
        } else if (choice == 4) {
            printHeader();
            cout << "UserName\t\tAttendance" << endl;
            printFileContents(FILE_HOD_ATT);
            waitForEnter();
        } else if (choice == 5) {
            printHeader();
            cout << "UserName\t\tAttendance" << endl;
            printFileContents(FILE_TEACHER_ATT);
            waitForEnter();
        } else if (choice == 6) {
            printHeader();
            cout << "\t\t\tName\t\tDepartment\t\tFeedback" << endl;
            printFileContents(FILE_FEEDBACK);
            waitForEnter();
        } else if (choice == 7) {
            cout << "\t\t\tLogging Off" << endl;
            waitForEnter();
            return;
        } else {
            cout << "\t\t\tYou Enter Wrong Entry" << endl;
            cout << "\t\t\tEnter Again" << endl;
            waitForEnter();
        }
    }
}

/**
 * @brief Run the HOD menu until the user chooses to log out.
 * @param id         The logged-in HOD's user ID.
 * @param pass       The logged-in HOD's password.
 * @param department The logged-in HOD's department.
 */
void runHodMenu(const string& id, const string& pass, const string& department) {
    while (true) {
        printHeader();
        cout << "\t\t\tWelcome Hod" << endl;
        cout << "\t\t****Choose You Entry****" << endl;
        cout << "\t\t\t1->Add Teacher Data" << endl;
        cout << "\t\t\t2->See Your Attendance" << endl;
        cout << "\t\t\t3->Add Attendance of Teacher" << endl;
        cout << "\t\t\t4->See Your Data" << endl;
        cout << "\t\t\t5->Log out" << endl;
        cout << "\t\t\tEnter your Entry Here: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int n;
            cout << "\t\t\tEnter How many Teachers detail you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) addTeacher();
            waitForEnter();
        } else if (choice == 2) {
            printHeader();
            cout << "UserName\tDepartment\t\t\tAttendance" << endl;
            printFileContents(FILE_HOD_ATT);
            waitForEnter();
        } else if (choice == 3) {
            printHeader();
            recordAttendance(FILE_TEACHER, FILE_TEACHER_ATT, department);
            waitForEnter();
        } else if (choice == 4) {
            showProfile(FILE_HOD, id, pass, "Salary");
            waitForEnter();
        } else if (choice == 5) {
            cout << "\t\t\tLogging Out" << endl;
            waitForEnter();
            return;
        } else {
            cout << "\t\t\tYou Enter Wrong Entry" << endl;
            cout << "\t\t\tEnter Again" << endl;
            waitForEnter();
        }
    }
}

/**
 * @brief Run the Teacher menu until the user chooses to log out.
 * @param id         The logged-in Teacher's user ID.
 * @param pass       The logged-in Teacher's password.
 * @param department The logged-in Teacher's department.
 */
void runTeacherMenu(const string& id, const string& pass, const string& department) {
    while (true) {
        printHeader();
        cout << "\t\t\tWelcome Teacher" << endl;
        cout << "\t\t****Choose You Entry****" << endl;
        cout << "\t\t\t1->Add Student Data" << endl;
        cout << "\t\t\t2->See  your Attendance" << endl;
        cout << "\t\t\t3->Add Attendance of Student" << endl;
        cout << "\t\t\t4->See Your Data" << endl;
        cout << "\t\t\t5->See Student's Attendance" << endl;
        cout << "\t\t\t6->Log Out" << endl;
        cout << "\t\t\tEnter your Entry Here: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int n;
            cout << "\t\t\tEnter How many Student detail you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) addStudent();
            waitForEnter();
        } else if (choice == 2) {
            printHeader();
            cout << "UserName\tDepartment\t\tAttendance" << endl;
            printFileContents(FILE_TEACHER_ATT);
            waitForEnter();
        } else if (choice == 3) {
            printHeader();
            recordAttendance(FILE_STUDENT, FILE_STUDENT_ATT, department);
            waitForEnter();
        } else if (choice == 4) {
            showProfile(FILE_TEACHER, id, pass, "Salary");
            waitForEnter();
        } else if (choice == 5) {
            printHeader();
            cout << "\t\t\tUserName\tDepartment\t\tAttendance" << endl;
            printFileContents(FILE_STUDENT_ATT);
            waitForEnter();
        } else if (choice == 6) {
            cout << "\t\t\tLogging Out" << endl;
            waitForEnter();
            return;
        } else {
            cout << "\t\t\tYou Enter Wrong Entry" << endl;
            cout << "\t\t\tEnter Again" << endl;
            waitForEnter();
        }
    }
}

/**
 * @brief Run the Student menu until the user chooses to log out.
 * @param id         The logged-in Student's user ID.
 * @param pass       The logged-in Student's password.
 * @param department The logged-in Student's department.
 */
void runStudentMenu(const string& id, const string& pass, const string& department) {
    while (true) {
        printHeader();
        cout << "\t\t\tWelcome Student" << endl;
        cout << "\t\t****Choose You Entry****" << endl;
        cout << "\t\t\t1->See your Attendance" << endl;
        cout << "\t\t\t2->See Your Data" << endl;
        cout << "\t\t\t3->Give feedback to Your Teacher" << endl;
        cout << "\t\t\t4->Log Out" << endl;
        cout << "\t\t\tEnter your Entry Here: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            printHeader();
            cout << "\t\t\tUserName\tDepartment\t\t\tAttendance" << endl;
            printFileContents(FILE_STUDENT_ATT);
            waitForEnter();
        } else if (choice == 2) {
            showProfile(FILE_STUDENT, id, pass, "Result");
            waitForEnter();
        } else if (choice == 3) {
            printHeader();
            cout << "\t\t\t\t\tGive Feedback" << endl;
            cout << "\t\t\t1->Excellent 2->Good 3->Bad 4->Very Bad" << endl;
            giveFeedback(department);
            waitForEnter();
        } else if (choice == 4) {
            cout << "\t\t\tLogging Out" << endl;
            waitForEnter();
            return;
        } else {
            cout << "\t\t\tYou Enter Wrong Entry" << endl;
            cout << "\t\t\tEnter Again" << endl;
            waitForEnter();
        }
    }
}

// ============================================================
// Entry point.
// ============================================================

/**
 * @brief Application entry point — login loop that dispatches to role menus.
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
